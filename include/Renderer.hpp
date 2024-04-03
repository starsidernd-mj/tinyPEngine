
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace tinypengine {

	class Renderer {
	private:
		GLFWwindow* m_window;
		int m_width;
		int m_height;
		const char* m_title;
			
	public:
		Renderer(int width, int height, const char* title) : m_width(width), m_height(height), m_title(title), m_window(nullptr) {};
		
		bool init();
		void renderLoop();
		void cleanup();
		
	};
}
