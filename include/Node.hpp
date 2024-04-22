#ifndef NODE_H
#define NODE_H

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
		
		void addNode(Node* node);
	};
}

#endif
