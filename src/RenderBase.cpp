
#include "RenderBase.hpp"

namespace tinypengine {

	static void error_callback(int error, const char* desc) {
		std::cerr << "Error: " << desc << std::endl;
	}

	bool RenderBase::init() {
		// set error callback
		glfwSetErrorCallback(error_callback);
		
		// Set callbacks
		set_callbacks();
	
		//init GLFW
		if(!glfwInit()) {
			std::cerr << "Failed to init GLFW" << std::endl;
			return -1;
		}
		
		//create a window and openGL context
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if(!m_window) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		
		//Make windows context current
		glfwMakeContextCurrent(m_window);
		
		//Init GLEW
		GLenum err = glewInit();
		if(err != GLEW_OK) {
			std::cerr << "Failed to initialie GLEW" << std::endl;
			return -1;
		}
		
		//ensure we can capture inputs
		glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		
		//enable depth test
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		
		//Create camera
		camera = new Camera(m_width, m_height);
		
		// Create root Node
		rootNode = new Node("root");

		return 1;		
	}

	void RenderBase::renderLoop() {
		// Loop until the user closes the window
		while(!glfwWindowShouldClose(m_window) && !escape) {
			// Poll for and process events
			glfwPollEvents();
			
			if(escape)
				break;
			
			// Update logic
			update();
			
			// Update camera vectors
			camera->updateVectors();
			
			// Render here
			render();
			camera->render();
			
			// Draw cube
			//s_drawCube();
			
			// Draw root Node
			rootNode->draw();
			
			// Swap front and back buffers
			glfwSwapBuffers(m_window);
		}
	}
	
	void RenderBase::cleanup() {
		glfwTerminate();
	}
	
	void RenderBase::update() {}
	
	void RenderBase::render() {}
	
	void RenderBase::debugTest() {}
	
	void RenderBase::set_callbacks() {}
	
	void RenderBase::processInput() {}
	
	GLFWwindow* RenderBase::getWindow() {
		return m_window;
	}

	void RenderBase::s_drawCube() {
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



