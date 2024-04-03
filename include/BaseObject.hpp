

namespace tinypengine {

	class BaseObject {
	
	private:
		bool animating;
		bool repeatAnimation = true;
		
		int frameDelay;
		uint64_t currentPose;
		int framesWaited;
		
		std::string name;
		glm::mat4x4 transformation = glm::mat4x4(1);
		glm::vec3 rotationXYZ = glm::vec3(0.0f);
		bool rotationByMatrix = false;
		
		void init(const std::string &name);
	
	
	public:
	
	};

}
