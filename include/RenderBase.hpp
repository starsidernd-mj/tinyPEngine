
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
		
		virtual void render();
		virtual void debugTest();
		virtual void set_callbacks();
		
		GLfloat pitch = 0.0f;
		GLfloat yaw = 0.0f;
		
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 5.0f);
		glm::vec3 cameraRotation = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cameraDirection = glm::normalize(cameraTarget - cameraPosition);
		glm::vec3 cameraUp = glm::normalize(glm::cross(cameraDirection, up));
		glm::vec3 cameraRight = glm::normalize(glm::cross(cameraUp, cameraDirection));
		float cameraSpeed = 0.05f;
		glm::mat4 view;
		
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
