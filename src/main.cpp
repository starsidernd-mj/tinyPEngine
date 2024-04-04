#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer.hpp"

//using namespace tinypengine;

int main(int argc, char** argv) {
	//glutInit(&argc, argv);
	tinypengine::Renderer renderer(800, 600, "TinyPEngine", argc, argv);
    renderer.debugTest();
    
    if(!renderer.init()) {
    	return -1;
    }
    
    renderer.renderLoop();
    renderer.cleanup();
    
    return 0;
}

