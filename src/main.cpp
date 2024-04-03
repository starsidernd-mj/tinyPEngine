#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer.hpp"

//using namespace tinypengine;

int main() {
    tinypengine::Renderer renderer(800, 600, "TinyPEngine");
    
    if(!renderer.init()) {
    	return -1;
    }
    
    renderer.renderLoop();
    renderer.cleanup();
    
    return 0;
}
