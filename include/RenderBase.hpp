
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace tinypengine {

	class RenderBase {			
	public:
		RenderBase(int width, int height, const char* title, int argv, char** argc) : m_width(width), m_height(height), m_title(title), m_window(nullptr), m_argv(argv), m_argc(argc) {};
		
		bool init();
		void renderLoop();
		void cleanup();
		
		virtual void render();
		virtual void debugTest();
		
		static void drawCube();
		static void display();
		static void reshape(int, int);
		
		const char* vertexShaderSource = R"(
			#version 330 core
			layout (location = 0) in vec3 aPos;
			
			void main() {
				gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
			}
		)";
		const char* fragmentShaderSource = R"(
			#version 330 core
			out vec4 FragColor;
			
			void main() {
				FragColor = vec4(1.0, 0.5, 0.2, 1.0);
			}
		)";
		
		GLuint shaderProgram;
		GLuint VBO, VAO;		
		
	protected:
		int m_width;
		int m_height;
		const char* m_title;
		GLFWwindow* m_window;
		int m_argv;
		char** m_argc;
	};
}
