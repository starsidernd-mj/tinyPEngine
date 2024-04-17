
#include "RenderBase.hpp"

namespace tinypengine {

	static void error_callback(int error, const char* desc) {
		std::cerr << "Error: " << desc << std::endl;
	}

	bool RenderBase::init() {
		// set error callback
		glfwSetErrorCallback(error_callback);
		
		// Set callbacks
		set_callbacks();
	
		//init GLFW
		if(!glfwInit()) {
			std::cerr << "Failed to init GLFW" << std::endl;
			return -1;
		}
		
		//create a window and openGL context
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if(!m_window) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		
		//Make windows context current
		glfwMakeContextCurrent(m_window);
		
		//Init GLEW
		GLenum err = glewInit();
		if(err != GLEW_OK) {
			std::cerr << "Failed to initialie GLEW" << std::endl;
			return -1;
		}
		
		//ensure we can capture inputs
		glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		
		//enable depth test
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		return 1;		
	}

	void RenderBase::renderLoop() {
		// Loop until the user closes the window
		while(!glfwWindowShouldClose(m_window) && !escape) {
			// Poll for and process events
			glfwPollEvents();
			
			if(escape)
				break;
			
			// Render here
			render();
			
			// set up view matrix
			view = glm::lookAt(cameraPosition, cameraPosition + cameraDirection, cameraUp);
			
			// update cameraDirection
			cameraDirection = glm::normalize(cameraTarget - cameraPosition);
			// apply rotations to camera direction
			cameraDirection = glm::rotate(cameraDirection, glm::radians(cameraRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
			cameraDirection = glm::rotate(cameraDirection, glm::radians(cameraRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
			cameraDirection = glm::rotate(cameraDirection, glm::radians(cameraRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
			
			// update cameraTarget
			cameraTarget = cameraPosition + cameraDirection;
			
			// Swap front and back buffers
			glfwSwapBuffers(m_window);
		}
	}
	
	void RenderBase::cleanup() {
		glfwTerminate();
	}
	
	void RenderBase::render() {}
	
	void RenderBase::debugTest() {}
	
	void RenderBase::set_callbacks() {}
	
	void RenderBase::processInput() {}
	
	GLFWwindow* RenderBase::getWindow() {
		return m_window;
	}

}



