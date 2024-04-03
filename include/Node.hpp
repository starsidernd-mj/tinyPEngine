
#include <vector>

namespace tinypengine {

	class Node {
	private:
		std::vector<Node*> m_children;
	
	
	public:
		Node();
		virtual ~Node();
		
		
	
	};
}
