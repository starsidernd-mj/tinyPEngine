#include <iostream>
#include "Renderer.hpp"

//using namespace tinypengine;

int main(int argc, char** argv) {
	tinypengine::Renderer renderer(800, 600, "TinyPEngine test1", argc, argv);
	//tinypengine::Renderer *renderer = new tinypengine::Renderer(800, 600, "TinyPEngine test1", argc, argv);
	//Renderer *renderer = new Renderer(800, 600, "TinyPEngine test1", argc, argv);
	
    
    if(!renderer.init()) {
    	return -1;
    }
    
    // set error callback
	//glfwSetErrorCallback(renderer->error_callback);
	
	// set mouse movement callback
	//glfwSetCursorPosCallback(renderer->m_window, renderer->mouse_callback);
	
	// set keyboard callback
	//glfwSetKeyCallback(renderer->m_window, renderer->key_callback);
    
    //renderer.s_drawCube();
    renderer.renderLoop();
    renderer.cleanup();
    
    return 0;
}

