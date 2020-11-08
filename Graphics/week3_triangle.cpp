#include <GL/freeglut.h>

void function(void) {

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 0.7, 0.0);
	glColor3f(1, 0, 1);
	glVertex3f(-0.7, -0.7, 0.0);
	glColor3f(1, 1, 0);
	glVertex3f(0.7, -0.7, 0.0);
	glColor3f(1, 1, 1);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL");

	glutDisplayFunc(function);
	glutMainLoop();
}
