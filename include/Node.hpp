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
		glm::vec3 normalizeQuad(glm::vec3 v);
		void normalizeQuad(glm::vec3 *v);
		void drawQuad(GLfloat* v1, GLfloat* v2, GLfloat* v3, GLfloat* v4);
		void drawQuad(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4);
		void printVertices(std::vector<glm::vec3> fc, std::string name);
		
		void addNode(Node* node);
		
		bool debug = 0;
		bool firstDraw = true;
	};
}
