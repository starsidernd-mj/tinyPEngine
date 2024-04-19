
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

namespace tinypengine {

	class RenderBase {			
	public:
		RenderBase(int width, int height, const char* title, int argc, char** argv) : m_width(width), m_height(height), m_title(title), m_window(nullptr), m_argc(argc), m_argv(argv) {};
		
		bool init();
		void renderLoop();
		void cleanup();
		
		void updateVectors();
		
		virtual void update();
		virtual void render();
		virtual void debugTest();
		virtual void set_callbacks();
		void s_drawCube();
		
		glm::vec3 up 				= glm::vec3(0.0f, 1.0f, 0.0f);
		
		glm::vec3 cameraPosition 	= glm::vec3(0.0f, 0.0f, 10.0f);
		glm::vec3 cameraDirection 	= glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraUp 			= glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cameraRight 		= glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cameraFront		= glm::vec3(0.0f, 0.0f, 0.0f);
		
		float cameraSpeed = 0.05f;
		float cameraSensitivity = 0.05f;
		bool mouseInvert = false;
		glm::mat4 view;
		
		GLfloat pitch = 0.0f;
		GLfloat yaw = -90.0f;
		GLfloat fov = 45.0f;
		
		GLfloat lastX= 400, lastY = 300;
		bool firstMouse = true;
		
		void processInput();
		
		GLFWwindow* getWindow();
		bool escape = false;
		
	private:
		
	protected:
		int m_width;
		int m_height;
		const char* m_title;
		GLFWwindow* m_window;
		int m_argc;
		char** m_argv;
	};
}
