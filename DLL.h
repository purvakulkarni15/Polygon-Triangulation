#include "windows.h"
#include<iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define CYCLIC 01

struct Node
{
	Node* next, *prev;
	glm::vec2 data;
};

class DLL
{
	public:

	Node *root = NULL;
	int size = 0;

	DLL();
	~DLL();

	DLL(glm::vec2 vertices[], int size, int formType);

	void Insert(glm::vec2 vertex);
	void Delete(Node* ptr);

};