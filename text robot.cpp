#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(lib, "glaux.lib")

#pragma comment(lib, "legacy_stdio_definitions.lib")


#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glaux.h>

int Width, Height;
float angle = 0.0f;
float angle2 = 0.0f;
////// Robot variables
float legAngle[2] = { 0.0f, 0.0f };		// each leg's current angle
float armAngle[2] = { 0.0f, 0.0f };
float lowlegAngle[2] = { -7.0f, -7.0f };

GLfloat xrot = 0.9f, yrot = 0.8f, zrot = 1.0f;
unsigned int MyTextureObject[1];
AUX_RGBImageRec* pTextureImage[1];  //텍스쳐 저장 공간을 가리키는 포인터
char tmp[20] = "kakao.bmp";
void MyReshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void mytimer(int value)
{
	angle = angle + 0.5f;
	angle2 = angle2 + 0.3f;   // increase our rotation angle counter
	if (angle >= 360.0f)               // if we've gone in a circle, reset counter
		angle = 0.0f;
	if (angle2 >= 35)
		angle2 = -35;
	glutPostRedisplay();
}
void MyDisplay(float xPos, float yPos, float zPos) {
	glTranslatef(xPos, yPos, zPos);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  //앞면
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  //뒷면
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  //윗면
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  //아랫면
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  //우측면
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  //좌측면
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    //glutSwapBuffers();
}
void DrawCube(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);	// top face
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);	// front face
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f); // right face
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);

	glVertex3f(-1.0f, 0.0f, 0.0f);	// left face
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);	// bottom face
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f); // back face
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);

	glEnd();
	glPopMatrix();
}

// DrawArm
// desc: draws one arm
void DrawArm(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	// red
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.0f, 1.0f);		// arm is a 1x4x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawArm2
// desc: draws one arm
void DrawArm2(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);	// red
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.0f, 1.0f);		// arm is a 1x4x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawHead
// desc: draws the robot head
void DrawHead(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);	// white
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 1.0f, 1.0f);		// head is a 2x2x2 cube
	MyDisplay(-1.0f, -1.0f, -1.0f);
	glPopMatrix();
}

// DrawTorso
// desc: draws the robot torso
void DrawTorso(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);	// blue
	glTranslatef(xPos, yPos, zPos);
	glScalef(3.0f, 5.0f, 2.0f);		// torso is a 3x5x2 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawLeg
// desc: draws a single leg
void DrawLeg(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.5f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawLeg
// desc: draws a single leg
void DrawLeg2(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.7f, 0.6f, 1.0f);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.5f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
// Drawfoot
// desc: draws a single foot
void Drawfoot(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 1.0f, 2.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// Drawhand
// desc: draws a single foot
void Drawhand(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 0.7f, 0.7f);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 1.0f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}


// DrawRobot
// desc: draws the robot located at (xpos,ypos,zpos)
void DrawRobot(float xPos, float yPos, float zPos)
{
	static bool leg1 = true;		// robot's leg states
	static bool leg2 = false;		// true = forward, false = back

	static bool leg3 = true;		// robot's leg states
	static bool leg4 = false;		// true = forward, false = back

	static bool arm1 = true;
	static bool arm2 = false;

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);	// draw robot at desired coordinates

// draw components
	DrawHead(1.0f, 2.0f, 0.0f);
	DrawTorso(1.5f, 0.0f, 0.0f);
	glPushMatrix();
	// if leg is moving forward, increase angle, else decrease angle
	if (arm1)
		armAngle[0] = armAngle[0] + 0.3f;
	else
		armAngle[0] = armAngle[0] - 0.3f;

	// once leg has reached its maximum angle in a direction,
	// reverse it
	if (armAngle[0] >= 15.0f)
		arm1 = false;
	if (armAngle[0] <= -15.0f)
		arm1 = true;

	// move the leg away from the torso and rotate it to give "walking" effect
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngle[0], 1.0f, 0.0f, 0.0f);
	DrawArm(2.5f, 0.0f, -0.5f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	DrawArm2(2.5f, -0.5f, 3.0f);
	Drawhand(2.5f, -2.5f, 3.0f);
	glPopMatrix();

	glPushMatrix();
	// if leg is moving forward, increase angle, else decrease angle
	if (arm2)
		armAngle[1] = armAngle[1] + 0.3f;
	else
		armAngle[1] = armAngle[1] - 0.3f;

	// once leg has reached its maximum angle in a direction,
	// reverse it
	if (armAngle[1] >= 15.0f)
		arm2 = false;
	if (armAngle[1] <= -15.0f)
		arm2 = true;

	// move the leg away from the torso and rotate it to give "walking" effect
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngle[1], 1.0f, 0.0f, 0.0f);
	DrawArm(-1.5f, 0.0f, -0.5f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	DrawArm2(-1.5f, -0.5f, 3.0f);
	Drawhand(-1.5f, -2.5f, 3.0f);
	glPopMatrix();


	// we want to rotate the legs relative to the robot's position in the world
	// this is leg 1, the robot's right leg
	glPushMatrix();

	// if leg is moving forward, increase angle, else decrease angle
	if (leg1)
		legAngle[0] = legAngle[0] + 0.3f;
	else
		legAngle[0] = legAngle[0] - 0.3f;



	// once leg has reached its maximum angle in a direction,
	// reverse it
	if (legAngle[0] >= 15.0f)
		leg1 = false;
	if (legAngle[0] <= -15.0f)
		leg1 = true;



	// move the leg away from the torso and rotate it to give "walking" effect
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(legAngle[0], 1.0f, 0.0f, 0.0f);

	// draw the leg
	DrawLeg(-0.5f, -4.6f, -0.5f);

	glPushMatrix();
	if (leg3)
		lowlegAngle[0] = lowlegAngle[0] + 0.3f;
	else
		lowlegAngle[0] = lowlegAngle[0] - 0.3f;

	if (lowlegAngle[0] >= 7.0f)
		leg3 = false;
	if (lowlegAngle[0] <= -23.0f)
		leg3 = true;
	glTranslatef(-0.5f, -6.9f, -0.5f);
	glRotatef(lowlegAngle[0], 1.0f, 0.0f, 0.0f);
	DrawLeg2(0.0f, -0.0f, 0.0f);
	Drawfoot(0.0f, -2.5f, 0.0f);
	glPopMatrix();



	glPopMatrix();



	// do the same as above with leg 2, the robot's left leg
	glPushMatrix();

	if (leg2)
		legAngle[1] = legAngle[1] + 0.3f;
	else
		legAngle[1] = legAngle[1] - 0.3f;

	if (legAngle[1] >= 15.0f)
		leg2 = false;
	if (legAngle[1] <= -15.0f)
		leg2 = true;

	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(legAngle[1], 1.0f, 0.0f, 0.0f);
	DrawLeg(1.5f, -4.6f, -0.5f);

	glPushMatrix();
	if (leg4)
		lowlegAngle[1] = lowlegAngle[1] + 0.3f;
	else
		lowlegAngle[1] = lowlegAngle[1] - 0.3f;

	if (lowlegAngle[1] >= 7.0f)
		leg4 = false;
	if (lowlegAngle[1] <= -23.0f)
		leg4 = true;
	glTranslatef(1.5f, -6.9f, -0.5f);
	glRotatef(lowlegAngle[1], 1.0f, 0.0f, 0.0f);
	DrawLeg2(0.0f, -0.0f, 0.0f);
	Drawfoot(0.0f, -2.5f, 0.0f);
	glPopMatrix();



	//DrawLeg2(1.5f, -7.5f, -0.5f);
	//Drawfoot(1.5f, -10.0f, -0.5f);
	glPopMatrix();
	glPopMatrix();
}

