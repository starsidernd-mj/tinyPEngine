
#include "Node.hpp"

namespace tinypengine {

	Node::Node(const std::string& name, glm::vec3 pos) {
		//initLogger();
		init(name);
		this->n_position = pos;
	}

	Node::~Node() {

	}
	
	void Node::init(const std::string& name) {
		this->name = name;
		std::cout << "Creating Node[" << name << "]" << std::endl;
	}
	
	void Node::update() {
	
	}
	
	void Node::draw() {
		// draw children
		//std::cout << "Drawing node[" << this->name << "]" << std::endl;
		/*for(size_t i = 0; i < n_children.size(); ++i) {
			Node* child = n_children[i];
			//std::cout << "Drawing node[" << child->name << "]" << std::endl;
			
			child->draw();
			
		}*/
		if(debug)
			drawCube();
	
		for(Node* i : n_children) {
			//std::cout << "Drawing node " << i->name << std::endl;
			i->draw();
		}
	}
	
	void Node::addNode(Node *node) {
		n_children.push_back(node);
	}
	
	void Node::drawCube() {
		//if(debug) std::cout << "drawing cube at (" << n_position.x << ", " << n_position.y << ", " << n_position.z << ")" << std::endl;
		// Front face
		glBegin(GL_QUADS);
		glColor3f( 1.0f, 0.0f, 0.0f); // Red
		glVertex3f(-1.0f + n_position.x, -1.0f + n_position.y, 1.0f + n_position.z);
		glVertex3f(1.0f  + n_position.x, -1.0f + n_position.y, 1.0f + n_position.z);
		glVertex3f(1.0f  + n_position.x, 1.0f  + n_position.y, 1.0f + n_position.z);
		glVertex3f(-1.0f + n_position.x, 1.0f  + n_position.y, 1.0f + n_position.z);
		glEnd();

		// Back face
		glBegin(GL_QUADS);
		glColor3f( 0.0f, 1.0f, 0.0f); // Green
		glVertex3f(-1.0f + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z);
		glVertex3f(1.0f  + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z);
		glVertex3f(1.0f  + n_position.x, 1.0f  + n_position.y, -1.0f + n_position.z);
		glVertex3f(-1.0f + n_position.x, 1.0f  + n_position.y, -1.0f + n_position.z);
		glEnd();

		// Top face
		glBegin(GL_QUADS);
		glColor3f( 0.0f, 0.0f, 1.0f); // Blue
		glVertex3f(-1.0f + n_position.x, 1.0f + n_position.y, -1.0f + n_position.z);
		glVertex3f(1.0f  + n_position.x, 1.0f + n_position.y, -1.0f + n_position.z);
		glVertex3f(1.0f  + n_position.x, 1.0f + n_position.y, 1.0f  + n_position.z);
		glVertex3f(-1.0f + n_position.x, 1.0f + n_position.y, 1.0f  + n_position.z);
		glEnd();

		// Bottom face
		glBegin(GL_QUADS);
		glColor3f( 1.0f, 1.0f, 0.0f); // Yellow
		glVertex3f(-1.0f + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z);
		glVertex3f(1.0f  + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z);
		glVertex3f(1.0f  + n_position.x, -1.0f + n_position.y, 1.0f  + n_position.z);
		glVertex3f(-1.0f + n_position.x, -1.0f + n_position.y, 1.0f  + n_position.z);
		glEnd();

		// Left face
		glBegin(GL_QUADS);
		glColor3f( 1.0f, 0.0f, 1.0f); // Magenta
		glVertex3f(-1.0f + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z);
		glVertex3f(-1.0f + n_position.x, 1.0f  + n_position.y, -1.0f + n_position.z);
		glVertex3f(-1.0f + n_position.x, 1.0f  + n_position.y, 1.0f  + n_position.z);
		glVertex3f(-1.0f + n_position.x, -1.0f + n_position.y, 1.0f  + n_position.z);
		glEnd();

		// Right face
		glBegin(GL_QUADS);
		glColor3f( 0.0f, 1.0f, 1.0f); // Cyan
		glVertex3f(1.0f + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z);
		glVertex3f(1.0f + n_position.x, 1.0f  + n_position.y, -1.0f + n_position.z);
		glVertex3f(1.0f + n_position.x, 1.0f  + n_position.y, 1.0f  + n_position.z);
		glVertex3f(1.0f + n_position.x, -1.0f + n_position.y, 1.0f  + n_position.z);
		glEnd();
	}

}
