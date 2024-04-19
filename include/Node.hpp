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
	
		std::vector<Node*> m_children;
		int m_child_count = 0;
	
	
	public:
		Node(const std::string& name);
		virtual ~Node();
		
		void init(const std::string& name);
		virtual void draw();
		virtual void drawCube();
	
	};
}