void drawtile(float a, float b)
{
	glColor3f(0.3, 0.7, 1.0);
	glPushMatrix();
	glTranslatef(0.0, -b, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(a, 0.0, a);
	glVertex3f(a, 0.0, -a);
	glVertex3f(-a, 0.0, -a);
	glVertex3f(-a, 0.0, a);
	glEnd();
	glPopMatrix();
}

void Render()
{
	glutTimerFunc(10, mytimer, 3);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);

	
	glLoadIdentity();										// reset modelview matrix
	gluLookAt(0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	DrawRobot(0.0f, 0.0f, 0.0f);		// draw the robot

	glutSwapBuffers();

}
AUX_RGBImageRec* LoadBMP(char* szFilename) {
    FILE* pFile = NULL;
    if (!szFilename) {
        return NULL;
    }
    pFile = fopen(szFilename, "r");
    if (pFile) {
        fclose(pFile);
        return auxDIBImageLoad(szFilename);     //파일로부터 메모리로
    }
    return NULL;
}

int LoadGLTextures(char* szFilePath) {       //파일을 로드하고 텍스쳐로 변환
    int Status = FALSE;
    glClearColor(0.0, 0.0, 0.0, 0.5);
    memset(pTextureImage, 0, sizeof(void*) * 1);    //포인터를 널로

    if (pTextureImage[0] = LoadBMP(szFilePath)) {   //비트맵을 로드하고 오류확인
        Status = TRUE;                              //상태 플랙을 True로
        glGenTextures(1, &MyTextureObject[0]);      //텍스쳐 생성
        glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
            pTextureImage[0]->sizeX, pTextureImage[0]->sizeY,
            0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glEnable(GL_TEXTURE_2D);
    }
    if (pTextureImage[0]) {                 //텍스쳐가 존재하면
        if (pTextureImage[0]->data) {       //텍스쳐 영상이 존재하면
            free(pTextureImage[0]->data);   //텍스쳐 영상공간 반납
        }
        free(pTextureImage[0]);             //텍스쳐 반납
    }
    return Status;
}

void main(int argc, char** argv) {
	Width = 800;
	Height = 800;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("2017305053 이규진");
	glutDisplayFunc(Render);
    glutReshapeFunc(MyReshape);
    //glutTimerFunc(500, mytimer, 1);
    if (LoadGLTextures(tmp)) {
        glEnable(GL_TEXTURE_2D);
        glShadeModel(GL_SMOOTH);
        glClearDepth(1.0);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
        glutMainLoop();
    }
}
