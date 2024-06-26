#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "RenderBase.hpp"

namespace tinypengine {

	class Renderer : public RenderBase {
	public:
		Renderer(int width, int height, const char* title, int argv, char** argc);
	
		virtual void update() override;
		virtual void render() override;
		virtual void debugTest() override;
		virtual void set_callbacks() override;
	};
}

#endif
