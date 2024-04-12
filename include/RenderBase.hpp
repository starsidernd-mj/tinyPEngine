
#include <GL/glew.h>
//#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <iostream>
#include <algorithm>

namespace tinypengine {

	class RenderBase {			
	public:
		RenderBase(int width, int height, const char* title, int argc, char** argv) : m_width(width), m_height(height), m_title(title), m_window(nullptr), m_argc(argc), m_argv(argv) {};
		
		bool init();
		void renderLoop();
		void cleanup();
		
		virtual void render();
		virtual void debugTest();
		virtual void set_callbacks();
		
		GLfloat cameraPosition[3] = {0.0f, 0.0f, 5.0f};
		GLfloat cameraRotation[3] = {0.0f, 0.0f, 0.0f};
		
		GLfloat lastX= 400, lastY = 300;
		bool firstMouse = true;
		
		void processInput();
		
		GLFWwindow* getWindow();
		bool escape = false;
		
	private:
		
	protected:
		int m_width;
		int m_height;
		const char* m_title;
		GLFWwindow* m_window;
		int m_argc;
		char** m_argv;
	};
}
