#include <glut.h>  
#include <math.h>  
int ww = 600, wh = 400;
int xi, yi, xf, yf;
int dx, dy, steps, k;
float xinc, yinc, x , y;

void putPixel(int x, int y)
{
    glColor3f(0.3, 0.2, 0.0); // activate the pixel by setting the point color to white  
    glBegin(GL_POINTS);
    glVertex2i(x, y); // set the point  
    glEnd();
    glFlush(); // process all openGL routines as quickly as possible  
}


void display()
{
    glClearColor(0.4, 0.7, 0.5, 1.0);
    glColor3f(0.2, 0.3, 0.3);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void dda(int xi, int yi, int xf, int yf) {
    dx = xf - xi;
    dy = yf - yi;
    x = xi;
    y = yi;

    steps = (abs(dx) < abs(dy)) ? abs(dy) : abs(dx) ;

    xinc = static_cast<float>(dx) / steps;
    yinc = static_cast<float>(dy) / steps;

    putPixel(round(x), round(y));

    for (k = 0;k < steps;k++) {
        x += xinc;
        y += yinc;
        putPixel(round(x), round(y));
    }
}

void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN)
        {
            xi = x;
            yi = (wh - y);
        }
        else if (state == GLUT_UP) {
            xf = x;
            yf = (wh - y);
            glutPostRedisplay();
            dda(xi, yi, xf, yf);
        }
    if (btn == GLUT_RIGHT_BUTTON) {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
}
void myinit()
{
    glViewport(0, 0, ww, wh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(ww, wh);
    glutCreateWindow("Bresenham Line Algorithm");
    glutDisplayFunc(display);
    myinit();
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}