
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "RenderBase.hpp"

namespace tinypengine {

	class Renderer : public RenderBase {
	public:
		Renderer(int width, int height, const char* title);
	
		virtual void render() override;
		virtual void debugTest() override;
	};
}
