#include <iostream>
#include "Renderer.hpp"

//using namespace tinypengine;

tinypengine::Renderer *renderer;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	GLfloat cameraSpeed = 0.05f;
	
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
	    renderer->cameraPosition[2] -= cameraSpeed;
	    std::cout << "Pressed key W" << std::endl;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
	    renderer->cameraPosition[2] += cameraSpeed;
	    std::cout << "Pressed key S" << std::endl;
	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
	    renderer->cameraPosition[0] -= cameraSpeed;
	    std::cout << "Pressed key A" << std::endl;
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
	    renderer->cameraPosition[0] += cameraSpeed;
	    std::cout << "Pressed key D" << std::endl;
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		renderer->escape = true;
		std::cout << "Pressed key esc" << std::endl;
	}
	
	std::cout << "Position: " << renderer->cameraPosition[0] << ", " << renderer->cameraPosition[1] << ", " << renderer->cameraPosition[2] << std::endl;
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
		if(renderer->firstMouse) {
			renderer->lastX = xpos;
			renderer->lastY = ypos;
			renderer->firstMouse = false;
		}
		
		GLfloat xoffset = xpos - renderer->lastX;
		GLfloat yoffset = ypos - renderer->lastY;
		renderer->lastX = xpos;
		renderer->lastY = ypos;
		
		GLfloat sensitivity = 0.05f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;
		
		renderer->cameraRotation[0] += yoffset;
		renderer->cameraRotation[1] += xoffset;
		
		if(renderer->cameraRotation[0] > 89.0f) renderer->cameraRotation[0] = 89.0f;
		if(renderer->cameraRotation[1] < -89.0f) renderer->cameraRotation[1] = -89.0f;
		
		std::cout << "Rotation: " << renderer->cameraRotation[0] << ", " << renderer->cameraRotation[1] << std::endl;
	}

int main(int argc, char** argv) {
	//tinypengine::Renderer renderer(800, 600, "TinyPEngine test1", argc, argv);
	//tinypengine::Renderer *renderer = new tinypengine::Renderer(800, 600, "TinyPEngine test1", argc, argv);
	//Renderer *renderer = new Renderer(800, 600, "TinyPEngine test1", argc, argv);
	
	renderer = new tinypengine::Renderer(800, 600, "TinyPEngine test1", argc, argv);
	
    
    if(!renderer->init()) {
    	return -1;
    }
    
    // set error callback
	//glfwSetErrorCallback(renderer->error_callback);
	
	// set mouse movement callback
	glfwSetCursorPosCallback(renderer->getWindow(), mouse_callback);
	
	// set keyboard callback
	glfwSetKeyCallback(renderer->getWindow(), key_callback);
    
    //renderer.s_drawCube();
    renderer->renderLoop();
    renderer->cleanup();
    
    return 0;
}

