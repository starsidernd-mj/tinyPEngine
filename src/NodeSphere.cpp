
#include "NodeSphere.hpp"

namespace tinypengine {

	NodeSphere::NodeSphere(const std::string& name, glm::vec3 pos) : Node(name, pos) {};

	void NodeSphere::update() {}
	
	void NodeSphere::draw() {
		glColor3f( 1.0f, 0.0f, 0.0f);
		drawIcosphere(2.0f, 16);
	}

	void NodeSphere::drawTriangle(GLfloat* v1, GLfloat* v2, GLfloat* v3) {
		glBegin(GL_TRIANGLES);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glEnd();
	}

	void NodeSphere::normalize(GLfloat* v) {
		GLfloat length = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
		v[0] /= length;
		v[1] /= length;
		v[2] /= length;
	}

	void NodeSphere::drawIcosphere(float radius, int subdivisions) {
		const float t = (1.0f + sqrt(5.0f)) / 2.0f;

		GLfloat vertices[12][3] = {
		    {-1, t, 0}, {1, t, 0}, {-1, -t, 0}, {1, -t, 0},
		    {0, -1, t}, {0, 1, t}, {0, -1, -t}, {0, 1, -t},
		    {t, 0, -1}, {t, 0, 1}, {-t, 0, -1}, {-t, 0, 1}
		};

		int faces[20][3] = {
		    {0, 11, 5}, {0, 5, 1}, {0, 1, 7}, {0, 7, 10}, {0, 10, 11},
		    {1, 5, 9}, {5, 11, 4}, {11, 10, 2}, {10, 7, 6}, {7, 1, 8},
		    {3, 9, 4}, {3, 4, 2}, {3, 2, 6}, {3, 6, 8}, {3, 8, 9},
		    {4, 9, 5}, {2, 4, 11}, {6, 2, 10}, {8, 6, 7}, {9, 8, 1}
		};

		for (int i = 0; i < 20; i++) {
		    GLfloat v1[3] = { vertices[faces[i][0]][0], vertices[faces[i][0]][1], vertices[faces[i][0]][2] };
		    GLfloat v2[3] = { vertices[faces[i][1]][0], vertices[faces[i][1]][1], vertices[faces[i][1]][2] };
		    GLfloat v3[3] = { vertices[faces[i][2]][0], vertices[faces[i][2]][1], vertices[faces[i][2]][2] };

		    normalize(v1);
		    normalize(v2);
		    normalize(v3);

		    drawTriangle(v1, v2, v3);
		}
	}


}
