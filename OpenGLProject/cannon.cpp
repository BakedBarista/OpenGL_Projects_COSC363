#include <iostream>
#include <fstream>
#include <climits>
#include <math.h> 
#include <sstream>
#include <GL/freeglut.h>
using namespace std;

float* x, * y, * z;  //vertex coordinate arrays
int* t1, * t2, * t3; //triangles
int nvrt, ntri;    //total number of vertices and triangles
float cannon_x = 0;
float cannon_y = 0;
bool cannon_done = true;


//-- Loads mesh data in OFF format    -------------------------------------
void loadMeshFile(const char* fname)
{
	ifstream fp_in;
	int num, ne;

	fp_in.open(fname, ios::in);
	if (!fp_in.is_open())
	{
		cout << "Error opening mesh file" << endl;
		exit(1);
	}

	fp_in.ignore(INT_MAX, '\n');				//ignore first line
	fp_in >> nvrt >> ntri >> ne;			    // read number of vertices, polygons, edges

	x = new float[nvrt];                        //create arrays
	y = new float[nvrt];
	z = new float[nvrt];

	t1 = new int[ntri];
	t2 = new int[ntri];
	t3 = new int[ntri];

	for (int i = 0; i < nvrt; i++)                         //read vertex list 
		fp_in >> x[i] >> y[i] >> z[i];

	for (int i = 0; i < ntri; i++)                         //read polygon list 
	{
		fp_in >> num >> t1[i] >> t2[i] >> t3[i];
		if (num != 3)
		{
			cout << "ERROR: Polygon with index " << i << " is not a triangle." << endl;  //not a triangle!!
			exit(1);
		}
	}

	fp_in.close();
	cout << " File successfully read." << endl;
}

//--Function to compute the normal vector of a triangle with index tindx ----------
void normal(int tindx)
{
	float x1 = x[t1[tindx]], x2 = x[t2[tindx]], x3 = x[t3[tindx]];
	float y1 = y[t1[tindx]], y2 = y[t2[tindx]], y3 = y[t3[tindx]];
	float z1 = z[t1[tindx]], z2 = z[t2[tindx]], z3 = z[t3[tindx]];
	float nx, ny, nz;
	nx = y1 * (z2 - z3) + y2 * (z3 - z1) + y3 * (z1 - z2);
	ny = z1 * (x2 - x3) + z2 * (x3 - x1) + z3 * (x1 - x2);
	nz = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	glNormal3f(nx, ny, nz);
}

//--------draws the mesh model of the cannon----------------------------
void drawCannon()
{
	glColor3f(0.4, 0.5, 0.4);

	//Construct the object model here using triangles read from OFF file
	glBegin(GL_TRIANGLES);
	for (int tindx = 0; tindx < ntri; tindx++)
	{
		normal(tindx);
		glVertex3d(x[t1[tindx]], y[t1[tindx]], z[t1[tindx]]);
		glVertex3d(x[t2[tindx]], y[t2[tindx]], z[t2[tindx]]);
		glVertex3d(x[t3[tindx]], y[t3[tindx]], z[t3[tindx]]);
	}
	glEnd();
}

void cannon()
{
	//--cannon
	glPushMatrix();
	glTranslatef(-20, 30, 0);
	glRotatef(30, 0, 0, 1);
	glTranslatef(20, -30, 0);
	drawCannon();
	glPopMatrix();

	//--start mount
	glPushMatrix();
	glColor3f(1, 0.7, 0.1);
	glTranslatef(-10, 5, 17);
	glScalef(80, 10, 6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.7, 0.1);
	glTranslatef(-20, 25, 17);
	glScalef(40, 30, 6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.7, 0.1);
	glTranslatef(-10, 5, -17);
	glScalef(80, 10, 6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.7, 0.1);
	glTranslatef(-20, 25, -17);
	glScalef(40, 30, 6);
	glutSolidCube(1);
	glPopMatrix();
	//--end mount

	//--cannon ball
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(38.88 + cannon_x, 64 + cannon_y, 0);
	glutSolidSphere(5, 36, 18);
	glPopMatrix();

	glFlush();
}

//------ Cannon ball timer to move it ------------------------------------
void cannonShotTimer(int value)
{
	if (cannon_y + 64 > -10) {
		cannon_done = false;
		cannon_x += 10;
		cannon_y = (-pow(cannon_x, 2)) / 200 + cannon_x;  //cannon parabola function (range increase the divider of x^2)
		glutPostRedisplay();
		glutTimerFunc(1, cannonShotTimer, 0);
	}
	else {
		cannon_done = true;
	}
}