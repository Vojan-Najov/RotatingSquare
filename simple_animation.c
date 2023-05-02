#include <GL/glut.h>
#include <math.h>

static void myInit(void);
static void display(void);
static void idle(void);
static void mouse(int btn, int state, int x, int y);

GLsizei ww = 500, wh = 500;
double theta = 0.0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("Simple Animation");

	glutDisplayFunc(display);
//	glutIdleFunc(NULL);
	glutMouseFunc(mouse);

	myInit();

	glutMainLoop();

	return (0);
}

static void myInit(void)
{
	glViewport(0, 0, ww, wh);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		theta = theta/((2*M_PI)/360.0);
		glVertex2f(cos(theta), sin(theta));
		glVertex2f(-sin(theta), cos(theta));
		glVertex2f(-cos(theta), -sin(theta));
		glVertex2f(sin(theta), -cos(theta));
	glEnd();
	glFlush();
}

static void idle(void)
{
	theta += 2.0;
	theta = fmod(theta, 360.0);
	glutPostRedisplay();
}

static void mouse(int btn, int state, int x, int y)
{
	static int animation;

	(void) x;
	(void) y;

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (animation) {
			glutIdleFunc(NULL);
			animation = 0;
		} else {
			glutIdleFunc(idle);
			animation = 1;
		}
	}
}
