#include <iostream>
#include "Renderer.hpp"

//using namespace tinypengine;

tinypengine::Renderer *renderer;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	GLfloat cameraSpeed = 0.05f;
	GLfloat camPos[3] = {0, 0, 0};
	
	camPos[0] = renderer->cameraPosition[0];
	camPos[1] = renderer->cameraPosition[1];
	camPos[2] = renderer->cameraPosition[2];
	
	
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
	    camPos[2] -= cameraSpeed;
	    std::cout << "Pressed key W" << std::endl;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
	    camPos[2] += cameraSpeed;
	    std::cout << "Pressed key S" << std::endl;
	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
	    camPos[0] -= cameraSpeed;
	    std::cout << "Pressed key A" << std::endl;
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
	    camPos[0] += cameraSpeed;
	    std::cout << "Pressed key D" << std::endl;
	}
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
	//glfwSetCursorPosCallback(renderer->m_window, renderer->mouse_callback);
	
	// set keyboard callback
	glfwSetKeyCallback(renderer->getWindow(), key_callback);
    
    //renderer.s_drawCube();
    renderer->renderLoop();
    renderer->cleanup();
    
    return 0;
}

