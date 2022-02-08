#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
float g_speed = 0.005;
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
GLfloat DeltaX = 0.0;
GLfloat DeltaY = 0.0;

GLboolean IsSphere = true;
GLboolean IsSmall = true;


void MyTimer2(int Value);
void MyTimer3(int Value);
void MyTimer4(int Value);
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y);


void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0.77, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(TopLeftX / 1000.0 + DeltaX, (1000.0 - TopLeftY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(TopLeftX / 1000.0 + DeltaX, (1000.0 - BottomRightY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(BottomRightX / 1000.0 + DeltaX, (1000.0 - BottomRightY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(BottomRightX / 1000.0 + DeltaX, (1000.0 - TopLeftY) / 1000.0 + DeltaY, 0.0);
    glEnd();
    glFlush();
}

void MyDisplay2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(TopLeftX / 1000.0 + DeltaX, (1000.0 - TopLeftY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(TopLeftX / 1000.0 + DeltaX, (1000.0 - BottomRightY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(BottomRightX / 1000.0 + DeltaX, (1000.0 - BottomRightY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(BottomRightX / 1000.0 + DeltaX, (1000.0 - TopLeftY) / 1000.0 + DeltaY, 0.0);
    glEnd();
    glFlush();
}

void MyDisplay3() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0.6, 0);
    glBegin(GL_POLYGON);
    glVertex3f(TopLeftX / 1000.0 + DeltaX, (1000.0 - TopLeftY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(TopLeftX / 1000.0 + DeltaX, (1000.0 - BottomRightY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(BottomRightX / 1000.0 + DeltaX, (1000.0 - BottomRightY) / 1000.0 + DeltaY, 0.0);
    glVertex3f(BottomRightX / 1000.0 + DeltaX, (1000.0 - TopLeftY) / 1000.0 + DeltaY, 0.0);    
    glEnd();
    glFlush();
}
void MyTimer1(int Value) {
    DeltaX = DeltaX + g_speed;
    DeltaY = DeltaY + g_speed;
    glutPostRedisplay();
    if ((1000.0 - TopLeftY) / 1000.0 + DeltaY > 1)
        glutTimerFunc(10, MyTimer2, 1);
    else if (BottomRightX / 1000.0 + DeltaX > 1)
        glutTimerFunc(10, MyTimer3, 1);
    else
        glutTimerFunc(10, MyTimer1, 1);
}

void MyTimer2(int Value) {
    DeltaX = DeltaX + g_speed;
    DeltaY = DeltaY - g_speed;
    glutPostRedisplay();
    if (BottomRightX / 1000.0 + DeltaX > 1)
        glutTimerFunc(10, MyTimer3, 1);
    else if ((1000.0 - BottomRightY) / 1000.0 + DeltaY < 0)
        glutTimerFunc(10, MyTimer4, 1);
    else
        glutTimerFunc(10, MyTimer2, 1);
}
void MyTimer3(int Value) {
    DeltaX = DeltaX - g_speed;
    DeltaY = DeltaY - g_speed;
    glutPostRedisplay();
    if ((1000.0 - BottomRightY) / 1000.0  + DeltaY < 0)
        glutTimerFunc(10, MyTimer4, 1);
    else if (TopLeftX / 1000.0 + DeltaX < 0)
        glutTimerFunc(10, MyTimer1, 1);
    else
        glutTimerFunc(10, MyTimer3, 1);
}

void MyTimer4(int Value) {
    DeltaX = DeltaX - g_speed;
    DeltaY = DeltaY + g_speed;
    glutPostRedisplay();
    if (TopLeftX / 1000.0 + DeltaX < 0)
        glutTimerFunc(10, MyTimer1, 1);
    else if ((1000.0 - TopLeftY) / 1000.0 + DeltaY > 1)
        glutTimerFunc(10, MyTimer2, 1);
    else
        glutTimerFunc(10, MyTimer4, 1);
    
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
        DeltaX = 0;
        DeltaY = 0;
    }
}

void MyMouseMove(GLint X, GLint Y) {
    BottomRightX = X;
    BottomRightY = Y;
    glutPostRedisplay();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case 'P':
        glutDisplayFunc(MyDisplay); break;
    case 'p':
        glutDisplayFunc(MyDisplay); break;
    case 'Y':
        glutDisplayFunc(MyDisplay2); break;
    case 'y':
        glutDisplayFunc(MyDisplay2); break;
    case 'O':
        glutDisplayFunc(MyDisplay3); break;
    case 'o':
        glutDisplayFunc(MyDisplay3); break;
    }
}

void MySpecial(int KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case GLUT_KEY_LEFT:
        if(g_speed > 0)g_speed -= 0.001; break;
    case GLUT_KEY_RIGHT:
        if(g_speed <0.02)g_speed += 0.001; break;
    case GLUT_KEY_UP:
        BottomRightX += 50; BottomRightY += 50; break;
    case GLUT_KEY_DOWN:
        if (BottomRightX > 0 && BottomRightY > 0) { BottomRightX -= 50; BottomRightY -= 50; } break;
    }
}

void MyMainMenu(int entryID) {
    glutPostRedisplay();
}

void MySubMenu(int entryID) {
    if (entryID == 1) {
        BottomRightX -= 100; BottomRightY -= 100;
    }  
    else if (entryID == 2) {
        BottomRightX += 100; BottomRightY += 100;
    }
    glutPostRedisplay();
}

void MySubMenu2(int entryID) {
    if (entryID == 1)
        g_speed = 0.002;
    else if (entryID == 2)
        g_speed = 0.01;
    glutPostRedisplay();
}

void MySubMenu3(int entryID) {
    if (entryID == 1)
        glutDisplayFunc(MyDisplay);
    else if (entryID == 2)
        glutDisplayFunc(MyDisplay2);
    else if (entryID == 3)
        glutDisplayFunc(MyDisplay3);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2017305053 이규진");

    glClearColor(0.5, 0.5, 0.5, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    GLint MySubMenuID1 = glutCreateMenu(MySubMenu);
    glutAddMenuEntry("작게", 1);
    glutAddMenuEntry("크게", 2); 

    GLint MySubMenuID2 = glutCreateMenu(MySubMenu2);
    glutAddMenuEntry("느리게", 1);
    glutAddMenuEntry("빠르게", 2);

    GLint MySubMenuID3 = glutCreateMenu(MySubMenu3);
    glutAddMenuEntry("핑크", 1);
    glutAddMenuEntry("노랑", 2);
    glutAddMenuEntry("주황", 3);

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddSubMenu("크기", MySubMenuID1);
    glutAddSubMenu("속도", MySubMenuID2);
    glutAddSubMenu("색", MySubMenuID3);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(MyDisplay);

    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);

    glutKeyboardFunc(MyKeyboard);
    glutSpecialFunc(MySpecial);

    glutTimerFunc(10, MyTimer2, 1);
    glutMainLoop();
    return 0;
}
