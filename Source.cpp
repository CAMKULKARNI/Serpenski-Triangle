#include <GL/glut.h>
#include <random>

struct GLPoint
{
	GLfloat x, y;
};

void drawpoint(float x, float y)
{
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	glVertex2f(x, y);
	glEnd();
}

void serpenskiGasket()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Select vertices that will form a triangle
	GLPoint T[3] = {{10, 10}, {600, 10}, {300, 600}};

	//select one point randomly
	int index = rand() % 3;

	//draw that point as a dot
	GLPoint point = T[index];
	drawpoint(point.x, point.y);

	//loop into 5000 iterations
	//	Random vertex which is not equal to point
	//	find and draw the midpoint
	//	switch the new point to the initial point for the next iteration
	//End of loop
	for (int i = 0; i < 10000; i++)
	{
		index = rand() % 3;
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawpoint(point.x, point.y);

		/*To animate uncomment the next line*/
		glFlush();
	}

	//flush the contents of the screen
	/*To show the points in one shot uncomment the next line*/
	//glFlush();
}

int main(int argc, char *argv[])
{
	//initialize GLUT using the command line arguments
	glutInit(&argc, argv);

	//Setup the size of the opengl window, display mode
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB);

	//creating the window
	glutCreateWindow("Hello World !! This is a point");

	//set windows background
	glClearColor(1, 1, 1, 0);

	//defining a callback function for looping into the rasterizer
	glutDisplayFunc(serpenskiGasket);

	//setup projection windows
	glMatrixMode(GL_PROJECTION); //Select Projection Matrix
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 640);
	glPointSize(2);

	//telling the GLUT to loop into the callback
	glutMainLoop();
}