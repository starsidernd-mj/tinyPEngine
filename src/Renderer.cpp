
#include "Renderer.hpp"

namespace tinypengine {

	bool Renderer::init() {
		//Init GLFW
		if(!glfwInit()) {
			std::cerr << "Failed to init GLFW" << std::endl;
			return false;
		}
		
		// Create a windowed mode window and its OpenGL context
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if(!m_window) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		
		// Make the window's context current
		glfwMakeContextCurrent(m_window);
		
		// Init GLEW
		GLenum err = glewInit();
		if(err != GLEW_OK) {
			std::cerr << "Failed to init GLEW: " << glewGetErrorString(err) << std::endl;
			glfwTerminate();
			return false;
		}
		
		// Enable depth testing
		glEnable(GL_DEPTH_TEST);
		
		return true;
	}
	
	void Renderer::renderLoop() {
		// Loop until the user closes the window
		while(!glfwWindowShouldClose(m_window)) {
			// Render here
			
			// Swap front and back buffers
			glfwSwapBuffers(m_window);
			
			// Poll for and process events
			glfwPollEvents();
		}
	}
	
	void Renderer::cleanup() {
		glfwTerminate();
	}

}
