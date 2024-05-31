
#include "NodeCube.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace tinypengine {

	NodeCube::NodeCube(const std::string& name, glm::vec3 pos, int subdiv, float size, bool norm) : Node(name, pos) {
		this->n_position = pos;
		this->n_subdiv = subdiv;
		this->n_size = size;
		this->n_norm = norm;
		std::cout << "Subdiv[" << this->n_subdiv << "], Size[" << this->n_size << "], Norm[" << this->n_norm << "]" << std::endl;
		
		init(name);
	}

	NodeCube::~NodeCube() {}
	
	void NodeCube::init(const std::string& name) {
		this->name = name;
		std::cout << "\tCreating NodeCube[" << name << "]" << std::endl;
		
		faces = generateVertices(this->n_subdiv);
		debugPoints = generateFaces(faces, this->n_size, this->n_norm);
		std::cout << "Generating " << faces[0].size() << " vertices and " << debugPoints[0].size() << " faces" << std::endl;
		textureID = loadTexture("../assets/textures/grid.jpg");
	}
	
	void NodeCube::update() {}
	
	void NodeCube::draw() {
		// draw children
		drawCube(debugPoints);
	
		for(Node* i : n_children) {
			//std::cout << "Drawing node " << i->name << std::endl;
			i->draw();
		}
	}
	
	void NodeCube::addNode(Node *node) {
		n_children.push_back(node);
	}
	
	std::vector<std::vector<glm::vec3>> NodeCube::generateVertices(int subdivisions) {
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
	
	std::vector<std::vector<glm::vec3>> NodeCube::generateFaces(std::vector<std::vector<glm::vec3>> &faces, float size, bool norm) {
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
				v1 = (glm::vec3{faces[0][idx0].x, faces[0][idx0].y, faces[0][idx0].z});
				v2 = (glm::vec3{faces[0][idx1].x, faces[0][idx1].y, faces[0][idx1].z});
				v3 = (glm::vec3{faces[0][idx3].x, faces[0][idx3].y, faces[0][idx3].z});
				v4 = (glm::vec3{faces[0][idx2].x, faces[0][idx2].y, faces[0][idx2].z});
				
				if(this->n_norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1*size);
				a2.push_back(v2*size);
				a3.push_back(v3*size);
				a4.push_back(v4*size);
				//drawQuad(v1, v2, v3, v4);
		
				// Back face
				//glColor3f( 0.0f, 1.0f, 0.0f); // Green
				v1 = (glm::vec3{faces[1][idx0].x, faces[1][idx0].y, faces[1][idx0].z});
				v2 = (glm::vec3{faces[1][idx1].x, faces[1][idx1].y, faces[1][idx1].z});
				v3 = (glm::vec3{faces[1][idx3].x, faces[1][idx3].y, faces[1][idx3].z});
				v4 = (glm::vec3{faces[1][idx2].x, faces[1][idx2].y, faces[1][idx2].z});
				
				if(this->n_norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1*size);
				a2.push_back(v2*size);
				a3.push_back(v3*size);
				a4.push_back(v4*size);
				//drawQuad(v1, v2, v3, v4);
				
				// Top face
				//glColor3f( 0.0f, 0.0f, 1.0f); // Blue
				v1 = (glm::vec3{faces[2][idx0].x, faces[2][idx0].y, faces[2][idx0].z});
				v2 = (glm::vec3{faces[2][idx1].x, faces[2][idx1].y, faces[2][idx1].z});
				v3 = (glm::vec3{faces[2][idx3].x, faces[2][idx3].y, faces[2][idx3].z});
				v4 = (glm::vec3{faces[2][idx2].x, faces[2][idx2].y, faces[2][idx2].z});
				
				if(this->n_norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1*size);
				a2.push_back(v2*size);
				a3.push_back(v3*size);
				a4.push_back(v4*size);
				//drawQuad(v1, v2, v3, v4);
				
				// Botton face
				//glColor3f( 1.0f, 1.0f, 0.0f); // Yellow
				v1 = (glm::vec3{faces[3][idx0].x, faces[3][idx0].y, faces[3][idx0].z});
				v2 = (glm::vec3{faces[3][idx1].x, faces[3][idx1].y, faces[3][idx1].z});
				v3 = (glm::vec3{faces[3][idx3].x, faces[3][idx3].y, faces[3][idx3].z});
				v4 = (glm::vec3{faces[3][idx2].x, faces[3][idx2].y, faces[3][idx2].z});
				
				if(this->n_norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1*size);
				a2.push_back(v2*size);
				a3.push_back(v3*size);
				a4.push_back(v4*size);
				//drawQuad(v1, v2, v3, v4);
				
				// Left face
				//glColor3f( 1.0f, 0.0f, 1.0f); // Magenta
				v1 = (glm::vec3{faces[4][idx0].x, faces[4][idx0].y, faces[4][idx0].z});
				v2 = (glm::vec3{faces[4][idx1].x, faces[4][idx1].y, faces[4][idx1].z});
				v3 = (glm::vec3{faces[4][idx3].x, faces[4][idx3].y, faces[4][idx3].z});
				v4 = (glm::vec3{faces[4][idx2].x, faces[4][idx2].y, faces[4][idx2].z});
				
				if(this->n_norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1*size);
				a2.push_back(v2*size);
				a3.push_back(v3*size);
				a4.push_back(v4*size);
				//drawQuad(v1, v2, v3, v4);
				
				// Right face
				//glColor3f( 0.0f, 1.0f, 1.0f); // Cyan
				v1 = (glm::vec3{faces[5][idx0].x, faces[5][idx0].y, faces[5][idx0].z});
				v2 = (glm::vec3{faces[5][idx1].x, faces[5][idx1].y, faces[5][idx1].z});
				v3 = (glm::vec3{faces[5][idx3].x, faces[5][idx3].y, faces[5][idx3].z});
				v4 = (glm::vec3{faces[5][idx2].x, faces[5][idx2].y, faces[5][idx2].z});
				
				if(this->n_norm) {
					normalizeQuad(&v1); normalizeQuad(&v2); normalizeQuad(&v3); normalizeQuad(&v4);
				}
				a1.push_back(v1*size);
				a2.push_back(v2*size);
				a3.push_back(v3*size);
				a4.push_back(v4*size);
				//drawQuad(v1, v2, v3, v4);
			}
		}
		std::vector<std::vector<glm::vec3>> faceVecPoints = {a1, a2, a3, a4};
		return faceVecPoints;
	}
	
	void NodeCube::drawCube(std::vector<std::vector<glm::vec3>> v0) {
	
		//std::cout << "test: " << v1[0].x << ", " << v1[0].y << ", " << v1[0].z << std::endl;
		std::vector<glm::vec3> v1 = v0[0];
		std::vector<glm::vec3> v2 = v0[1];
		std::vector<glm::vec3> v3 = v0[2];
		std::vector<glm::vec3> v4 = v0[3];
		
		int line_cnt = 0;
		GLfloat h_step = 0.0f;
		GLfloat v_step = 0.0f;
	
		for(int i = 0; i < (int)v1.size(); i++) {
			//glBegin(GL_QUADS);
			/*switch(i%6) {
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
			}*/
			//draw texture
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glBegin(GL_QUADS);			
			glTexCoord2f(0.0f+v_step, 0.1f+h_step); glVertex3f(v1[i].x, v1[i].y, v1[i].z);
			glTexCoord2f(0.1f+v_step, 0.1f+h_step); glVertex3f(v2[i].x, v2[i].y, v2[i].z);
			glTexCoord2f(0.1f+v_step, 0.0f+h_step); glVertex3f(v3[i].x, v3[i].y, v3[i].z);
			glTexCoord2f(0.0f+v_step, 0.0f+h_step); glVertex3f(v4[i].x, v4[i].y, v4[i].z);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			
			line_cnt++;
			if(line_cnt >= 10) {
				v_step += 0.1f;
				h_step = 0.0f;
				line_cnt = 0;
			} else {
				h_step += 0.1f;
			}
			
			
			
			/*glVertex3f(v1[i].x, v1[i].y, v1[i].z);
			glVertex3f(v2[i].x, v2[i].y, v2[i].z);
			glVertex3f(v3[i].x, v3[i].y, v3[i].z);
			glVertex3f(v4[i].x, v4[i].y, v4[i].z);
			glEnd();*/
			
			/*glLineWidth(1.0f);
			glColor3f(0.25f, 0.33f, 0.12f);
			glBegin(GL_LINE_LOOP);
			glVertex3f(v1[i].x, v1[i].y, v1[i].z);
			glVertex3f(v2[i].x, v2[i].y, v2[i].z);
			glVertex3f(v3[i].x, v3[i].y, v3[i].z);
			glVertex3f(v4[i].x, v4[i].y, v4[i].z);
			glEnd();*/
		}		
		glFlush();
	}
	
	void NodeCube::normalizeQuad(glm::vec3 *v) {
		GLfloat length = sqrt(v->x*v->x + v->y*v->y + v->z*v->z);
		v->x /= length;
		v->y /= length;
		v->z /= length;
	}

	void NodeCube::printVertices(std::vector<glm::vec3> fc, std::string name) {
		std::cout << "Print vertices points for " << name << std::endl;
		
		for(int i = 0; i < (int)fc.size(); i++) {
			std::cout << "{" << fc[i].x << ", " << fc[i].y << ", " << fc[i].z << "}" << std::endl;
		}
		
		std::cout << "Vertices done" << std::endl;
	}
	
	GLuint NodeCube::loadTexture(const char* filename) {
		// Load image using STB
		int width, height, channels;
		unsigned char* image = stbi_load(filename, &width, &height, &channels, STBI_rgb);
		
		std::cout << "Loading texture " << filename << std::endl;

		if (image == nullptr) {
		    // Error handling
		    std::cout << "Image nullptr error" << std::endl;
		    return (GLuint)NULL;
		}

		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		
		// Set texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

		stbi_image_free(image);
		
		std::cout << "texutre id: " << textureID << ", width[" << width << "], height[" << height << "], channels[" << channels << "]" << std::endl;
		
		return textureID;
    }
}
