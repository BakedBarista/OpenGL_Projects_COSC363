#include <GL/freeglut.h>

float gamma = 20;
bool crawlDirection = true;

void robot2()
{
	float spotpos[] = { 0, 4.5, 2 };
	float spotdir[] = { -10,-10,0,0 };

	glColor3f(.81, 0.84, 0.95);
	glPushMatrix();
	glTranslatef(0.9, 7, 1.8);
	glScalef(0.1, 2, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);
	glPushMatrix();
	glTranslatef(0.6, 7, 1.8);
	glScalef(0.1, 1.5, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);			//Torso
	glPushMatrix();
	glTranslatef(0, 4.5, 0);
	glScalef(2, 4, 5);
	glutSolidCube(1);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.01);
	glLightfv(GL_LIGHT1, GL_POSITION, spotpos);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotdir);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);		//Right leg
	glPushMatrix();
	glTranslatef(-0.7, 4, 1.7);
	glRotatef(-gamma, 1, 0, 0);
	glTranslatef(0.8, -4, 0);
	glTranslatef(-0.8, 2.2, 0);
	glScalef(.5, 2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);		//Left leg
	glPushMatrix();
	glTranslatef(0.7, 4, 1.7);
	glRotatef(gamma, 1, 0, 0);
	glTranslatef(-0.8, -4, 0);
	glTranslatef(0.8, 2.2, 0);
	glScalef(0.5, 2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);		//Right leg
	glPushMatrix();
	glTranslatef(-0.7, 4, -1.7);
	glRotatef(-gamma, 1, 0, 0);
	glTranslatef(0.8, -4, 0);
	glTranslatef(-0.8, 2.2, 0);
	glScalef(.5, 2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(.81, 0.84, 0.95);		//Left leg
	glPushMatrix();
	glTranslatef(0.7, 4, -1.7);
	glRotatef(gamma, 1, 0, 0);
	glTranslatef(-0.8, -4, 0);
	glTranslatef(0.8, 2.2, 0);
	glScalef(0.5, 2, 1);
	glutSolidCube(1);
	glPopMatrix();
}

void walkTimer2(int value)
{
	if (crawlDirection)
	{
		gamma--;
		if (gamma == -10) crawlDirection = false;
	}
	else
	{
		gamma++;
		if (gamma == 10) crawlDirection = true;
	}
	glutPostRedisplay();
	glutTimerFunc(50, walkTimer2, 0);
}