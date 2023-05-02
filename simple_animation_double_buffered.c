#include <GL/glut.h>
#include <math.h>

static void myInit(void);
static void display(void);
static void myReshape(int w, int h);
static void mouse(int btn, int state, int x, int y);
static void spinDisplay(void);

static GLfloat spin = 0.0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Double buffered");

	myInit();

	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glutIdleFunc(spinDisplay);
	glutMouseFunc(mouse);

	glutMainLoop();

	return (0);
}

static void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glutSwapBuffers();
}

static void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		glOrtho(-50.0, 50.0,
				-50.0*(GLfloat)h/(GLfloat)w, 50.0*(GLfloat)h/(GLfloat)w,
				-1.0, 1.0);
	} else {
		glOrtho(-50.0*(GLfloat)w/(GLfloat)h, 50.0*(GLfloat)w/(GLfloat)h,
				-50.0, 50.0, -1.0, 1.0);

	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
			glutIdleFunc(spinDisplay);
			animation = 1;
		}
	}
}

static void spinDisplay(void)
{
	spin += 2.0;
	spin = fmod(spin, 360.0);

	glLoadIdentity();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glutPostRedisplay();
}
