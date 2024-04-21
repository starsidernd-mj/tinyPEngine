
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
		debugPoints = generateFaces(faces, 2.0f, true);
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
    		//generateFaces(faces, 2.0f, false);
    		drawCubeO(debugPoints);
    		//drawCube(faces, 2.0f, true);
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
		float sp = 0.5f;
		
		//		y
		//		|
		//		---- z
		//		\
		//		 \
		//		  \-x

		std::cout << "Subdivisions[" << subdivisions << "], Steps[" << step << "]" << std::endl;

		for(int i = 0; i <= subdivisions; i++) {
			for(int j = 0; j <= subdivisions; j++) {										 
				glm::vec3 p_front  = {	-sp + ( j * step) + n_position.x,
										-sp + ( i * step) + n_position.y,
										 sp               + n_position.z};
										 
				glm::vec3 p_back   = {	-sp + ( j * step) + n_position.x,
										-sp + ( i * step) + n_position.y,
										-sp               + n_position.z};
										
				glm::vec3 p_top    = {	-sp + ( i * step) + n_position.x,
										 sp               + n_position.y,
										-sp + ( j * step) + n_position.z};
										 
				glm::vec3 p_bottom = {	-sp + ( i * step) + n_position.x,
										-sp               + n_position.y,
										-sp + ( j * step) + n_position.z};
										 
				glm::vec3 p_left   = {	-sp               + n_position.x,
										-sp + ( i * step) + n_position.y,
										-sp + ( j * step) + n_position.z};
										 
				glm::vec3 p_right  = {	 sp               + n_position.x,
										-sp + ( i * step) + n_position.y,
										-sp + ( j * step) + n_position.z};
										 
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
		
		//printVertices(front, "front");
		//printVertices(back, "back");
		//printVertices(top, "top");
		//printVertices(bottom, "bottom");
		//printVertices(left, "left");
		//printVertices(right, "right");
		
		//std::cout << "Generated " << vertices.size() << " vertices" << std::endl;
		return vertices;
	}
	
	std::vector<std::vector<glm::vec3>> Node::generateFaces(std::vector<std::vector<glm::vec3>> &faces, float size, bool norm) {
		std::vector<glm::vec3> a1;
		std::vector<glm::vec3> a2;
		std::vector<glm::vec3> a3;
		std::vector<glm::vec3> a4;
		
		glm::vec3 v1, v2, v3, v4;
		
		int subdivisions = sqrt(faces[0].size()) - 1;
		float step = 1 + subdivisions;
		
		for(int j = 0; j < subdivisions; j++) {
			for(int i = 0; i < subdivisions; i++) {
				int idx0 = j+(i*step);
				int idx1 = j+1+(i*step);
				int idx2 = j+step+(i*step);
				int idx3 = j+step+1+(i*step);
				
				// Front face
				//glColor3f( 1.0f, 0.0f, 0.0f); // Red
				v1 = (glm::vec3{faces[0][idx0].x*size, faces[0][idx0].y*size, faces[0][idx0].z*size});
				v2 = (glm::vec3{faces[0][idx1].x*size, faces[0][idx1].y*size, faces[0][idx1].z*size});
				v3 = (glm::vec3{faces[0][idx3].x*size, faces[0][idx3].y*size, faces[0][idx3].z*size});
				v4 = (glm::vec3{faces[0][idx2].x*size, faces[0][idx2].y*size, faces[0][idx2].z*size});
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1);
				a2.push_back(v2);
				a3.push_back(v3);
				a4.push_back(v4);
				//drawQuad(v1, v2, v3, v4);
		
				// Back face
				//glColor3f( 0.0f, 1.0f, 0.0f); // Green
				v1 = (glm::vec3{faces[1][idx0].x*size, faces[1][idx0].y*size, faces[1][idx0].z*size});
				v2 = (glm::vec3{faces[1][idx1].x*size, faces[1][idx1].y*size, faces[1][idx1].z*size});
				v3 = (glm::vec3{faces[1][idx3].x*size, faces[1][idx3].y*size, faces[1][idx3].z*size});
				v4 = (glm::vec3{faces[1][idx2].x*size, faces[1][idx2].y*size, faces[1][idx2].z*size});
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1);
				a2.push_back(v2);
				a3.push_back(v3);
				a4.push_back(v4);
				//drawQuad(v1, v2, v3, v4);
				
				// Top face
				//glColor3f( 0.0f, 0.0f, 1.0f); // Blue
				v1 = (glm::vec3{faces[2][idx0].x*size, faces[2][idx0].y*size, faces[2][idx0].z*size});
				v2 = (glm::vec3{faces[2][idx1].x*size, faces[2][idx1].y*size, faces[2][idx1].z*size});
				v3 = (glm::vec3{faces[2][idx3].x*size, faces[2][idx3].y*size, faces[2][idx3].z*size});
				v4 = (glm::vec3{faces[2][idx2].x*size, faces[2][idx2].y*size, faces[2][idx2].z*size});
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1);
				a2.push_back(v2);
				a3.push_back(v3);
				a4.push_back(v4);
				//drawQuad(v1, v2, v3, v4);
				
				// Botton face
				//glColor3f( 1.0f, 1.0f, 0.0f); // Yellow
				v1 = (glm::vec3{faces[3][idx0].x*size, faces[3][idx0].y*size, faces[3][idx0].z*size});
				v2 = (glm::vec3{faces[3][idx1].x*size, faces[3][idx1].y*size, faces[3][idx1].z*size});
				v3 = (glm::vec3{faces[3][idx3].x*size, faces[3][idx3].y*size, faces[3][idx3].z*size});
				v4 = (glm::vec3{faces[3][idx2].x*size, faces[3][idx2].y*size, faces[3][idx2].z*size});
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1);
				a2.push_back(v2);
				a3.push_back(v3);
				a4.push_back(v4);
				//drawQuad(v1, v2, v3, v4);
				
				// Left face
				//glColor3f( 1.0f, 0.0f, 1.0f); // Magenta
				v1 = (glm::vec3{faces[4][idx0].x*size, faces[4][idx0].y*size, faces[4][idx0].z*size});
				v2 = (glm::vec3{faces[4][idx1].x*size, faces[4][idx1].y*size, faces[4][idx1].z*size});
				v3 = (glm::vec3{faces[4][idx3].x*size, faces[4][idx3].y*size, faces[4][idx3].z*size});
				v4 = (glm::vec3{faces[4][idx2].x*size, faces[4][idx2].y*size, faces[4][idx2].z*size});
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1);
				a2.push_back(v2);
				a3.push_back(v3);
				a4.push_back(v4);
				//drawQuad(v1, v2, v3, v4);
				
				// Right face
				//glColor3f( 0.0f, 1.0f, 1.0f); // Cyan
				v1 = (glm::vec3{faces[5][idx0].x*size, faces[5][idx0].y*size, faces[5][idx0].z*size});
				v2 = (glm::vec3{faces[5][idx1].x*size, faces[5][idx1].y*size, faces[5][idx1].z*size});
				v3 = (glm::vec3{faces[5][idx3].x*size, faces[5][idx3].y*size, faces[5][idx3].z*size});
				v4 = (glm::vec3{faces[5][idx2].x*size, faces[5][idx2].y*size, faces[5][idx2].z*size});
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1);
				a2.push_back(v2);
				a3.push_back(v3);
				a4.push_back(v4);
				//drawQuad(v1, v2, v3, v4);
			}
		}
		//drawCubeO(&v1, &v2, &v3, &v4);
		//drawCubeO(v1, v2, v3, v4);
		std::vector<std::vector<glm::vec3>> faceVecPoints = {a1, a2, a3, a4};
		return faceVecPoints;
	}
	
	//void Node::drawCubeO(std::vector<glm::vec3> v1, std::vector<glm::vec3> v2, std::vector<glm::vec3> v3, std::vector<glm::vec3> v4) {
	void Node::drawCubeO(std::vector<std::vector<glm::vec3>> v0) {
	
		//std::cout << "test: " << v1[0].x << ", " << v1[0].y << ", " << v1[0].z << std::endl;
		std::vector<glm::vec3> v1 = v0[0];
		std::vector<glm::vec3> v2 = v0[1];
		std::vector<glm::vec3> v3 = v0[2];
		std::vector<glm::vec3> v4 = v0[3];
	
	
		for(int i = 0; i < (int)v1.size(); i++) {
			glBegin(GL_QUADS);
			switch(i%6) {
				case 0: {
					glColor3f( 1.0f, 0.0f, 0.0f); // Red
				} break;
				case 1: {
					glColor3f( 0.0f, 1.0f, 0.0f); // Green
				} break;
				case 2: {
					glColor3f( 0.0f, 0.0f, 1.0f); // Blue
				} break;
				case 3: {
					glColor3f( 1.0f, 1.0f, 0.0f); // Yellow
				} break;
				case 4: {
					glColor3f( 1.0f, 0.0f, 1.0f); // Magenta
				} break;
				case 5: {
					glColor3f( 0.0f, 1.0f, 1.0f); // Cyan
				} break;
			}
			glVertex3f(v1[i].x, v1[i].y, v1[i].z);
			glVertex3f(v2[i].x, v2[i].y, v2[i].z);
			glVertex3f(v3[i].x, v3[i].y, v3[i].z);
			glVertex3f(v4[i].x, v4[i].y, v4[i].z);
			glEnd();
			
			/*glLineWidth(3.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			glBegin(GL_LINE_LOOP);
			glVertex3f(v1[i].x, v1[i].y, v1[i].z);
			glVertex3f(v2[i].x, v2[i].y, v2[i].z);
			glVertex3f(v3[i].x, v3[i].y, v3[i].z);
			glVertex3f(v4[i].x, v4[i].y, v4[i].z);
			glEnd();*/
		}
	
		/*glBegin(GL_QUADS);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v4);
		glEnd();*/
		
		//draw lines around quad
		/*glLineWidth(3.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v4);
		glEnd();*/
		
		glFlush();
	}
	
	void Node::drawCube(std::vector<std::vector<glm::vec3>> &faces, float size, bool norm) {
		glm::vec3 v1;
		glm::vec3 v2;
		glm::vec3 v3;
		glm::vec3 v4;
		
		int subdivisions = sqrt(faces[0].size()) - 1;
		float step = 1 + subdivisions;
		
		for(int j = 0; j < subdivisions; j++) {
			for(int i = 0; i < subdivisions; i++) {
				int idx0 = j+(i*step);
				int idx1 = j+1+(i*step);
				int idx2 = j+step+(i*step);
				int idx3 = j+step+1+(i*step);
				
				// Front face
				glColor3f( 1.0f, 0.0f, 0.0f); // Red
				v1 = glm::vec3{faces[0][idx0].x*size, faces[0][idx0].y*size, faces[0][idx0].z*size};
				v2 = glm::vec3{faces[0][idx1].x*size, faces[0][idx1].y*size, faces[0][idx1].z*size};
				v3 = glm::vec3{faces[0][idx3].x*size, faces[0][idx3].y*size, faces[0][idx3].z*size};
				v4 = glm::vec3{faces[0][idx2].x*size, faces[0][idx2].y*size, faces[0][idx2].z*size};
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				drawQuad(v1, v2, v3, v4);
		
				// Back face
				glColor3f( 0.0f, 1.0f, 0.0f); // Green
				v1 = glm::vec3{faces[1][idx0].x*size, faces[1][idx0].y*size, faces[1][idx0].z*size};
				v2 = glm::vec3{faces[1][idx1].x*size, faces[1][idx1].y*size, faces[1][idx1].z*size};
				v3 = glm::vec3{faces[1][idx3].x*size, faces[1][idx3].y*size, faces[1][idx3].z*size};
				v4 = glm::vec3{faces[1][idx2].x*size, faces[1][idx2].y*size, faces[1][idx2].z*size};
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				drawQuad(v1, v2, v3, v4);
				
				// Top face
				glColor3f( 0.0f, 0.0f, 1.0f); // Blue
				v1 = glm::vec3{faces[2][idx0].x*size, faces[2][idx0].y*size, faces[2][idx0].z*size};
				v2 = glm::vec3{faces[2][idx1].x*size, faces[2][idx1].y*size, faces[2][idx1].z*size};
				v3 = glm::vec3{faces[2][idx3].x*size, faces[2][idx3].y*size, faces[2][idx3].z*size};
				v4 = glm::vec3{faces[2][idx2].x*size, faces[2][idx2].y*size, faces[2][idx2].z*size};
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				drawQuad(v1, v2, v3, v4);
				
				// Botton face
				glColor3f( 1.0f, 1.0f, 0.0f); // Yellow
				v1 = glm::vec3{faces[3][idx0].x*size, faces[3][idx0].y*size, faces[3][idx0].z*size};
				v2 = glm::vec3{faces[3][idx1].x*size, faces[3][idx1].y*size, faces[3][idx1].z*size};
				v3 = glm::vec3{faces[3][idx3].x*size, faces[3][idx3].y*size, faces[3][idx3].z*size};
				v4 = glm::vec3{faces[3][idx2].x*size, faces[3][idx2].y*size, faces[3][idx2].z*size};
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				drawQuad(v1, v2, v3, v4);
				
				// Left face
				glColor3f( 1.0f, 0.0f, 1.0f); // Magenta
				v1 = glm::vec3{faces[4][idx0].x*size, faces[4][idx0].y*size, faces[4][idx0].z*size};
				v2 = glm::vec3{faces[4][idx1].x*size, faces[4][idx1].y*size, faces[4][idx1].z*size};
				v3 = glm::vec3{faces[4][idx3].x*size, faces[4][idx3].y*size, faces[4][idx3].z*size};
				v4 = glm::vec3{faces[4][idx2].x*size, faces[4][idx2].y*size, faces[4][idx2].z*size};
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				drawQuad(v1, v2, v3, v4);
				
				// Right face
				glColor3f( 0.0f, 1.0f, 1.0f); // Cyan
				v1 = glm::vec3{faces[5][idx0].x*size, faces[5][idx0].y*size, faces[5][idx0].z*size};
				v2 = glm::vec3{faces[5][idx1].x*size, faces[5][idx1].y*size, faces[5][idx1].z*size};
				v3 = glm::vec3{faces[5][idx3].x*size, faces[5][idx3].y*size, faces[5][idx3].z*size};
				v4 = glm::vec3{faces[5][idx2].x*size, faces[5][idx2].y*size, faces[5][idx2].z*size};
				
				if(norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				drawQuad(v1, v2, v3, v4);
			}
		}
	}
	
	void Node::drawCube() {}
	
	void Node::normalize(GLfloat* v) {
		GLfloat length = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
		v[0] /= length;
		v[1] /= length;
		v[2] /= length;
	}
	
	/*NOT WORKING DUE TO PACKED glm:vec3 conversion issue, current one used is not overriding the pointed value so it's a wasted operation*/
	void Node::normalizeQuad(glm::vec3 *v) {
		GLfloat length = sqrt(v->x*v->x + v->y*v->y + v->z*v->z);
		v->x /= length;
		v->y /= length;
		v->z /= length;
	}//*/
	
	/*glm::vec3 Node::normalizeQuad(glm::vec3 v) {
		GLfloat vf[3] = {v.x, v.y, v.z};
		GLfloat length = sqrt(vf[0]*vf[0] + vf[1]*vf[1] + vf[2]*vf[2]);
		//normalizeQuad(vf);
		
		vf[0] /= length;
		vf[1] /= length;
		vf[2] /= length;
		
		glm::vec3 vv = {vf[0], vf[1], vf[2]};
		return vv;
	}*/
	
	void Node::drawQuad(GLfloat* v1, GLfloat* v2, GLfloat* v3, GLfloat* v4) {
		glBegin(GL_QUADS);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v4);
		glEnd();
		
		//draw lines around quad
		/*glLineWidth(3.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v4);
		glEnd();*/
		
		glFlush();
	}
	
	void Node::drawQuad(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4) {
		GLfloat vf1[3] = {v1.x, v1.y, v1.z};
		GLfloat vf2[3] = {v2.x, v2.y, v2.z};
		GLfloat vf3[3] = {v3.x, v3.y, v3.z};
		GLfloat vf4[3] = {v4.x, v4.y, v4.z};
		
		drawQuad(vf1, vf2, vf3, vf4);
	}

	void Node::printVertices(std::vector<glm::vec3> fc, std::string name) {
		std::cout << "Print vertices points for " << name << std::endl;
		
		for(int i = 0; i < (int)fc.size(); i++) {
			std::cout << "{" << fc[i].x << ", " << fc[i].y << ", " << fc[i].z << "}" << std::endl;
		}
		
		std::cout << "Vertices done" << std::endl;
	}
}
