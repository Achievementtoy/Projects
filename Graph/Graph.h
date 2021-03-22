#pragma once
#include <string>
#include <iostream>
#include <queue>
#include <set>
#include <cassert>
#include <climits>


class Graph
{
public:
	Graph();
	~Graph();
	void AddEdge(std::string source, std::string target, int weight);
	void AddVertex(std::string label);
	int GetIndex(std::string label) const; // -1 if label is not found
	bool IsEdge(int sourceIndex, int targetIndex) const;
	int GetWeight(int sourceIndex, int targetIndex) const;
	void BreadthFirstSearch(std::string startingVertex) const;
	void BreadthFirstSearch(std::string startingVertex, int visited[]) const;
	void DijkstraShortestPath(std::string startingVertex) const;
	void DijkstraShortestPath(std::string startingVertex, int distance[], int prevVertex[]) const;
	void PrintGraph() const;
	void Path(int prev[], int index) const;
	int Min(int distance[], bool current[]) const;
	static const int MAX_VERTECIES = 10;


private:

	
	int matrix[MAX_VERTECIES][MAX_VERTECIES];
	std::string verticies[MAX_VERTECIES];
	int nverticies;




};

