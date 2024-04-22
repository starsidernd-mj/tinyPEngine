
#include "Camera.hpp"

namespace tinypengine {

	void Camera::updateVectors() {
		// Create a vector looking forward based on yaw and pitch
		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        
        Direction = glm::normalize(front);
        // also re-calculate the Right and Up vector
        // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Right = glm::normalize(glm::cross(worldUp, Direction));
        Up    = glm::cross(Direction, Right);
        
        Front = Position + Direction;
        
	}
	
	void Camera::render() {
		
		// Clear color buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		
		// Set up the viewport
		glViewport(0, 0, m_width, m_height);
		
		// Set up projection matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective((float)fov, (float)m_width / (float)m_height, (float)near, (float)far);
		
		// Set up modelview matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		// Look in the direction of the cameraTarget from the cameraPosition, with reference to cameraUp
		gluLookAt(Position.x, Position.y, Position.z, Front.x, Front.y, Front.z, Up.x, Up.y, Up.z);
	}
	
}
