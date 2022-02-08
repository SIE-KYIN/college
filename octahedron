#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat rotateX = 0.0;
GLfloat rotateY = 0.0;

GLfloat MyVertices[6][3] = {
    { 0.25, 0, 0.25 },
    { -0.25, 0, -0.25 },
    { 0.25, 0, -0.25 },
    { -0.25, 0 , 0.25 },
    {0, 0.25 , 0 },
    {0, -0.25 , 0 }
};
GLfloat MyColors[8][3] = {
    { 0.2, 0.2, 0.2 },
    { 1.0, 0.0, 0.0 },
    { 1.0, 1.0, 0.0 },
    { 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    { 1.0, 0.0, 1.0 },
    { 0.5, 0.5, 0.5 },
    { 0.0, 1.0, 1.0 }
};
GLubyte MyVertexList[24] = {
    3,0,4,
    0,2,4,
    2,1,4,
    1,3,4,
    3,5,0,
    0,5,2,
    2,5,1,
    1,5,3
};

void MySpecial(int KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case GLUT_KEY_LEFT:
        rotateY -= 10.0; glutPostRedisplay(); break;
    case GLUT_KEY_RIGHT:
        rotateY += 10.0; glutPostRedisplay(); break;
    case GLUT_KEY_UP:
        rotateX += 10.0; glutPostRedisplay(); break;
    case GLUT_KEY_DOWN:
        rotateX -= 10.0; glutPostRedisplay(); break;
    }
}


void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    //glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    //glColorPointer(3, GL_FLOAT, 0, MyColors);
    glVertexPointer(3, GL_FLOAT, 0, MyVertices);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(rotateX, 1.0, 0, 0);
    glRotatef(rotateY, 0, 1.0, 0);
    for (GLint i = 0; i < 8; i++) {
        glColor3f(MyColors[i][0], MyColors[i][1], MyColors[i][2]);
        glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, &MyVertexList[3 * i]);
    }
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2017305053 이규진");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutSpecialFunc(MySpecial);
    glutMainLoop();
    return 0;
}
