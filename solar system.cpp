#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

static int Day = 0, Time = 0;

void mytimer(int value)
{
    Day = (Day + 10) % 360;
    Time = (Time + 5) % 360;
    glutPostRedisplay();
}
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glutTimerFunc(100, mytimer, 1);
    glLoadIdentity();

    //draw sun
    glColor3f(1.0, 0.3, 0.3);
    glutWireSphere(0.30, 20, 16);
    glPushMatrix();// save the sun's coordinate

    //draw earth
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.7, 0.0, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.5, 0.6, 0.7);
    glutWireSphere(0.1, 10, 8);

    //draw moon
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0.9, 0.8, 0.2);
    glutWireSphere(0.05, 10, 8);
    
    //return to sun
    glPopMatrix();

    //save the sun's coordinate
    glPushMatrix();

    //draw the biggest satellite
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glutWireSphere(0.25, 20, 16);

    //return to sun
    glPopMatrix();

    //draw another sun
    glTranslatef(1.3, 0.0, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glutWireSphere(0.20, 10, 8);

    //draw another sun's satellite
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.28, 0.0, 0.0);
    glColor3f(1, 0.77, 0.8);
    glutWireSphere(0.03, 10, 8);

    glutSwapBuffers();
}

/*
void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        Day = (Day + 10) % 360;
        glutPostRedisplay();
        break;
    case 't':
        Time = (Time + 5) % 360;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}
*/
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2017305053 이규진");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.5, 2.5, -2.5, 2.5, -2.5, 2.5);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
