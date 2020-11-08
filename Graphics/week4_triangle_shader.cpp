#include <GL/glew.h>
#include <GL/freeglut.h>

GLuint vbo;
GLuint posLoc;


void myInit()
{
	GLuint program = glCreateProgram();

	GLuint vsh = glCreateShader(GL_VERTEX_SHADER);

	const char*vshCode = "#version 120\n\
				  attribute vec3 pos;\n\
				 void main( )\n\
	 				  {\n\
					  		gl_Position = vec4(pos, 1);\n\
	 				  }";
	GLint length = strlen(vshCode);
	glShaderSource(vsh, 1, &vshCode, &length);
	glCompileShader(vsh);
	glAttachShader(program, vsh);

	GLuint fsh = glCreateShader(GL_FRAGMENT_SHADER);

	const char*fshCode = "#version 120\n\
				 void main( )\n\
	 				  {\n\
					        gl_FragColor = vec4(0,0,1,1);\n\
	 				  }";

	length = strlen(fshCode);
	glShaderSource(fsh, 1, &fshCode, &length);
	glCompileShader(fsh);
	glAttachShader(program, fsh);


	glValidateProgram(program);
	glLinkProgram(program);
	glUseProgram(program);


	posLoc = glGetAttribLocation(program, "pos");



	float vertices[] = { -1, -1, 0, 1, -1, 0, 0, 1, 0 };
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(posLoc);


	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);


	glDisableVertexAttribArray(posLoc);
	glutSwapBuffers();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow(argv[0]);

	glewInit();
	myInit();

	glutDisplayFunc(myDisplay);

	glutMainLoop();
}
