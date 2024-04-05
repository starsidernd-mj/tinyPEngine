
#include "RenderBase.hpp"

namespace tinypengine {

	bool RenderBase::init() {

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
		
		//enable depth test
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		return 1;		
	}

	void RenderBase::renderLoop() {
		// Loop until the user closes the window
		while(!glfwWindowShouldClose(m_window)) {
			// Poll for and process events
			glfwPollEvents();
			
			// Render here
			render();
			
			// Swap front and back buffers
			glfwSwapBuffers(m_window);
		}
	}
	
	void RenderBase::cleanup() {
		glfwTerminate();
	}
	
	void RenderBase::render() {}
	
	void RenderBase::debugTest() {}

}



