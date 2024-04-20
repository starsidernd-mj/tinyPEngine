#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <glm/glm.hpp>

#include <GL/glut.h>
#include <GL/freeglut.h>


namespace tinypengine {

	class Node {
	private:
		std::string name;
		glm::vec3 n_position = {0.0f, 0.0f, 0.0f};
		glm::vec3 n_rotation = {0.0f, 0.0f, 0.0f};
	
		std::vector<Node*> n_children;
	
	public:
		Node(const std::string& name, glm::vec3 pos);
		virtual ~Node();
		
		void init(const std::string& name);
		virtual void update();
		virtual void draw();
		virtual void drawCube();
		
		std::vector<glm::vec3> front, back, top, bottom, left, right;
		std::vector<std::vector<glm::vec3>> faces;
		std::vector<std::vector<glm::vec3>> generateVertices(int subdivisions);
		virtual void drawCube(std::vector<std::vector<glm::vec3>>& vertices, float size);
		
		void normalize(GLfloat* v);
		
		void addNode(Node* node);
		
		bool debug = 0;
		bool firstDraw = true;
	};
}
