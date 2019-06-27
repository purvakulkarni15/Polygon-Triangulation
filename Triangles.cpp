#include "Triangles.h"


Triangles::Triangles()
{

}


Triangles::~Triangles()
{
}

Triangles::Triangles(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3)
{
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;
}