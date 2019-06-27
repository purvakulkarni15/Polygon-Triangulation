#include"DLL.h"
#include"Triangles.h"
#include<vector>

class EarClippingMethod
{
	public:

	DLL *verticesDLL = NULL;
	std::vector<Triangles> triangles;

	~EarClippingMethod();

	EarClippingMethod(glm::vec2 vertices[], int size);
	EarClippingMethod();

	bool IsReflex(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3);
	bool IsPointInsideTriangle(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3, glm::vec2 pt);
	bool IsEarTip(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3);
	
	void Triangulate();

};