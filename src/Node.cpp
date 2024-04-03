
#include "Node.hpp"

namespace tinypengine {

	Node::Node(const std::string& name) {
		//initLogger();
		
		init(name);
	}

	Node::~Node() {

	}
	
	void Node::init(const std::string& name) {
		this->name = name;
		
		
	}

}
