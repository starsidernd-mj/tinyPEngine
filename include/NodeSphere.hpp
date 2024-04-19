#include <cmath>
#include "Node.hpp"

namespace tinypengine {

	class NodeSphere : public Node {
	public:
		NodeSphere(const std::string& name, glm::vec3 pos);
		
		virtual void update() override;
		virtual void draw() override;
		
		void drawTriangle(GLfloat* v1, GLfloat* v2, GLfloat* v3);
		void normalize(GLfloat* v);
		void drawIcosphere(float radius, int subdivisions);
		
	};

}
