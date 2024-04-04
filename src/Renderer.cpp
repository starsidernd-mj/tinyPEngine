
#include "Renderer.hpp"

namespace tinypengine {

	Renderer::Renderer(int width, int height, const char* title) : RenderBase(width, height, title) {};

	void Renderer::render() {
		
	}
	
	void Renderer::debugTest() {
		std::cout << "Debug from Renderer" << std::endl;
	}

}
