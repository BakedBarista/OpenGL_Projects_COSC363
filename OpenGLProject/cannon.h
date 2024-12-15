
#ifndef CANNON_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define CANNON_H

#include <iostream>
#include <fstream>
#include <climits>
#include <math.h> 
#include <sstream>
#include <GL/freeglut.h>

extern float cannon_x;
extern float cannon_y;
extern bool cannon_done;

void loadMeshFile(const char* fname);
void cannon();
void cannonShotTimer(int value);

#endif
