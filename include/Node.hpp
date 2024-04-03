
#include <vector>
#include <sstream>
#include <memory>

#include <glm/glm.hpp>

namespace tinypengine {

	class Node {
	private:
		std::string name;
	
		std::vector<Node*> m_children;
	
	
	public:
		Node(const std::string& name);
		virtual ~Node();
		
		void init(const std::string& name);
	
	};
}
