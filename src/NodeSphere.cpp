
#include "NodeSphere.hpp"

namespace tinypengine {

	NodeSphere::NodeSphere(const std::string& name, glm::vec3 pos) : NodeCube(name, pos) {
		init(name);
		this->n_position = pos;
	};
	
	NodeSphere::~NodeSphere() {}
	
	/*void NodeSphere::init() {
		this->name = name;
		std::cout << "\tCreating NodeSphere[" << name << "]" << std::endl;
		
		faces = generateVertices(10);
		debugPoints = generateFaces(faces, 2.0f, true);
		std::cout << "Generating " << faces[0].size() << " vertices" << std::endl;
	}*/

	void NodeSphere::update() {}
	
	void NodeSphere::draw() {
		// draw children
		drawCube(debugPoints);
	
		for(Node* i : n_children) {
			//std::cout << "Drawing node " << i->name << std::endl;
			i->draw();
		}
	}
}
