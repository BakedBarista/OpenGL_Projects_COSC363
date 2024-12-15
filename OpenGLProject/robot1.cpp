#include <GL/freeglut.h>

float theta = 20;
bool walkDirection = true;

void robot1(GLuint txId[8])
{
	glColor3f(.81, 0.84, 0.95);		//Head
	glPushMatrix();
	glTranslatef(0, 7.7, 0);
	glutSolidCube(1.4);
	glPopMatrix();

	float white[4] = { 1., 1., 1., 1. };
	float black[4] = { 0 };
	glDisable(GL_TEXTURE_2D);
	//glColor4f(0.2, 0.3, 0.2, 1.0);
	glNormal3f(0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, txId[7]);

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTranslatef(-0.5, 8.3, 0.71);
	glRotatef(90, 1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1);
	glVertex3f(0, 0, 0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 1);
	glTexCoord2f(1, 0.0);
	glVertex3f(1, 0, 1);
	glTexCoord2f(1, 1);
	glVertex3f(1, 0, 0);
	glEnd();
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);			//Antena
	glPushMatrix();
	glTranslatef(0, 8.4, 0);
	glScalef(0.1, 3, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);			//Torso
	glPushMatrix();
	glTranslatef(0, 5.5, 0);
	glScalef(3, 3, 1.4);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);		//Right leg
	glPushMatrix();
	glTranslatef(-0.8, 4, 0);
	glRotatef(-theta, 1, 0, 0);
	glTranslatef(0.8, -4, 0);
	glTranslatef(-0.8, 2.2, 0);
	glScalef(1, 4.4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);		//Left leg
	glPushMatrix();
	glTranslatef(0.8, 4, 0);
	glRotatef(theta, 1, 0, 0);
	glTranslatef(-0.8, -4, 0);
	glTranslatef(0.8, 2.2, 0);
	glScalef(1, 4.4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);		//Right arm
	glPushMatrix();
	glTranslatef(-2, 6.5, 0);
	glRotatef(theta, 1, 0, 0);
	glTranslatef(2, -6.5, 0);
	glTranslatef(-2, 5, 0);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);		//Left arm
	glPushMatrix();
	glTranslatef(2, 6.5, 0);
	glRotatef(-theta, 1, 0, 0);
	glTranslatef(-2, -6.5, 0);
	glTranslatef(2, 5, 0);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();
}

void walkTimer(int value)
{
	if (walkDirection)
	{
		theta -= 3;
		if (theta < -50) walkDirection = false;
	}
	else
	{
		theta += 3;
		if (theta > 50) walkDirection = true;
	}
	glutPostRedisplay();
	glutTimerFunc(1, walkTimer, 0);
}