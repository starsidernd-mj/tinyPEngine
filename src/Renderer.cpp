
#include "Renderer.hpp"

namespace tinypengine {

	Renderer::Renderer(int width, int height, const char* title, int argv, char** argc) : RenderBase(width, height, title, argv, argc) {};

	void Renderer::render() {
		
	}
	
	void Renderer::debugTest() {
		std::cout << "Debug from Renderer" << std::endl;
	}

}
