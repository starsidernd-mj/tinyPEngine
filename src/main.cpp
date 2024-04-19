#include <iostream>
#include "Renderer.hpp"

tinypengine::Renderer *renderer;

int GAME_WIDTH = 800;
int GAME_HEIGHT = 600;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	GLfloat cameraSpeed = 0.5f;
	
	if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
	    renderer->cameraPosition += cameraSpeed * renderer->cameraDirection;
	    //std::cout << "Pressed key W" << std::endl;
	}
	if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
	    renderer->cameraPosition -= cameraSpeed * renderer->cameraDirection;
	    //std::cout << "Pressed key S" << std::endl;
	}
	if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
	    renderer->cameraPosition += cameraSpeed * renderer->cameraRight;
	    //std::cout << "Pressed key A" << std::endl;
	}
	if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
	    renderer->cameraPosition -= cameraSpeed * renderer->cameraRight;
	    //std::cout << "Pressed key D" << std::endl;
	}
	if (key == GLFW_KEY_Q && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		renderer->cameraPosition += cameraSpeed * renderer->cameraUp;
		//std::cout << "Pressed key Q" << std::endl;
	}
	if (key == GLFW_KEY_Z && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		renderer->cameraPosition -= cameraSpeed * renderer->cameraUp;
		//std::cout << "Pressed key Z" << std::endl;
	}
	if (key == GLFW_KEY_ESCAPE && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		renderer->escape = true;
		//std::cout << "Pressed key esc" << std::endl;
	}
	
	//std::cout << "Position: " << renderer->cameraPosition[0] << ", " << renderer->cameraPosition[1] << ", " << renderer->cameraPosition[2] << std::endl;
	//std::cout << "Position: " << renderer->cameraPosition << std::endl;
	/*std::cout << "View matrix: " << renderer->view[0][0] << ", " << 
									renderer->view[0][1] << ", " <<
									renderer->view[0][2] << ", " << 
									renderer->view[1][0] << ", " << 
									renderer->view[1][1] << ", " <<
									renderer->view[1][2] << ", " <<
									renderer->view[2][0] << ", " <<
									renderer->view[2][1] << ", " <<
									renderer->view[2][2] << ", " << std::endl;*/
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
	if(renderer->firstMouse) {
		renderer->lastX = GAME_WIDTH/2;
		renderer->lastY = GAME_HEIGHT/2;
		renderer->firstMouse = false;
	}
	
	GLfloat xoffset = xpos - renderer->lastX;
	GLfloat yoffset;
	if(renderer->mouseInvert) {
		yoffset = ypos - renderer->lastY;
	} else {
		yoffset = renderer->lastY - ypos;
	}
	renderer->lastX = xpos;
	renderer->lastY = ypos;
	
	xoffset *= renderer->cameraSensitivity;
	yoffset *= renderer->cameraSensitivity;
	
	renderer->yaw += xoffset;
	renderer->pitch += yoffset;
	
	if(renderer->pitch > 89.0f) renderer->pitch = 89.0f;
	if(renderer->pitch < -89.0f) renderer->pitch = -89.0f;
	
	//std::cout << "Pitch: " << renderer->pitch << ", Yaw: " << renderer->yaw << std::endl;
}
	
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	renderer->fov -= (float)yoffset;
	if(renderer->fov < 1.0f)
		renderer->fov = 1.0f;
	if(renderer->fov > 45.0f)
		renderer->fov = 45.0f;
}

int main(int argc, char** argv) {
	renderer = new tinypengine::Renderer(GAME_WIDTH, GAME_HEIGHT, "TinyPEngine test1", argc, argv);	
    
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
    
    //renderer->s_drawCube();
    renderer->renderLoop();
    renderer->cleanup();
    
    return 0;
}

