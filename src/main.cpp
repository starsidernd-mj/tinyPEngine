#include <iostream>
#include "Renderer.hpp"
//#include "Camera.hpp"
//#include "NodeSphere.hpp"

tinypengine::Renderer *renderer;
tinypengine::Camera *camera;
tinypengine::Node *rootNode;

int GAME_WIDTH = 800;
int GAME_HEIGHT = 600;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	
	if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
	    renderer->camera->Position += renderer->camera->Speed * renderer->camera->Direction;
	    //std::cout << "Pressed key W" << std::endl;
	}
	if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
	    renderer->camera->Position -= renderer->camera->Speed * renderer->camera->Direction;
	    //std::cout << "Pressed key S" << std::endl;
	}
	if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
	    renderer->camera->Position += renderer->camera->Speed * renderer->camera->Right;
	    //std::cout << "Pressed key A" << std::endl;
	}
	if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
	    renderer->camera->Position -= renderer->camera->Speed * renderer->camera->Right;
	    //std::cout << "Pressed key D" << std::endl;
	}
	if (key == GLFW_KEY_Q && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		renderer->camera->Position += renderer->camera->Speed * renderer->camera->Up;
		//std::cout << "Pressed key Q" << std::endl;
	}
	if (key == GLFW_KEY_Z && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		renderer->camera->Position -= renderer->camera->Speed * renderer->camera->Up;
		//std::cout << "Pressed key Z" << std::endl;
	}
	if (key == GLFW_KEY_ESCAPE && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		renderer->escape = true;
		//std::cout << "Pressed key esc" << std::endl;
	}
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
	if(renderer->camera->firstMouse) {
		renderer->camera->lastX = GAME_WIDTH/2;
		renderer->camera->lastY = GAME_HEIGHT/2;
		renderer->camera->firstMouse = false;
	}
	
	GLfloat xoffset = xpos - renderer->camera->lastX;
	GLfloat yoffset;
	if(renderer->camera->mouseInvert) {
		yoffset = ypos - renderer->camera->lastY;
	} else {
		yoffset = renderer->camera->lastY - ypos;
	}
	renderer->camera->lastX = xpos;
	renderer->camera->lastY = ypos;
	
	xoffset *= renderer->camera->Sensitivity;
	yoffset *= renderer->camera->Sensitivity;
	
	renderer->camera->yaw += xoffset;
	renderer->camera->pitch += yoffset;
	
	if(renderer->camera->pitch > 89.0f) renderer->camera->pitch = 89.0f;
	if(renderer->camera->pitch < -89.0f) renderer->camera->pitch = -89.0f;
	
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	renderer->camera->fov -= (float)yoffset;
	if(renderer->camera->fov < 1.0f)
		renderer->camera->fov = 1.0f;
	if(renderer->camera->fov > 45.0f)
		renderer->camera->fov = 45.0f;
}

void init() {
	rootNode = renderer->getRootNode();
	
	tinypengine::Node *debugNode = new tinypengine::Node("debug", glm::vec3(0, 0, 0));
	debugNode->debug = true;
	rootNode->addNode(debugNode);
	
	//tinypengine::Node *testNode = new tinypengine::Node("test", glm::vec3(1, 1, 1));
	//testNode->debug = true;
	//rootNode->addNode(testNode);
	
	//tinypengine::NodeSphere *ball = new tinypengine::NodeSphere("ball", glm::vec3(5, 5, 5));
	//rootNode->addNode(ball);
}

int main(int argc, char** argv) {
	renderer = new tinypengine::Renderer(GAME_WIDTH, GAME_HEIGHT, "TinyPEngine test1", argc, argv);
	camera = renderer->camera;
    
    if(!renderer->init()) {
    	return -1;
    }
    
    // set error callback
	//glfwSetErrorCallback(renderer->error_callback);
	
	// set mouse movement callback
	glfwSetCursorPosCallback(renderer->getWindow(), mouse_callback);
	
	// set keyboard callback
	glfwSetKeyCallback(renderer->getWindow(), key_callback);
	
	// set mouse scrolling callback
	glfwSetScrollCallback(renderer->getWindow(), scroll_callback);
	
	// main init
	init();
    
    renderer->renderLoop();
    renderer->cleanup();
    
    return 0;
}

