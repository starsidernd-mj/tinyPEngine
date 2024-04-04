
#include "RenderBase.hpp"

namespace tinypengine {

	//RenderBase::RenderBase(int width, int height, const char* title) : m_width(width), m_height(height), m_title(title), m_window(nullptr) {};

	bool RenderBase::init() {
		glutInit(&m_argv, m_argc);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutCreateWindow("tinypengine");
		glEnable(GL_DEPTH_TEST);
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		
		glutMainLoop();
		
		return true;
	}

	/*bool RenderBase::init() {
		//Init GLFW
		if(!glfwInit()) {
			std::cerr << "Failed to init GLFW" << std::endl;
			return false;
		}
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		// Create a windowed mode window and its OpenGL context
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if(!m_window) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		
		// Make the window's context current
		glfwMakeContextCurrent(m_window);
		
		// Init GLEW
		glewExperimental = true;//Not sure this is needed
		GLenum err = glewInit();
		if(err != GLEW_OK) {
			std::cerr << "Failed to init GLEW: " << glewGetErrorString(err) << std::endl;
			glfwTerminate();
			return false;
		}
		
		#ifdef OPENGL_3_3
		// Build and compile shader program
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		// Link shaders
		//GLuint shaderProgram = glCreateProgram();
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		// Delete shaders as they're linked into program and no longer needed
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		#endif
		
		// Cube
		float vertices[] = {
			// Positions
		    -0.5f, -0.5f, -0.5f,
		    0.5f, -0.5f, -0.5f,
		    0.5f,  0.5f, -0.5f,
		    0.5f,  0.5f, -0.5f,
		    -0.5f,  0.5f, -0.5f,
		    -0.5f, -0.5f, -0.5f
		};
		
		//GLuint VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// Bind vertex array object first, then bind and set vertex buffers 
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		
		
		// Enable depth testing
		glEnable(GL_DEPTH_TEST);
		
		return true;
	}*/
	
	void RenderBase::renderLoop() {
		// Loop until the user closes the window
		while(!glfwWindowShouldClose(m_window)) {
			// Poll for and process events
			glfwPollEvents();
			
			// Render here
			render();
			
			// Clear color buffer
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			
			// Draw the triangle
			glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
			
			// Swap front and back buffers
			glfwSwapBuffers(m_window);
		}
	}
	
	void RenderBase::cleanup() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteProgram(shaderProgram);
	
		glfwTerminate();
	}
	
	void RenderBase::render() {}
	
	void RenderBase::debugTest() {}
	
	void RenderBase::drawCube() {
		// Front face
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f); // Red
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glEnd();

		// Back face
		glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glEnd();

		// Top face
		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 1.0f); // Blue
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glEnd();

		// Bottom face
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f); // Yellow
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glEnd();

		// Left face
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 1.0f); // Magenta
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glEnd();

		// Right face
		glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 1.0f); // Cyan
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glEnd();
	}
	
	void RenderBase::display() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		
		gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);//camera setup
		
		drawCube();
		glutSwapBuffers();
	}
	
	void RenderBase::reshape(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
	}

}



