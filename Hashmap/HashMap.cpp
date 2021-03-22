// File/Project Prolog
// Name: Garrett Cook
// CS 2420 Section 003
// Project: HashMap
// Date: 10/10/2019
//
// I declare that the following code was written by me or provided 
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
// 
// I also state that the Standard Template Library is NOT used in this project
// ---------------------------------------------------------------------------




#include "HashMap.h"
#include "Node.h"
#include <iostream>
#include <sstream>
using namespace std;


int HashMap::GenerateHash(string key) const
{
	int hashValue = 41;
	for (size_t i = 0; i < key.length(); i++)
	{
		hashValue += (hashValue * 101) + key[i];
	}
	return abs(hashValue) % sizeOfArray;
}

HashMap::HashMap(int size)
{
	hashArray = new Node * [size];
	for (int i = 0; i < size; i++)
	{
		hashArray[i] = nullptr;
	}
	sizeOfArray = size;
}
//destroys everything properly
HashMap::~HashMap()
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		Node* temp = hashArray[i];
		while (temp != nullptr) {
			Node* temp1 = temp;
			temp = temp->next;
			delete temp1;
		}
	}
	delete[]hashArray;


}
// Checks the key to make sure it is in there
bool HashMap::IsKeyPresent(string const& key) const
{
	int index = GenerateHash(key);
	Node* temp = hashArray[index];
	while (temp != nullptr) {
		if (temp->key == key) 
			return true;

			
		temp = temp->next;
	}
	return false;
		
}
// If no key was here, makes a new key
void HashMap::SetKeyValue(string const& key, int value)
{
	int index = GenerateHash(key);
	Node* temp = hashArray[index];

	if (temp == nullptr) {
		hashArray[index] = new Node(key, value, nullptr);
			return;
	}
	while (temp != nullptr) {
		if (temp->key == key) {
			temp->value = value;
			return;
		}
		if (temp->next == nullptr) {

			temp->next = new Node(key, value, nullptr);
			return;


		}
		temp = temp->next;
	}
}
// Gets the key value
bool HashMap::GetKeyValue(string const& key, int& value)
{
	int index = GenerateHash(key);
	Node* temp = hashArray[index];
	while (temp != nullptr) {
		if (temp->key == key)
		{
			value = temp->value;
			return true;
		}
		temp = temp->next;
	}
	return false;
}
// This and begin Dana helped me with, had it backwards originally
Iterator HashMap::begin()
{
	int start = 0;
	while ((hashArray[start] == nullptr) and (start < sizeOfArray))
		start++;
	return Iterator(start, hashArray, sizeOfArray);

}

Iterator HashMap::end()
{
	return Iterator();
}
