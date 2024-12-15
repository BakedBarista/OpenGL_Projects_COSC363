#include <GL/freeglut.h>
using namespace std;

float beta = 0;

void spaceship()
{
	glColor3f(1., 0.78, 0.06);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glutSolidSphere(3, 30, 30);
	glPopMatrix();

	glColor3f(0.4, 0.4, 0.9);
	glPushMatrix();
	glTranslatef(0, 3, 0);
	glScalef(1, 0.2, 1);
	glutSolidSphere(6, 30, 30);
	glPopMatrix();

	//----------------------------------------------
	glPushMatrix();
	glRotatef(beta, 0, 1, 0);
	glColor3f(0.7, 0.5, 0.6);
	glPushMatrix();
	glTranslatef(0, 3.6, 4.5);
	glScalef(1, 1, 1);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

	glColor3f(0.7, 0.5, 0.6);
	glPushMatrix();
	glTranslatef(0, 3.6, -4.5);
	glScalef(1, 1, 1);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

	glColor3f(0.7, 0.5, 0.6);
	glPushMatrix();
	glTranslatef(4.5, 3.6, 0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

	glColor3f(0.7, 0.5, 0.6);
	glPushMatrix();
	glTranslatef(-4.5, 3.6, 0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//----------------------------------------------
}

void spinTimer(int value)
{
	beta = beta + 0.5;
	if (beta > 360) beta = 0;
	glutPostRedisplay();
	glutTimerFunc(10, spinTimer, 0);
}