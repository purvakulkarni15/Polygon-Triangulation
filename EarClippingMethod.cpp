#include "EarClippingMethod.h"

#define PI 3.14159265359

EarClippingMethod::~EarClippingMethod()
{

}

EarClippingMethod::EarClippingMethod(glm::vec2 vertices[], int size)
{
	verticesDLL = new DLL(vertices, size, CYCLIC);
}

EarClippingMethod::EarClippingMethod()
{
	verticesDLL = new DLL();
}

bool EarClippingMethod::IsEarTip(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3)
{
	if (IsReflex(v1, v2, v3))
	{
		return false;
	}
	
	Node* trav = verticesDLL->root;

	do
	{
		if (trav->data != v1 && trav->data != v2 && trav->data != v3)
		{
			if (IsPointInsideTriangle(v1, v2, v3, trav->data))
			{
				return false;
			}
		}
		trav = trav->next;
	} while (trav != verticesDLL->root);


	return true;
}

void EarClippingMethod::Triangulate()
{
	//triangles.clear();

	Node* trav = verticesDLL->root;

	while (verticesDLL->size > 2)
	{
		if (IsEarTip(trav->prev->data, trav->data, trav->next->data))
		{
			triangles.push_back(Triangles(trav->prev->data, trav->data, trav->next->data));
			verticesDLL->Delete(trav);
			trav = verticesDLL->root;
		}
		trav = trav->next;
	}
}

bool EarClippingMethod::IsReflex(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3)
{

	return ((v1.x * (v3.y - v2.y)) + (v2.x * (v1.y - v3.y)) + (v3.x * (v2.y - v1.y))) > 0;
}

bool EarClippingMethod::IsPointInsideTriangle(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3, glm::vec2 pt)
{
	glm::vec2 edge0 = v1 - v2;
	glm::vec2 edge1 = v3 - v2;
	glm::vec2 edge2 = pt - v2;

	float dot00 = glm::dot(edge0, edge0);
	float dot01 = glm::dot(edge0, edge1);
	float dot02 = glm::dot(edge0, edge2);
	float dot11 = glm::dot(edge1, edge1);
	float dot12 = glm::dot(edge1, edge2);

	// Compute barycentric coordinates
	float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	// Check if point is in triangle
	return (u >= 0) && (v >= 0) && (u + v < 1);
}
