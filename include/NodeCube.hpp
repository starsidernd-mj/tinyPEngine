#ifndef NODECUBE_H
#define NODECUBE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <glm/glm.hpp>

#include <GL/glut.h>
#include <GL/freeglut.h>

#include "Node.hpp"




namespace tinypengine {

	class NodeCube : public Node {
	private:
		std::string name;
		glm::vec3 n_position = {0.0f, 0.0f, 0.0f};
		glm::vec3 n_rotation = {0.0f, 0.0f, 0.0f};
	
		std::vector<Node*> n_children;
		bool n_norm = false;
		int n_subdiv = 1;
		float n_size = 1.0f;
		
		GLuint textureID;
	
	public:
		NodeCube(const std::string& name, glm::vec3 pos, int subdiv, float size, bool norm);
		virtual ~NodeCube();
		
		virtual void update() override;
		virtual void draw() override;
		
		void init(const std::string& name);
		
		std::vector<glm::vec3> front, back, top, bottom, left, right;
		std::vector<std::vector<glm::vec3>> faces;
		std::vector<std::vector<glm::vec3>> generateVertices(int subdivisions);
		
		std::vector<std::vector<glm::vec3>> generateFaces(std::vector<std::vector<glm::vec3>> &faces, float size, bool norm);
		void drawCube(std::vector<std::vector<glm::vec3>> v0);
		
		void normalizeQuad(glm::vec3 *v);
		void printVertices(std::vector<glm::vec3> fc, std::string name);
		
		void addNode(Node* node);
		
		bool debug = 0;
		bool firstDraw = true;
		
		std::vector<std::vector<glm::vec3>> debugPoints;
		
		GLuint loadTexture(const char* filename);
	};
}

#endif
