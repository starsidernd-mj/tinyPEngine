#include <iostream>
#include "Renderer.hpp"

//using namespace tinypengine;

int main(int argc, char** argv) {
	tinypengine::Renderer renderer(800, 600, "TinyPEngine test1", argc, argv);
    
    if(!renderer.init()) {
    	return -1;
    }
    
    //renderer.s_drawCube();
    renderer.renderLoop();
    renderer.cleanup();
    
    return 0;
}

