#include <glut.h>

float x = 0;
bool state = true;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(x - 0.5, -0.1);
    glVertex2f(x - 0.5, 0.5);
    glVertex2f(x + 0.5, 0.1);
    glVertex2f(x + 0.5, -0.5);
  glEnd();
  glutSwapBuffers();
}

void animate(int value) 
{
	x += 0.501;
	if (x > 2.5) x = -1.5;
	glutPostRedisplay();
	 if(state){
		glutTimerFunc(25, animate, value);
	 }

}


void mouse(int btn, int click, int x, int y)
{
	if (click == GLUT_LEFT_BUTTON)
		if (click == GLUT_DOWN){
		{
			state = !state;
		}
		if(state){
			animate(0);
		}
	}
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Translation Animation");
  glutDisplayFunc(display);
	glutTimerFunc(25, animate, 0);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); 
  glutMouseFunc(mouse); 
  glOrtho(-1.5, 1.5, -1.0, 1.0, -1.0, 1.0);
  glutMainLoop();
  return 0;
}