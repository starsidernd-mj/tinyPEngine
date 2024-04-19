
#include "Renderer.hpp"

namespace tinypengine {

	Renderer::Renderer(int width, int height, const char* title, int argc, char** argv) : RenderBase(width, height, title, argc, argv) {};

	void Renderer::update() {}

	void Renderer::render() {
		
		// Clear color buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		
		// Set up the viewport
		glViewport(0, 0, m_width, m_height);
		
		// Set up projection matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective((float)fov, (float)m_width / (float)m_height, 0.1f, 100.0f);
		
		// Set up modelview matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		// Look in the direction of the cameraTarget from the cameraPosition, with reference to cameraUp
		gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z, cameraFront.x, cameraFront.y, cameraFront.z, cameraUp.x, cameraUp.y, cameraUp.z);
	}
	
	void Renderer::debugTest() {
		std::cout << "Debug from Renderer" << std::endl;
	}
	
	void Renderer::set_callbacks() {
		std::cout << "Setting callbacks" << std::endl;
		
		// set error callback
		//glfwSetErrorCallback(error_callback);
	
		// set mouse movement callback
		//glfwSetCursorPosCallback(m_window, mouse_callback);
	
		// set keyboard callback
		//glfwSetKeyCallback(m_window, key_callback);
	
		std::cout << "Callbacks set" << std::endl;
	}

}
