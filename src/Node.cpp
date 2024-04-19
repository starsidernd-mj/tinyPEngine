
#include "Node.hpp"

namespace tinypengine {

	Node::Node(const std::string& name, glm::vec3 pos) {
		//initLogger();
		init(name);
		this->n_position = pos;
	}

	Node::~Node() {}
	
	void Node::init(const std::string& name) {
		this->name = name;
		std::cout << "Creating Node[" << name << "]" << std::endl;
	}
	
	void Node::update() {}
	
	void Node::draw() {
		// draw children
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
	
		 GLfloat vertices[8][3] = {
		    {-1.0f + n_position.x, -1.0f + n_position.y, 1.0f + n_position.z},
		    {1.0f + n_position.x, -1.0f + n_position.y, 1.0f + n_position.z},
		    {1.0f + n_position.x, 1.0f + n_position.y, 1.0f + n_position.z},
		    {-1.0f + n_position.x, 1.0f + n_position.y, 1.0f + n_position.z},
		    {-1.0f + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z},
		    {-1.0f + n_position.x, 1.0f + n_position.y, -1.0f + n_position.z},
		    {1.0f + n_position.x, 1.0f + n_position.y, -1.0f + n_position.z},
		    {1.0f + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z}
		};
		
		{
			// Front face
			glBegin(GL_QUADS);
			glColor3f( 1.0f, 0.0f, 0.0f); // Red
			normalize(vertices[0]); normalize(vertices[1]); normalize(vertices[2]); normalize(vertices[3]);
			glVertex3fv(vertices[0]);
			glVertex3fv(vertices[1]);
			glVertex3fv(vertices[2]);
			glVertex3fv(vertices[3]);
			glEnd();
		
			// Back face
			glBegin(GL_QUADS);
			glColor3f( 0.0f, 1.0f, 0.0f); // Green
			normalize(vertices[4]); normalize(vertices[5]); normalize(vertices[6]); normalize(vertices[7]);
			glVertex3fv(vertices[4]);
			glVertex3fv(vertices[5]);
			glVertex3fv(vertices[6]);
			glVertex3fv(vertices[7]);
			glEnd();

			// Top face
			glBegin(GL_QUADS);
			glColor3f( 0.0f, 0.0f, 1.0f); // Blue
			normalize(vertices[3]); normalize(vertices[2]); normalize(vertices[6]); normalize(vertices[7]);
			glVertex3fv(vertices[3]);
			glVertex3fv(vertices[2]);
			glVertex3fv(vertices[6]);
			glVertex3fv(vertices[7]);
			glEnd();

			// Bottom face
			glBegin(GL_QUADS);
			glColor3f( 1.0f, 1.0f, 0.0f); // Yellow
			normalize(vertices[0]); normalize(vertices[1]); normalize(vertices[5]); normalize(vertices[4]);
			glVertex3fv(vertices[0]);
			glVertex3fv(vertices[1]);
			glVertex3fv(vertices[5]);
			glVertex3fv(vertices[4]);
			glEnd();

			// Right face
			glBegin(GL_QUADS);
			glColor3f( 0.0f, 1.0f, 1.0f); // Cyan
			normalize(vertices[1]); normalize(vertices[2]); normalize(vertices[6]); normalize(vertices[5]);
			glVertex3fv(vertices[1]);
			glVertex3fv(vertices[2]);
			glVertex3fv(vertices[6]);
			glVertex3fv(vertices[5]);
			glEnd();

			// Left face
			glBegin(GL_QUADS);
			glColor3f( 1.0f, 0.0f, 1.0f); // Magenta
			normalize(vertices[0]); normalize(vertices[3]); normalize(vertices[7]); normalize(vertices[4]);
			glVertex3fv(vertices[0]);
			glVertex3fv(vertices[3]);
			glVertex3fv(vertices[7]);
			glVertex3fv(vertices[4]);
			glEnd();
		}
		
		//if(debug) std::cout << "drawing cube at (" << n_position.x << ", " << n_position.y << ", " << n_position.z << ")" << std::endl;
		// Front face
		/*glBegin(GL_QUADS);
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
		glEnd();*/
	}
	
	void Node::normalize(GLfloat* v) {
		GLfloat length = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
		v[0] /= length;
		v[1] /= length;
		v[2] /= length;
	}
	
	

}
