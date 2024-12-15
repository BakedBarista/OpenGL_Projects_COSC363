#include <math.h>
#include <GL/freeglut.h>
#include <iostream>
#include "floor.h"


void floor(GLuint txId[8])
{
	float white[4] = { 1., 1., 1., 1. };
	float black[4] = { 0 };
	glDisable(GL_TEXTURE_2D);
	//glColor4f(0.2, 0.3, 0.2, 1.0); //The floor is gray in colour
	glNormal3f(0.0, 1.0, 0.0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  //testing wireframes
	glBindTexture(GL_TEXTURE_2D, txId[6]); 
	
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	for (int i = -100; i < 100; i = i + 20)
	{
		for (int j = -100; j < 100; j = j + 20)
		{
			glTexCoord2f(0.0, 10);	
			glVertex3f(i, 0, j);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(i, 0, j + 20);
			glTexCoord2f(10, 0.0);	
			glVertex3f(i + 20, 0, j + 20);
			glTexCoord2f(10, 10);	
			glVertex3f(i + 20, 0, j);
		}
	}
	glEnd();
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glDisable(GL_TEXTURE_2D);
}