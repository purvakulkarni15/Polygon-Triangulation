#include<iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Triangles
{
	public:
	
	glm::vec2 vertices[3];
	

	Triangles();
	virtual ~Triangles();

	Triangles(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3);
};

