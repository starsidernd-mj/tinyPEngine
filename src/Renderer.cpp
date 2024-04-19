
#include "Renderer.hpp"

namespace tinypengine {

	Renderer::Renderer(int width, int height, const char* title, int argc, char** argv) : RenderBase(width, height, title, argc, argv) {};

	void Renderer::update() {}
	
	void Renderer::render() {}
	
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
