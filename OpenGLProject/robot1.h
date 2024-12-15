#pragma once
#ifndef ROBOT1_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define ROBOT1_H

#include <GL/freeglut.h>

void robot1(GLuint txId[8]);
void walkTimer(int value);

#endif