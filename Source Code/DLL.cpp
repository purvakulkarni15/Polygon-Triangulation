#include "DLL.h"

Node* CreateNode(glm::vec2 data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = newNode;
	newNode->prev = newNode;

	return newNode;
}

DLL::~DLL()
{

}

DLL::DLL(glm::vec2 vertices[], int size, int formType)
{
	root = CreateNode(vertices[0]);

	Node* trav = root;

	for (int i = 1; i < size; i++)
	{
		trav->next = CreateNode(vertices[i]);
		trav->next->prev = trav;

		trav = trav->next;

		//Insert(vertices[i]);
	}

	if (formType == CYCLIC)
	{
		trav->next = root;
		root->prev = trav;
	}

	this->size = size;
}

void DLL::Insert(glm::vec2 vertex)
{
	if (root == NULL)
	{
		size = 1;
		root = CreateNode(vertex);
		return;
	}

	Node* last = root->prev;

	Node* newNode = CreateNode(vertex);
	newNode->next = root;
	root->prev = newNode;

	newNode->prev = last;
	last->next = newNode;

	size++;
}

DLL::DLL()
{
	root = NULL;
	size = 0;
}

void DLL::Delete(Node* ptr)
{
	if (ptr != NULL)
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;

		if (ptr == root)
			root = ptr->next;

		free(ptr);
		size--;
	}
}
