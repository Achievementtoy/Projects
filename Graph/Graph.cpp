
/********************************************************************************************
**	Project: Weighted Graph
**  Programmer: Garrett Cook
**  Course:		cs2420
**	Section:	601
**	Assignment: 10
**	Data:		December 2, 2019
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/




#include "Graph.h"
#include <iostream>

using namespace std;
// constructor
Graph::Graph()
{
	nverticies = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			matrix[i][j] = INT_MAX;
		}
	}
}

Graph::~Graph()
{
	
}
//adds an edge to the graph
void Graph::AddEdge(std::string source, std::string target, int weight)
{
	int Indexsource = GetIndex(source);
	int Targetsource = GetIndex(target);

	if (Indexsource == -1 or Targetsource == -1)
		return;

	matrix[Indexsource][Targetsource] = weight;

}
//adds a vertex
void Graph::AddVertex(std::string label)
{
	if (nverticies >= MAX_VERTECIES)
		return;

	verticies[nverticies++] = label;

}
// should return the index
int Graph::GetIndex(std::string label) const
{
	for (int i = 0; i < nverticies; i++)
	{
		if (verticies[i] == label)
			return i;
	}
	return -1;
}
// finds the edge
bool Graph::IsEdge(int sourceIndex, int targetIndex) const
{
	return (GetWeight(sourceIndex, targetIndex) < INT_MAX) ? true : false;
}

int Graph::GetWeight(int sourceIndex, int targetIndex) const
{
	return matrix[sourceIndex][targetIndex];
}
// used help from the depth first to find the solution to this one
void Graph::BreadthFirstSearch(std::string startingVertex) const
{
	int visited[MAX_VERTECIES];

	cout << "starting BFS with vertex " << startingVertex << endl;

	for (int i = 0; i < nverticies; i++)
	{
		visited[i] = -1;
	}

	BreadthFirstSearch(startingVertex, visited);

		for (int i = 0; i < nverticies; i++)
		{
			if (visited[i] != -1)
				cout << " \tvisited " << verticies[visited[i]] << endl;
		}
		cout << endl;
}
 // this one as well
// also looked on geeks for geeks and found that sets for me were easier to understand
void Graph::BreadthFirstSearch(std::string startingVertex, int visited[]) const
{
	int index = GetIndex(startingVertex);
	queue<int> vertex;
	set<int> found;
	int ivisited = 0;



	vertex.push(index);
	while (!vertex.empty()) {
		index = vertex.front();
		vertex.pop();

		if (found.find(index) == found.end())
		{

			visited[ivisited++] = index;

			found.insert(index);

			for (int i = 0; i < nverticies; i++)
			{
				if (IsEdge(index, i) && found.find(i) == found.end())
					vertex.push(i);

			}

		}

	}

}
// calls the other function, these two were difficult so I found some help online as well as from some from friends
void Graph::DijkstraShortestPath(std::string startingVertex) const
{
	int distance[MAX_VERTECIES];
	int prev[MAX_VERTECIES];
	//goes into the algorithm to solve shortest path
	DijkstraShortestPath(startingVertex, distance, prev);

	cout << "Shortest Distance starting from vertex " << startingVertex << endl;

	for (int i = 0; i < nverticies; i++)
	{
		cout << "\tto: " << verticies[i] << '\t';
		// I made dumb mistakes on this one with all the printing
		if (distance[i] < INT_MAX) {
			cout << distance[i] << "\tPath: ";
			Path(prev, i);
		}
		else
			cout << "no path";
		cout << endl;

	}
	cout << endl;

}
//this function finds the shortest path
void Graph::DijkstraShortestPath(std::string startingVertex, int distance[], int prevVertex[]) const
{
	bool current[MAX_VERTECIES];

	for (int i = 0; i < nverticies; i++)
	{
		distance[i] = INT_MAX;
		current[i] = false;
		//Dana said use -1 instead of anything else
		prevVertex[i] = -1;
	}
	//find the index 
	int starting = GetIndex(startingVertex);

	distance[starting] = 0;

	for (int i = 0; i < nverticies - 1; i++)
	{
		//remember to make new function for this variable to reduce difficulty
		int next = Min(distance, current);

		current[next] = true;

		// finish code here with updating distance once I am back from vacation

		for (int i = 0; i < nverticies; i++)

			if (!current[i] and IsEdge(next, i) and distance[next] != INT_MAX and distance[next] + matrix[next][i] < distance[i]) {
				prevVertex[i] = next;
				distance[i] = distance[next] + matrix[next][i];
			}
	}



}
// separte function to take care of the minimum 
int Graph::Min(int distance[], bool current[]) const
{
	int minimum = INT_MAX, minimum_index;
	for (int i = 0; i < nverticies; i++)
	{
		if (current[i] == false and distance[i] <= minimum)
			minimum = distance[i], minimum_index = i;
		
	}
	return minimum_index;
}
// got help with this one in class from Dana
void Graph::PrintGraph() const
{
	cout << "numVerticies: " << nverticies << endl;

	for (int i = 0; i < nverticies; i++)
	{
		cout << "\t" << verticies[i];
	}
	cout << endl;
	for (int i = 0; i < nverticies; i++)
	{
		cout << verticies[i];


		for (int k = 0; k < nverticies; k++)
		{
			cout << "\t";
			if (matrix[i][k] != INT_MAX)
				cout << matrix[i][k];
		}
		cout << endl;
	}
}

//takes care of the path printing for the program
void Graph::Path(int prev[], int index) const
{
	int index1 = index;
	cout << verticies[index1];

	while (prev[index1] != -1) {
		index1 = prev[index1];
		cout << ", " << verticies[index1];
	}


}