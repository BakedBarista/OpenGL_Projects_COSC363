//  ========================================================================
//  COSC363: Computer Graphics (2024); CSSE  University of Canterbury.
//
//  FILE NAME: Yard.cpp
//  See Lab03.pdf for details.
//  ========================================================================
 
#include <iostream>
#include <cmath> 
#include <GL/freeglut.h>
#include "loadTGA.h"
using namespace std;

GLuint txId[2];   //Texture ids

float angle=0, look_x, look_z=-1., eye_x, eye_z;  //Camera parameters

//--------------------------------------------------------------------------------
void loadTexture()				
{
	glGenTextures(2, txId); 	// Create 2 texture ids

	glBindTexture(GL_TEXTURE_2D, txId[0]);  //Use this texture
    loadTGA("Wall.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	//Set texture parameters
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	

	glBindTexture(GL_TEXTURE_2D, txId[1]);  //Use this texture
    loadTGA("Floor.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	//Set texture parameters
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	
	
	
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
}

//--------------------------------------------------------------------------------
void special(int key, int x, int y)
{
	if(key == GLUT_KEY_LEFT) angle -= 0.1;  //Change direction
	else if(key == GLUT_KEY_RIGHT) angle += 0.1;
	else if(key == GLUT_KEY_DOWN)
	{  //Move backward
		eye_x -= 0.1*sin(angle);
		eye_z += 0.1*cos(angle);
	}
	else if(key == GLUT_KEY_UP)
	{ //Move forward
		eye_x += 0.1*sin(angle);
		eye_z -= 0.1*cos(angle);
	}

	look_x = eye_x + 100*sin(angle);
	look_z = eye_z - 100*cos(angle);
	glutPostRedisplay();
}

//--------------------------------------------------------------------------------

void initialise()
{ 
	loadTexture();	
	glEnable(GL_TEXTURE_2D);
	glClearColor(0., 1., 1., 1.);    //Background colour 	
	glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------------------------

void walls()
{
	   //replace with a texture
	glBindTexture(GL_PROXY_TEXTURE_2D, txId[0]);
 	glBegin(GL_QUADS);

	////////////////////// BACK WALL ///////////////////////
	glTexCoord2f(0.0f, 2.0f);
	glVertex3f(-15, 1, -15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-15, -1, -15);
	glTexCoord2f(12.0f, 0.0f);
	glVertex3f(15, -1, -15);
	glTexCoord2f(12.0f, 2.0f);
	glVertex3f(15, 1, -15);

	////////////////////// FRONT WALL ///////////////////////
	 glTexCoord2f(0.0f, 2.0f);
     glVertex3f(-15, 1, 15);
	 glTexCoord2f(0.0f, 0.0f);
 	 glVertex3f(-15, -1, 15);
	 glTexCoord2f(12.0f, 0.0f);
 	 glVertex3f(15, -1, 15);
	 glTexCoord2f(12.0f, 2.0f);
     glVertex3f(15, 1, 15);

	////////////////////// LEFT WALL ///////////////////////
	 glTexCoord2f(0.0f, 2.0f);
	 glVertex3f(-15, 1, -15);
	 glTexCoord2f(0.0f, 0.0f);
  	 glVertex3f(-15, -1, -15);
	 glTexCoord2f(12.0f, 0.0f);
	 glVertex3f(-15, -1, 15);
	 glTexCoord2f(12.0f, 2.0f);
 	 glVertex3f(-15, 1, 15);


	////////////////////// RIGHT WALL ///////////////////////
	 glTexCoord2f(0.0f, 2.0f);
	 glVertex3f(15, 1, -15);
	 glTexCoord2f(0.0f, 0.0f);
	 glVertex3f(15, -1, -15);
	 glTexCoord2f(12.0f, 0.0f);
 	 glVertex3f(15, -1, 15);
	 glTexCoord2f(12.0f, 2.0f);
 	 glVertex3f(15, 1, 15);

	glEnd();
}
//--------------------------------------------------------------------------------

void floor()
{
     //replace with a texture
	glBindTexture(GL_PROXY_TEXTURE_2D, txId[1]);
	glBegin(GL_QUADS);
		 glTexCoord2f(0.0f, 2.0f);
		 glVertex3f(-15, -1, -15);
		 glTexCoord2f(0.0f, 0.0f);
		 glVertex3f(-15, -1, 15);
		 glTexCoord2f(12.0f, 0.0f);
		 glVertex3f(15, -1, 15);
		 glTexCoord2f(12.0f, 2.0f);
		 glVertex3f(15, -1, -15);
	glEnd();
}

//--------------------------------------------------------------------------------

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glMatrixMode(GL_PROJECTION);						
	glLoadIdentity();
	gluPerspective(45., 1., 1., 100.);

	glMatrixMode(GL_MODELVIEW);								
	glLoadIdentity();
	gluLookAt(eye_x, 0, eye_z,  look_x, 0, look_z,   0, 1, 0);	
	
	walls();
	floor();

	glutSwapBuffers();									
}

//--------------------------------------------------------------------------------

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
   glutInitWindowSize (800, 800); 
   glutInitWindowPosition (10, 10);
   glutCreateWindow ("The Yard");
   initialise();

   glutDisplayFunc(display); 
   glutSpecialFunc(special);
   glutMainLoop();
   return 0;
}
