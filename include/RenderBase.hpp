#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "Camera.hpp"
#include "Node.hpp"

namespace tinypengine {

	class RenderBase {			
	public:
		RenderBase(int width, int height, const char* title, int argc, char** argv) : m_width(width), m_height(height), m_title(title), m_window(nullptr), m_argc(argc), m_argv(argv) {};
		
		bool init();
		void renderLoop();
		void cleanup();
		
		void updateVectors();
		
		virtual void update();
		virtual void render();
		virtual void debugTest();
		virtual void set_callbacks();
		
		void s_drawCube();
		void processInput();
		
		GLFWwindow* getWindow();
		bool escape = false;
		
		Camera *camera;
		
		Node* getRootNode();
		
	private:
		Node *rootNode;
		
	protected:
		int m_width;
		int m_height;
		const char* m_title;
		GLFWwindow* m_window;
		int m_argc;
		char** m_argv;
	};
}
