#include <math.h>
#include <GL/freeglut.h>
#include <iostream>
#include "floor.h"

void wall(int wall_length)
{
	glDisable(GL_TEXTURE_2D);
	for (int i = 0; i < wall_length * 4; i += 4) {
		glColor3f(0.8, 0.8, 0.8);
		glPushMatrix();
		glTranslatef(i, 4, 0);
		glScalef(2, 8, 1);
		glutSolidCube(1);
		glPopMatrix();

		glColor3f(0.8, 0.8, 0.8);
		glPushMatrix();
		glTranslatef(i + 2, 5, 0);
		glScalef(2, 10, 1);
		glutSolidCube(1);
		glPopMatrix();
	}
}


void walls()
{
	wall(4);
	glPushMatrix();
	glTranslatef(24, 0, 0);
	wall(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 20);
	wall(10);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glTranslatef(1, 0, 0);
	wall(5);
	glTranslatef(0, 0, -38);
	wall(5);
	glPopMatrix();
}