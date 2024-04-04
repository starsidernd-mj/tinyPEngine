
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace tinypengine {

	class RenderBase {			
	public:
		RenderBase(int width, int height, const char* title) : m_width(width), m_height(height), m_title(title), m_window(nullptr) {};
		//RenderBase(int width, int height, const char* title);
		
		bool init();
		void renderLoop();
		void cleanup();
		
		virtual void render();
		virtual void debugTest();
		
	protected:
		int m_width;
		int m_height;
		const char* m_title;
		GLFWwindow* m_window;
		
	};
}
