
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
		
		faces = generateVertices(10);
		std::cout << "Generating " << faces[0].size() << " vertices" << std::endl;
	}
	
	void Node::update() {}
	
	void Node::draw() {
		// draw children
		if(debug) {
			//drawCube();
			// Generate cube vertices with 5 subdivisions
    		//std::vector<glm::vec3> vertices = generateVertices(2);
    		// Draw cube with size 1.0
    		drawCube(faces, 1.0f);
		}
	
		for(Node* i : n_children) {
			//std::cout << "Drawing node " << i->name << std::endl;
			i->draw();
		}
	}
	
	void Node::addNode(Node *node) {
		n_children.push_back(node);
	}
	
	std::vector<std::vector<glm::vec3>> Node::generateVertices(int subdivisions) {
		std::vector<std::vector<glm::vec3>> vertices;
		float step = 1.0f / subdivisions;
		//float step = 2.0f;
		
		//		y
		//		|
		//		---- z
		//		\
		//		 \
		//		  \-x

		

		for(int i = 0; i <= subdivisions; i++) {
			for(int j = 0; j <= subdivisions; j++) {										 
				glm::vec3 p_front  = {	-1.0f + ( j * step) + n_position.x,
										-1.0f + ( i * step) + n_position.y,
										 1.0f               + n_position.z};
										 
				glm::vec3 p_back   = {	-1.0f + ( j * step) + n_position.x,
										-1.0f + ( i * step) + n_position.y,
										-1.0f               + n_position.z};
										
				glm::vec3 p_top    = {	-1.0f + ( i * step) + n_position.x,
										 1.0f               + n_position.y,
										-1.0f + ( j * step) + n_position.z};
										 
				glm::vec3 p_bottom = {	-1.0f + ( i * step) + n_position.x,
										-1.0f               + n_position.y,
										-1.0f + ( j * step) + n_position.z};
										 
				glm::vec3 p_left   = {	-1.0f               + n_position.x,
										-1.0f + ( i * step) + n_position.y,
										-1.0f + ( j * step) + n_position.z};
										 
				glm::vec3 p_right  = {	 1.0f               + n_position.x,
										-1.0f + ( i * step) + n_position.y,
										-1.0f + ( j * step) + n_position.z};
										 
				front.push_back(p_front);
				back.push_back(p_back);
				top.push_back(p_top);
				bottom.push_back(p_bottom);
				left.push_back(p_left);
				right.push_back(p_right);
				
				//std::cout << "Start" << std::endl;
				//std::cout << p_front.x  << ", " << p_front.y  << ", " << p_front.z  << std::endl;
				//std::cout << p_back.x   << ", " << p_back.y   << ", " << p_back.z   << std::endl;
				//std::cout << p_top.x    << ", " << p_top.y    << ", " << p_top.z    << std::endl;
				//std::cout << p_bottom.x << ", " << p_bottom.y << ", " << p_bottom.z << std::endl;
				//std::cout << p_left.x   << ", " << p_left.y   << ", " << p_left.z   << std::endl;
				//std::cout << p_right.x  << ", " << p_right.y  << ", " << p_right.z  << std::endl;
				//std::cout << "End" << std::endl;
			}
		}
		
		vertices.push_back(front);
		vertices.push_back(back);
		vertices.push_back(top);
		vertices.push_back(bottom);
		vertices.push_back(left);
		vertices.push_back(right);
		
		//std::cout << "Generated " << vertices.size() << " vertices" << std::endl;
		return vertices;
	}
	
	void Node::drawCube(std::vector<std::vector<glm::vec3>> &faces, float size) {
		//glBegin(GL_QUADS);
		
		int subdivisions = sqrt(faces[0].size()) - 1;
		float step = 1 + subdivisions;
		
		for(int j = 0; j < subdivisions; j++) {
			for(int i = 0; i < subdivisions; i++) {
				int idx0 = j+(i*step);
				int idx1 = j+1+(i*step);
				int idx2 = j+step+(i*step);
				int idx3 = j+step+1+(i*step);
				
				// Front face
				glBegin(GL_QUADS);
				glColor3f( 1.0f, 0.0f, 0.0f); // Red
				glVertex3f(faces[0][idx0].x*size, faces[0][idx0].y*size, faces[0][idx0].z*size);
				glVertex3f(faces[0][idx1].x*size, faces[0][idx1].y*size, faces[0][idx1].z*size);
				glVertex3f(faces[0][idx3].x*size, faces[0][idx3].y*size, faces[0][idx3].z*size);
				glVertex3f(faces[0][idx2].x*size, faces[0][idx2].y*size, faces[0][idx2].z*size);
				glEnd();
		
				// Back face
				glBegin(GL_QUADS);
				glColor3f( 0.0f, 1.0f, 0.0f); // Green
				glVertex3f(faces[1][idx0].x*size, faces[1][idx0].y*size, faces[1][idx0].z*size);
				glVertex3f(faces[1][idx1].x*size, faces[1][idx1].y*size, faces[1][idx1].z*size);
				glVertex3f(faces[1][idx3].x*size, faces[1][idx3].y*size, faces[1][idx3].z*size);
				glVertex3f(faces[1][idx2].x*size, faces[1][idx2].y*size, faces[1][idx2].z*size);
				glEnd();
				
				// Top face
				glBegin(GL_QUADS);
				glColor3f( 0.0f, 0.0f, 1.0f); // Blue
				glVertex3f(faces[2][idx0].x*size, faces[2][idx0].y*size, faces[2][idx0].z*size);
				glVertex3f(faces[2][idx1].x*size, faces[2][idx1].y*size, faces[2][idx1].z*size);
				glVertex3f(faces[2][idx3].x*size, faces[2][idx3].y*size, faces[2][idx3].z*size);
				glVertex3f(faces[2][idx2].x*size, faces[2][idx2].y*size, faces[2][idx2].z*size);
				glEnd();
				
				// Botton face
				glBegin(GL_QUADS);
				glColor3f( 1.0f, 1.0f, 0.0f); // Yellow
				glVertex3f(faces[3][idx0].x*size, faces[3][idx0].y*size, faces[3][idx0].z*size);
				glVertex3f(faces[3][idx1].x*size, faces[3][idx1].y*size, faces[3][idx1].z*size);
				glVertex3f(faces[3][idx3].x*size, faces[3][idx3].y*size, faces[3][idx3].z*size);
				glVertex3f(faces[3][idx2].x*size, faces[3][idx2].y*size, faces[3][idx2].z*size);
				glEnd();
				
				// Left face
				glBegin(GL_QUADS);
				glColor3f( 1.0f, 0.0f, 1.0f); // Magenta
				glVertex3f(faces[4][idx0].x*size, faces[4][idx0].y*size, faces[4][idx0].z*size);
				glVertex3f(faces[4][idx1].x*size, faces[4][idx1].y*size, faces[4][idx1].z*size);
				glVertex3f(faces[4][idx3].x*size, faces[4][idx3].y*size, faces[4][idx3].z*size);
				glVertex3f(faces[4][idx2].x*size, faces[4][idx2].y*size, faces[4][idx2].z*size);
				glEnd();
				
				// Right face
				glBegin(GL_QUADS);
				glColor3f( 0.0f, 1.0f, 1.0f); // Cyan
				glVertex3f(faces[5][idx0].x*size, faces[5][idx0].y*size, faces[5][idx0].z*size);
				glVertex3f(faces[5][idx1].x*size, faces[5][idx1].y*size, faces[5][idx1].z*size);
				glVertex3f(faces[5][idx3].x*size, faces[5][idx3].y*size, faces[5][idx3].z*size);
				glVertex3f(faces[5][idx2].x*size, faces[5][idx2].y*size, faces[5][idx2].z*size);
				glEnd();
			}
		}
	}
	
	void Node::drawCube() {
	
		 GLfloat vertices[8][3] = {
		    {-1.0f + n_position.x, -1.0f + n_position.y,  1.0f + n_position.z},
		    { 1.0f + n_position.x, -1.0f + n_position.y,  1.0f + n_position.z},
		    { 1.0f + n_position.x,  1.0f + n_position.y,  1.0f + n_position.z},
		    {-1.0f + n_position.x,  1.0f + n_position.y,  1.0f + n_position.z},
		    {-1.0f + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z},
		    {-1.0f + n_position.x,  1.0f + n_position.y, -1.0f + n_position.z},
		    { 1.0f + n_position.x,  1.0f + n_position.y, -1.0f + n_position.z},
		    { 1.0f + n_position.x, -1.0f + n_position.y, -1.0f + n_position.z}
		};
		
		{
			// Front face
			glBegin(GL_QUADS);
			glColor3f( 1.0f, 0.0f, 0.0f); // Red
			//normalize(vertices[0]); normalize(vertices[1]); normalize(vertices[2]); normalize(vertices[3]);
			glVertex3fv(vertices[0]);
			glVertex3fv(vertices[1]);
			glVertex3fv(vertices[2]);
			glVertex3fv(vertices[3]);
			glEnd();
		
			// Back face
			glBegin(GL_QUADS);
			glColor3f( 0.0f, 1.0f, 0.0f); // Green
			//normalize(vertices[4]); normalize(vertices[7]); normalize(vertices[6]); normalize(vertices[5]);
			glVertex3fv(vertices[4]);
			glVertex3fv(vertices[7]);
			glVertex3fv(vertices[6]);
			glVertex3fv(vertices[5]);
			glEnd();

			// Top face
			glBegin(GL_QUADS);
			glColor3f( 0.0f, 0.0f, 1.0f); // Blue
			//normalize(vertices[5]); normalize(vertices[6]); normalize(vertices[2]); normalize(vertices[3]);
			glVertex3fv(vertices[5]);
			glVertex3fv(vertices[6]);
			glVertex3fv(vertices[2]);
			glVertex3fv(vertices[3]);
			glEnd();

			// Bottom face
			glBegin(GL_QUADS);
			glColor3f( 1.0f, 1.0f, 0.0f); // Yellow
			//normalize(vertices[4]); normalize(vertices[7]); normalize(vertices[1]); normalize(vertices[0]);
			glVertex3fv(vertices[4]);
			glVertex3fv(vertices[7]);
			glVertex3fv(vertices[1]);
			glVertex3fv(vertices[0]);
			glEnd();

			// Right face
			glBegin(GL_QUADS);
			glColor3f( 0.0f, 1.0f, 1.0f); // Cyan
			//normalize(vertices[7]); normalize(vertices[6]); normalize(vertices[2]); normalize(vertices[1]);
			glVertex3fv(vertices[7]);
			glVertex3fv(vertices[6]);
			glVertex3fv(vertices[2]);
			glVertex3fv(vertices[1]);
			glEnd();

			// Left face
			glBegin(GL_QUADS);
			glColor3f( 1.0f, 0.0f, 1.0f); // Magenta
			//normalize(vertices[4]); normalize(vertices[5]); normalize(vertices[3]); normalize(vertices[0]);
			glVertex3fv(vertices[4]);
			glVertex3fv(vertices[5]);
			glVertex3fv(vertices[3]);
			glVertex3fv(vertices[0]);
			glEnd();
		}
	}
	
	void Node::normalize(GLfloat* v) {
		GLfloat length = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
		v[0] /= length;
		v[1] /= length;
		v[2] /= length;
	}
	
	

}
