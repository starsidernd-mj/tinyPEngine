#ifndef NODESPHERE_H
#define NODESPHERE_H

#include <cmath>
#include "NodeCube.hpp"

namespace tinypengine {

	class NodeSphere : public NodeCube {
	private:
		std::string name;
		glm::vec3 n_position = {0.0f, 0.0f, 0.0f};
		glm::vec3 n_rotation = {0.0f, 0.0f, 0.0f};
	
		std::vector<Node*> n_children;
		
	public:
		NodeSphere(const std::string& name, glm::vec3 pos);
		virtual ~NodeSphere();
		
		virtual void update() override;
		virtual void draw() override;
		
		virtual void init(const std::string& name) override;
		//void init(const std::string& name);
	};

}

#endif
