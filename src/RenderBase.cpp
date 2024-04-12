
#include "RenderBase.hpp"

namespace tinypengine {

/*static void key_callback2(GLFWwindow *window, int key, int scancode, int action, int mods) {
	GLfloat cameraSpeed = 0.05f;
	
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		std::cout << "W Key pressed" << std::endl;
	    cameraPosition[2] -= cameraSpeed;
    }	
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		std::cout << "S Key pressed" << std::endl;
	    cameraPosition[2] += cameraSpeed;
    }
	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		std::cout << "A Key pressed" << std::endl;
	    cameraPosition[0] -= cameraSpeed;
    }
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		std::cout << "D Key pressed" << std::endl;
	    cameraPosition[0] += cameraSpeed;
	}
}*/

	static void error_callback(int error, const char* desc) {
		std::cerr << "Error: " << desc << std::endl;
	}
	
	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
		GLfloat cameraSpeed = 0.05f;
		GLfloat camPos[3] = {0, 0, 0};
		//std::copy(std::begin(RenderBase::cameraPosition), std::end(RenderBase::cameraPosition));
		//std::begin(camPos);
		
		camPos[0] = RenderBase::cameraPosition[0];
		camPos[1] = RenderBase::cameraPosition[1];
		camPos[2] = RenderBase::cameraPosition[2];
		
		
		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		    camPos[2] -= cameraSpeed;
		if (key == GLFW_KEY_S && action == GLFW_PRESS)
		    camPos[2] += cameraSpeed;
		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		    camPos[0] -= cameraSpeed;
		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		    camPos[0] += cameraSpeed;
	}
	
	void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
		if(RenderBase::firstMouse) {
			RenderBase::lastX = xpos;
			RenderBase::lastY = ypos;
			RenderBase::firstMouse = false;
		}
		
		GLfloat xoffset = xpos - RenderBase::lastX;
		GLfloat yoffset = ypos - RenderBase::lastY;
		RenderBase::lastX = xpos;
		RenderBase::lastY = ypos;
		
		GLfloat sensitivity = 0.05f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;
		
		RenderBase::cameraRotation[0] += yoffset;
		RenderBase::cameraRotation[1] += xoffset;
		
		if(RenderBase::cameraRotation[0] > 89.0f) RenderBase::cameraRotation[0] = 89.0f;
		if(RenderBase::cameraRotation[1] < -89.0f) RenderBase::cameraRotation[1] = -89.0f;
	}

	bool RenderBase::init() {
		cameraPosition[0] = 0.0f;
		cameraPosition[1] = 0.0f;
		cameraPosition[2] = 5.0f;
		cameraRotation[0] = 0.0f;
		cameraRotation[1] = 0.0f;
		cameraRotation[2] = 0.0f;
		
		lastX = 400;
		lastY = 300;
		firstMouse = true;
		
		// set error callback
		glfwSetErrorCallback(error_callback);
		
		// set mouse movement callback
		glfwSetCursorPosCallback(m_window, mouse_callback);
		
		// set keyboard callback
		glfwSetKeyCallback(m_window, key_callback);
		
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
		
		//enable depth test
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		return 1;		
	}

	void RenderBase::renderLoop() {
		// Loop until the user closes the window
		while(!glfwWindowShouldClose(m_window)) {
			// Poll for and process events
			glfwPollEvents();
			
			// Render here
			render();
			
			// Swap front and back buffers
			glfwSwapBuffers(m_window);
		}
	}
	
	void RenderBase::cleanup() {
		glfwTerminate();
	}
	
	void RenderBase::render() {}
	
	void RenderBase::debugTest() {}
	
	void RenderBase::set_callbacks() {}
	
	/*void RenderBase::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
		GLfloat cameraSpeed = 0.05f;
		
		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		    cameraPosition[2] -= cameraSpeed;
		if (key == GLFW_KEY_S && action == GLFW_PRESS)
		    cameraPosition[2] += cameraSpeed;
		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		    cameraPosition[0] -= cameraSpeed;
		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		    cameraPosition[0] += cameraSpeed;
	}
	
	void RenderBase::mouse_callback(GLFWwindow *window, double xpos, double ypos) {
		if(firstMouse) {
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}
		
		GLfloat xoffset = xpos - lastX;
		GLfloat yoffset = ypos - lastY;
		lastX = xpos;
		lastY = ypos;
		
		GLfloat sensitivity = 0.05f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;
		
		cameraRotation[0] += yoffset;
		cameraRotation[1] += xoffset;
		
		if(cameraRotation[0] > 89.0f) cameraRotation[0] = 89.0f;
		if(cameraRotation[1] < -89.0f) cameraRotation[1] = -89.0f;
	}*/
	
	/*void RenderBase::error_callback(int error, const char* desc) {
		std::cerr << "Error: " << desc << std::endl;
	}*/
	
	void RenderBase::processInput() {
		GLfloat cameraSpeed = 0.05f;
		
		if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
		    cameraPosition[2] -= cameraSpeed;
		if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
		    cameraPosition[2] += cameraSpeed;
		if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
		    cameraPosition[0] -= cameraSpeed;
		if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
		    cameraPosition[0] += cameraSpeed;
	}

}



