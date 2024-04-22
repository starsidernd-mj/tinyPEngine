#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

namespace tinypengine {

	class Camera {			
	public:
		glm::vec3 worldUp	= glm::vec3(0.0f, 1.0f, 0.0f);
		
		glm::vec3 Position 	= glm::vec3(0.0f, 0.0f, 10.0f);
		glm::vec3 Direction = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 Up 		= glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 Right 	= glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 Front		= glm::vec3(0.0f, 0.0f, 0.0f);
		
		float Speed = 0.1f;
		float Sensitivity = 0.05f;
		bool mouseInvert = false;
		
		GLfloat near = 0.1;
		GLfloat far = 1000.0f;
		
		GLfloat pitch = 0.0f;
		GLfloat yaw = -90.0f;
		GLfloat fov = 45.0f;
		
		GLfloat lastX= 400, lastY = 300;
		bool firstMouse = true;
		
		Camera(int width, int height) : m_width(width), m_height(height) {};
		void updateVectors();
		void render();
		
	private:
	
	protected:
		int m_width;
		int m_height;
	
	};
}

#endif
