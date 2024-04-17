
#include "Renderer.hpp"

namespace tinypengine {

	Renderer::Renderer(int width, int height, const char* title, int argc, char** argv) : RenderBase(width, height, title, argc, argv) {};

	void Renderer::render() {
		
		// Clear color buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		
		// Apply camera rotation transformations
		//glRotatef(cameraRotation.x, 1.0f, 0.0f, 0.0f);
		//glRotatef(cameraRotation.y, 0.0f, 1.0f, 0.0f);
		//glRotatef(cameraRotation.z, 0.0f, 0.0f, 1.0f);
		//glTranslatef(-cameraPosition.x, -cameraPosition.y, -cameraPosition.z);
		
		// Set up the viewport
		glViewport(0, 0, m_width, m_height);
		
		// Set up projection matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)m_width / (float)m_height, 0.1f, 100.0f);
		
		// Set up modelview matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		// Look in the direction of the cameraTarget from the cameraPosition, with reference to cameraUp
		gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z, cameraTarget.x, cameraTarget.y, cameraTarget.z, cameraUp.x, cameraUp.y, cameraUp.z);
		
		// Draw cube
		s_drawCube();
	}
	
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
	
	void Renderer::s_drawCube() {
		//std::cout << "drawing cube" << std::endl;
		// Front face
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f); // Red
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		//glEnd();

		// Back face
		//glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		//glEnd();

		// Top face
		//glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 1.0f); // Blue
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		//glEnd();

		// Bottom face
		//glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f); // Yellow
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		//glEnd();

		// Left face
		//glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 1.0f); // Magenta
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		//glEnd();

		// Right face
		//glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 1.0f); // Cyan
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glEnd();
	}

}
