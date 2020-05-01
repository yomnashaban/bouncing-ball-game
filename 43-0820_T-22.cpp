#include <math.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <glut.h>
#include <mmsystem.h>
#include <sstream>

using namespace std;






float rotAng;
float xsize = 0;
float ysize = 0;
float zsize = 0;
bool color1 = true;
bool color2 = true;
float rotationy = 0;
float rotationx = 0;
bool straight = false;
bool shoot = false;
float translatex = 0.0;
float translatey = 0.6;
float translatez = 1.8;
int path = -10;
int lastpath = -10;
int round1 = -1;
int round2 = -1;
int round3 = -1;
int rounds = 0;
std::string a;
std::string b;
std::string c;
std::string d;
int overallscore = 0;
bool replay = false;
int mode = 1;
bool gameon = true;





void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);


	//loop to display character by character
	for (i = 0; i < len; i++)
	{

		glColor3f(1, 0, 0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void print1(int x, int y, const char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);


	//loop to display character by character
	for (i = 0; i < len; i++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}



void print2(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);


	//loop to display character by character
	for (i = 0; i < len; i++)
	{

		glColor3f(1, 0, 0);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
	}
}



void drawWall(double thickness) {
	glPushMatrix();
	glTranslated(0.5, 0.5 * thickness, 0.5);
	glScaled(1.0, thickness, 1.0);
	glutSolidCube(1);
	glPopMatrix();
}

void drawunitright() {
	glPushMatrix();
	//glColor3f(1.0f, 0.0f, 0.0f);
	glTranslated(-0.635, 0, -1.3);
	glRotated(90, 0, 0, 1);
	glScaled(0.4, 1, 0.5);
	drawWall(0.05);
	glPopMatrix();
}

void drawright() {
	//glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_BLEND);
	float xsize = 0;
	float ysize = 0;
	float zsize = 0;
	float color1 = true;
	float color2 = true;
	for (int j = 0;j < 5;j++)
	{
		zsize = 0;
		for (int i = 0;i < 5;i++)
		{
			glBegin(GL_QUADS);
			if (color1 == true && color2 == true) {
				glColor3f(0.3f, 0.4f, 0.6f);
				color2 = false;
			}
			else if (color1 == true && color2 == false) {
				glColor3f(0.8f, 0.6f, 0.6f);
				color2 = true;



			}
			else if (color1 == false && color2 == true) {
				glColor3f(0.4f, 0.3f, 0.5f);

				color2 = false;



			}
			else if (color1 == false && color2 == false) {
				glColor3f(0.5f, 0.5f, 0.5f);
				color2 = true;


			}


			/*drawunitright();
			glPushMatrix();
			glTranslated(0, ysize, zsize);
			drawunitright();
			glPopMatrix();*/



			glVertex3f(-0.5, 0.5 + ysize, 0.0 + zsize);
			glVertex3f(-0.5, 0.5 + ysize, 0.4 + zsize);
			glVertex3f(-0.5, 0.7 + ysize, 0.4 + zsize);
			glVertex3f(-0.5, 0.7 + ysize, 0.0 + zsize);
			glEnd();

			zsize = zsize + 0.4;
		}
		if (color1 == true) {
			color1 = false;

		}
		else {
			color1 = true;

		}

		ysize += 0.2;
	}
	//glFlush();

}


void drawleft() {
	//glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_BLEND);
	float xsize = 0;
	float ysize = 0;
	float zsize = 0;
	float color1 = true;
	float color2 = true;

	for (int j = 0;j < 5;j++)
	{
		zsize = 0;
		for (int i = 0;i < 5;i++)
		{
			glBegin(GL_QUADS);
			if (color1 == true && color2 == true) {
				glColor3f(0.3f, 0.4f, 0.6f);
				color2 = false;
			}
			else if (color1 == true && color2 == false) {
				glColor3f(0.8f, 0.6f, 0.6f);
				color2 = true;



			}
			else if (color1 == false && color2 == true) {
				glColor3f(0.4f, 0.3f, 0.5f);

				color2 = false;



			}
			else if (color1 == false && color2 == false) {
				glColor3f(0.5f, 0.5f, 0.5f);
				color2 = true;


			}

			glVertex3f(0.5, 0.5 + ysize, 0.0 + zsize);
			glVertex3f(0.5, 0.5 + ysize, 0.4 + zsize);
			glVertex3f(0.5, 0.7 + ysize, 0.4 + zsize);
			glVertex3f(0.5, 0.7 + ysize, 0.0 + zsize);
			glEnd();

			zsize = zsize + 0.4;
		}
		if (color1 == true) {
			color1 = false;

		}
		else {
			color1 = true;

		}

		ysize += 0.2;
	}
	//glFlush();

}
void drawtop() {
	//glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_BLEND);
	float xsize = 0;
	float ysize = 0;
	float zsize = 0;
	float color1 = true;
	float color2 = true;


	for (int j = 0;j < 5;j++)
	{
		xsize = 0;
		for (int i = 0;i < 5;i++)
		{
			glBegin(GL_QUADS);
			if (color1 == true && color2 == true) {
				glColor3f(0.5f, 0.5f, 0.5f);

				color2 = false;
			}
			else if (color1 == true && color2 == false) {
				glColor3f(0.8f, 0.6f, 0.6f);
				color2 = true;



			}
			else if (color1 == false && color2 == true) {
				glColor3f(0.4f, 0.3f, 0.5f);

				color2 = false;



			}
			else if (color1 == false && color2 == false) {
				glColor3f(0.3f, 0.4f, 0.6f);
				color2 = true;


			}

			glVertex3f(-0.5 + xsize, 1.5, 0.0 + zsize);
			glVertex3f(-0.3 + xsize, 1.5, 0.0 + zsize);
			glVertex3f(-0.3 + xsize, 1.5, 0.4 + zsize);
			glVertex3f(-0.5 + xsize, 1.5, 0.4 + zsize);
			glEnd();

			xsize = xsize + 0.2;
		}
		if (color1 == true) {
			color1 = false;

		}
		else {
			color1 = true;

		}

		zsize += 0.4;
	}
	//glFlush();

}

void drawbuttom() {

	//glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_BLEND);
	float xsize = 0;
	float ysize = 0;
	float zsize = 0;
	float color1 = true;
	float color2 = true;
	/*glBegin(GL_QUADS);

	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 2.0f);
	glVertex3f(-0.5f, 0.5f, 2.0f);
	glEnd();*/


	for (int j = 0;j < 5;j++)
	{
		xsize = 0;
		for (int i = 0;i < 5;i++)
		{
			glBegin(GL_QUADS);
			if (color1 == true && color2 == true) {
				glColor3f(0.5f, 0.5f, 0.5f);

				color2 = false;
			}
			else if (color1 == true && color2 == false) {
				glColor3f(0.8f, 0.6f, 0.6f);
				color2 = true;



			}
			else if (color1 == false && color2 == true) {
				glColor3f(0.4f, 0.3f, 0.5f);

				color2 = false;



			}
			else if (color1 == false && color2 == false) {
				glColor3f(0.3f, 0.4f, 0.6f);


				color2 = true;


			}

			glVertex3f(-0.5 + xsize, 0.5, 0.0 + zsize);
			glVertex3f(-0.3 + xsize, 0.5, 0.0 + zsize);
			glVertex3f(-0.3 + xsize, 0.5, 0.4 + zsize);
			glVertex3f(-0.5 + xsize, 0.5, 0.4 + zsize);
			glEnd();

			xsize = xsize + 0.2;
		}
		if (color1 == true) {
			color1 = false;

		}
		else {
			color1 = true;

		}

		zsize += 0.4;
	}
	//glFlush();


}
void shootingstation() {
	glBegin(GL_QUADS);
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.3f);
	glRotatef(rotationy, 0, 1, 0);
	glVertex3f(-0.015f, 0.5f, 1.8f);
	glVertex3f(0.015f, 0.5f, 1.8f);
	glVertex3f(0.015f, 0.5f, 2.4f);
	glVertex3f(-0.015f, 0.5f, 2.4f);
	glEnd();
	glPopMatrix();

	/*glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.3f);
	glVertex3f(0, 0.5, 1.8);
	glVertex3f(0, 0.5, 1.5); // along the z-axis
	glRotated(45, 0, 1, 0);
	glEnd();
	glPopMatrix();*/

	//the arrow
	glPushMatrix();
	glTranslated(0, 0.6, 2.0);
	glRotated(180, 1, 0, 0);
	glRotated(rotationy, 0, 1, 0);
	glRotated(rotationx, 1, 0, 0);

	glutWireCone(0.04, 0.2, 12, 9);
	glPopMatrix();
}
void ball() {

	//the ball
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);
	//glRotated(rotation, 0, 1, 0);
	glTranslated(translatex, translatey, translatez);
	glRotated(rotationy, 0, 1, 0);
	glRotated(rotationx, 1, 0, 0);
	glutWireSphere(0.05, 10, 10);
	glPopMatrix();

}


void printscore() {
	if (rounds == 0) {



		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.8, -2, 0);
		print(-2, 1, "0");
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.771, -2.3, 0);
		print(-2, 1, "0");
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.75, -2.6, 0);
		print(-2, 1, "0");
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.72, -2.9, 0);
		print(-2, 1, "0");
		glPopMatrix();

	}

	else if (rounds == 1) {

		std::stringstream sstm;
		sstm << round1;
		a = sstm.str();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.8, -2, 0);
		print1(-2, 1, a.data());


		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.771, -2.3, 0);
		print(-2, 1, "0");
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.75, -2.6, 0);
		print(-2, 1, "0");
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.72, -2.9, 0);
		print(-2, 1, "0");
		glPopMatrix();






	}
	else if (rounds == 2) {


		std::stringstream sstm;
		sstm << round2;
		b = sstm.str();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.8, -2, 0);
		print1(-2, 1, a.data());
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.771, -2.3, 0);
		print1(-2, 1, b.data());
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.75, -2.6, 0);
		print(-2, 1, "0");
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.72, -2.9, 0);
		print(-2, 1, "0");
		glPopMatrix();




	}
	else if (rounds >= 3) {
		overallscore = round1 + round2 + round3;


		std::stringstream sstm;
		sstm << round3;
		c = sstm.str();

		//std::stringstream sstm;


		overallscore = round1 + round2 + round3;
		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.8, -2, 0);
		print1(-2, 1, a.data());
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.771, -2.3, 0);
		print1(-2, 1, b.data());
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.75, -2.6, 0);
		print1(-2, 1, c.data());
		glPopMatrix();

		std::stringstream sstm1;
		sstm1 << overallscore;
		d = sstm1.str();


		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.72, -2.9, 0);
		print1(-2, 1, d.data());
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.8, 1.0, 1.0);
		glTranslated(0.6, -2.6, 0);
		//	print(-2, 1, overallscore);
		glPopMatrix();

		gameon = false;




	}






}



float x2 = 0.0;
float y2 = 2.0;
//float y2 = 1.7;
float z2 = 5.5;
//float z2 = 4;

float x3 = 0;
float y3 = 0;
float z3 = 0.5;
void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-0.5, 0.5, -0.5, 0.5, -1, 1);
	gluPerspective(45.0f, 1000 / 600, 0.1f, 300.0f);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x2, y2, z2, x3, y3, z3, 0.0f, 1.0f, 0.0f);
}


















void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	setupCamera();



	//Draw endside



	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.3f);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 1.5f, 0.0f);
	glVertex3f(-0.5f, 1.5f, 0.0f);
	glEnd();

	//draw rightside
	drawright();

	//draw leftside
	drawleft();

	//draw buttomside
	drawbuttom();

	//draw topside
	drawtop();

	//shooting staion
	shootingstation();
	ball();


	/*drawunitright();

	glPushMatrix();
	glTranslated(0,0,0.5);
	drawunitright();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 0.5, 2);
	glRotated(90.0, 1, 0, 0);
	glScaled(0.5, 1, 1);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutWireCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0);
	glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(0.5, 25, 25);
	glPopMatrix();*/

	glPushMatrix();
	glColor3f(0.8, 0.4, 0.6);
	glTranslated(0.15, 0, 0);
	print(-2, 1, "Game Information");
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(0, -0.3, 0);
	print2(-2, 1, "-Use Keyboard arrows to move");
	//print(-2, 1, "the arrow right/left and up/down and the button's' to shoot");

	glPopMatrix();



	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(0, -0.5, 0);
	print2(-2, 1, "the arrow right/left and ");
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-0.01, -0.7, 0);
	print2(-2, 1, "up/down.");
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-0.09, -1, 0);
	print2(-2, 1, "-Use the button'S'to shoot");
	glPopMatrix();



	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-0.1, -1.3, 0);
	print2(-2, 1, "and button'R' to replay round");
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-0.115, -1.6, 0);
	if (mode == 2 && replay == false) {
		print2(-2, 1, "-Enhanced Camera mode ON");
	}
	else {
		print2(-2, 1, "-Simple Camera mode ON");

	}
	glPopMatrix();



	glPushMatrix();
	glColor3f(0.8, 1.0, 1.0);
	glTranslated(0, -2, 0);
	print(-2, 1, "Round 1 Score :");
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 1.0, 1.0);
	glTranslated(-0.039, -2.3, 0);
	print(-2, 1, "Round 2 Score :");
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 1.0, 1.0);
	glTranslated(-0.08, -2.6, 0);
	print(-2, 1, "Round 3 Score :");
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 1.0, 1.0);
	glTranslated(-0.12, -2.9, 0);
	print(-2, 1, "Overall Score   :");
	glPopMatrix();



	printscore();
	//cout << round1;
	//cout << round2;
	//cout << round3;



	glFlush();
}





void processSpecialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT && rotationy > -80) {
		rotationy = rotationy - 3;
	}
	else if (key == GLUT_KEY_RIGHT && rotationy < 80) {
		rotationy = rotationy + 3;
	}
	else if (key == GLUT_KEY_UP && rotationx < 50) {
		rotationx = rotationx + 3;
	}
	else if (key == GLUT_KEY_DOWN && rotationx > -10) {
		rotationx = rotationx - 3;
	}
	else {
		rotationy = rotationy;
	}

	glutPostRedisplay();

}


void Key(unsigned char key, int x, int y) {

	if (key == 's' && rotationy > -24 && rotationy < 24) {
		straight = true;
		path = 0;
		lastpath = 0;


		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}

	}

	else if (key == 's' && rotationy >= 24 && rotationy < 52 && rotationx <= 25 && rotationx >= 0) {
		path = 1;
		lastpath = 1;
		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}
	}
	else if (key == 's' && rotationy >= -52 && rotationy < -24 && rotationx <= 25 && rotationx >= 0) {
		path = -1;
		lastpath = -1;
		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}

	}
	else if (key == 's' && rotationy >= 52 && rotationy < 84) {
		path = 2;
		lastpath = 2;
		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}

	}
	else if (key == 's' && rotationy >= -83 && rotationy < -52) {
		path = -2;
		lastpath = -2;
		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}

	}
	else if (key == 's' && rotationy >= 24 && rotationy < 52 && rotationx >= 25 && rotationx <= 52) {
		path = 3;
		lastpath = 3;
		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}

	}
	else if (key == 's' && rotationy >= -52 && rotationy < -24 && rotationx >= 25 && rotationx <= 52) {
		path = -3;
		lastpath = -3;
		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}
	}
	else if (key == 's' && rotationy >= 24 && rotationy < 52 && rotationx <= 0 && rotationx >= -13) {
		path = 4;
		lastpath = 4;
		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}

	}
	else if (key == 's' && rotationy >= -52 && rotationy < -24 && rotationx <= 0 && rotationx >= -13) {
		path = -4;
		lastpath = -4;
		shoot = true;
		if (gameon == true) {
			y2 = 1.7;
			z2 = 4;
		}

	}


	if (key == 'r' && lastpath != -10) {
		replay = true;
	}

	if (key == 'c') {
		if (mode == 1) {
			mode = 2;
		}
		else {
			mode = 1;
		}
	}



	glutPostRedisplay();


}







void keySpecialUp(int key, int x, int y) {

	if (shoot == false) {

		if (rotationy == 0) {
			translatex = 0.0;

		}
		else if (rotationy < 15 && rotationy >0) {
			translatex = 0.025;

		}
		else if (rotationy < 30 && rotationy >0) {
			translatex = 0.05;

		}
		else if (rotationy < 45 && rotationy >0) {
			translatex = 0.09;

		}
		else if (rotationy < 60 && rotationy >0) {
			translatex = 0.12;

		}
		else if (rotationy <= 82 && rotationy > 0) {

			translatex = 0.19;
			translatez = 1.9;

		}
		else if (rotationy > -15 && rotationy < 0) {
			translatex = -0.025;

		}
		else if (rotationy > -30 && rotationy < 0) {
			translatex = -0.05;

		}
		else if (rotationy > -45 && rotationy < 0) {
			translatex = -0.09;


		}
		else if (rotationy > -60 && rotationy < 0) {
			translatex = -0.12;

		}
		else if (rotationy >= -82 && rotationy < 0) {
			translatex = -0.19;
			translatez = 1.9;

		}

		if (rotationx == 0) {
			translatey = 0.6;

		}
		else if (rotationx < 15 && rotationx >0) {
			translatey = 0.65;
		}
		else if (rotationx < 40 && rotationx>0) {
			translatey = 0.7;

		}
		else if (rotationx < 53 && rotationx>0) {
			translatey = 0.75;

		}
		else if (rotationx > -15 && rotationx < 0) {
			translatey = 0.55;
		}
		else if (rotationx > -40 && rotationx < 0) {
			translatey = 0.5;

		}
		else if (rotationx > -53 && rotationx < 0) {
			translatey = 0.45;

		}
	}

	glutPostRedisplay();
}

void Anim() {

	if (gameon == true) {

		if (replay == false) {



			if (straight == true && translatez > 0) {
				translatez = translatez - 0.004;
				translatey = translatey + 0.0001;
				if (translatez <= 0) {
					if (round1 == -1) {
						round1 = 0;


					}
					else if (round2 == -1) {
						round2 = 0;
					}
					else if (round3 == -1) {
						round3 = 0;
					}
				}





				if (mode == 1 || mode == 2) {
					z2 = z2 - 0.002;
					z3 = z3 - 0.002;



				}
				//y2 = y2 + 0.00001;
				if (rotationy > 0 && translatex<0.5 && translatex>-0.5) {
					translatex = translatex + 0.0001;



				}
				else if (rotationy < 0 && translatex<0.5 && translatex>-0.5) {
					translatex = translatex - 0.0001;

				}










			}
			else if (path == 1) {
				if (mode == 1) {
					z2 = z2 - 0.001;
					y2 = y2 - 0.00016;
					//z3 = 0;
				}

				if (translatex <= 0.5 && translatey <= 1 && translatez >= 1) {


					translatex = translatex + 0.0008;
					translatey = translatey + 0.00076;
					translatez = translatez - 0.002;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						y2 = y2 - 0.001;
						z3 = z3 - 0.001;
						z2 = z2 - 0.001;
					}


				}

				else if (translatex > -0.49 && translatey <= 1.2 && translatez <= 1.3) {
					translatex = translatex - 0.0022;
					translatey = translatey + 0.0004;
					translatez = translatez + 0.001;
					if (mode == 2) {

						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.001;
						z2 = z2 - 0.001;
					}
				}
				else if (translatex < 0 && translatez >0) {
					translatex = translatex + 0.0025;
					translatey = translatey - 0.000005;
					translatez = translatez - 0.0005;
					if (mode == 2) {

						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.001;
						z2 = z2 - 0.001;
					}
				}

				else {
					path = -10;

					if (round1 == -1) {
						round1 = 50;

					}
					else if (round2 == -1) {
						round2 = 50;
					}
					else if (round3 == -1) {
						round3 = 50;
					}


				}
			}

			else if (path == -1) {
				if (mode == 1) {
					z2 = z2 - 0.001;
					//z3 = 0;
				}

				if (translatex >= -0.5 && translatey <= 1 && translatez >= 1) {


					translatex = translatex - 0.0008;
					translatey = translatey + 0.00076;
					translatez = translatez - 0.002;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						y2 = y2 - 0.001;
						z3 = z3 - 0.001;
						z2 = z2 - 0.001;
					}

				}

				else if (translatex < 0.49 && translatey <= 1.2 && translatez <= 1.3) {
					translatex = translatex + 0.0022;
					translatey = translatey + 0.0004;
					translatez = translatez + 0.001;
					if (mode == 2) {

						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.001;
						z2 = z2 - 0.001;
					}

				}

				else if (translatex > 0 && translatez > 0) {
					translatex = translatex - 0.0025;
					translatey = translatey - 0.000005;
					translatez = translatez - 0.0005;
					//cout << translatez;

					if (mode == 2) {

						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.001;
						z2 = z2 - 0.001;
					}
				}
				else {
					path = -10;
					if (round1 == -1) {
						round1 = 45;

					}
					else if (round2 == -1) {
						round2 = 45;
					}
					else if (round3 == -1) {
						round3 = 45;
					}
				}


			}
			else if (path == 2) {

				if (mode == 1) {
					//z3 = translatez;
					z2 = z2 - 0.0003;
					y2 = y2 - 0.0001;
					//z3 = 0;
				}

				if (translatex < 0.45 && translatey <= 1 && translatez >= 1.5) {


					translatex = translatex + 0.0007;
					translatey = translatey + 0.00076;
					translatez = translatez - 0.0004;

					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						y2 = y2 - 0.0005;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
					}


				}

				else if (translatex > -0.45 && translatey <= 1.2 && translatez > 1.3) {
					translatex = translatex - 0.0022;
					translatey = translatey + 0.0004;
					translatez = translatez - 0.0004;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}



				}

				else if (translatex < 0.45 && translatey <= 1.3 && translatez >= 0.7) {
					translatex = translatex + 0.0022;
					translatey = translatey + 0.0002;
					translatez = translatez - 0.0012;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
					}
					//cout << translatez;
				}

				else if (translatex > -0.45 && translatey >= 0.9) {
					translatex = translatex - 0.0025;
					translatey = translatey - 0.0008;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//translatez = translatez + 0.0004;
						//cout << translatez;
					}
				}

				else if (translatex <= 1 && translatey <= 1 && translatez >= 0) {
					translatex = translatex + 0.0011;
					translatey = translatey + 0.0002;
					translatez = translatez - 0.0014;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}
				}

				else {
					path = -10;
					if (round1 == -1) {
						round1 = 105;

					}
					else if (round2 == -1) {
						round2 = 105;
					}
					else if (round3 == -1) {
						round3 = 105;
					}
				}
			}




			else if (path == -2) {
				if (mode == 1) {
					//z3 = translatez;
					z2 = z2 - 0.0003;
					y2 = y2 - 0.0001;
					//z3 = 0;
				}

				if (translatex > -0.45 && translatey <= 1 && translatez >= 1.5) {


					translatex = translatex - 0.0007;
					translatey = translatey + 0.00076;
					translatez = translatez - 0.0004;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						y2 = y2 - 0.0005;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
					}


				}

				else if (translatex < 0.45 && translatey <= 1.2 && translatez > 1.3) {
					translatex = translatex + 0.0022;
					translatey = translatey + 0.0004;
					translatez = translatez - 0.0004;
					//cout << translatez;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}



				}

				else if (translatex > -0.45 && translatey <= 1.3 && translatez >= 0.7) {
					translatex = translatex - 0.0022;
					translatey = translatey + 0.0002;
					translatez = translatez - 0.0012;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}

				}

				else if (translatex < 0.45 && translatey >= 0.9) {
					translatex = translatex + 0.0025;
					translatey = translatey - 0.0008;
					//translatez = translatez + 0.0004;
					//cout << translatez;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}
				}

				else if (translatex >= 0 && translatey <= 1 && translatez >= 0) {
					translatex = translatex - 0.0011;
					translatey = translatey + 0.0002;
					translatez = translatez - 0.0014;
					//cout << translatez;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}
				}

				else {
					path = -10;
					if (round1 == -1) {
						round1 = 105;

					}
					else if (round2 == -1) {
						round2 = 105;
					}
					else if (round3 == -1) {
						round3 = 105;
					}
				}
			}


			else if (path == 3) {
				if (mode == 1) {
					//z2 = z2 - 0.002;
					//z3 = 0;
					z2 = z2 - 0.0006;
					y2 = y2 - 0.0001;
				}

				if (translatex < 0.17 && translatey <= 1.4 && translatez>1.78) {


					translatex = translatex + 0.0008;
					translatey = translatey + 0.0076;
					translatez = translatez - 0.0002;
					//cout << translatez;
					//translatex= 0.15
					//translatey= 1.4
					//translatez= 1.78
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						y2 = y2 - 0.0005;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
					}


				}

				else if (translatex > -0.3 && translatey >= 0.45 && translatez >= 0.5) {
					translatex = translatex - 0.001;
					translatey = translatey - 0.002;
					translatez = translatez - 0.00375;
					//cout << translatey;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}


				}

				else if (translatex <= 0.3 && translatey < 0.9 && translatez >= 0) {
					translatex = translatex + 0.002;
					translatey = translatey + 0.0005;
					translatez = translatez - 0.0015;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}



				}

				else {
					path = -10;
					if (round1 == -1) {
						round1 = 10;

					}
					else if (round2 == -1) {
						round2 = 10;
					}
					else if (round3 == -1) {
						round3 = 10;
					}
				}
			}

			else if (path == -3) {
				if (mode == 1) {
					//z2 = z2 - 0.002;
					//z3 = 0;
					z2 = z2 - 0.0006;
					y2 = y2 - 0.0001;
				}

				if (translatex > -0.17 && translatey <= 1.4 && translatez > 1.78) {


					translatex = translatex - 0.0008;
					translatey = translatey + 0.0076;
					translatez = translatez - 0.0002;
					//cout << translatez;
					//translatex= 0.15
					//translatey= 1.4
					//translatez= 1.78
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						y2 = y2 - 0.0005;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
					}


				}

				else if (translatex < 0.3 && translatey >= 0.45 && translatez >= 0.5) {
					translatex = translatex + 0.001;
					translatey = translatey - 0.002;
					translatez = translatez - 0.00375;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}



				}

				else if (translatex >= -0.3 && translatey < 0.7 && translatez >= 0) {
					translatex = translatex - 0.002;
					translatey = translatey + 0.00005;
					translatez = translatez - 0.0015;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}



				}

				else {
					path = -10;
					if (round1 == -1) {
						round1 = 25;

					}
					else if (round2 == -1) {
						round2 = 25;
					}
					else if (round3 == -1) {
						round3 = 25;
					}
				}
			}

			else if (path == 4) {

				if (mode == 1) {
					//z2 = z2 - 0.002;
					//z3 = 0;
					z2 = z2 - 0.0006;
					y2 = y2 - 0.0001;
				}

				if (translatex < 0.17 && translatey >= -1.4 && translatez>1.78) {


					translatex = translatex + 0.0004;
					translatez = translatez - 0.0001;
					//cout << translatey;
					//translatex= 0.15
					//translatey= 1.4
					//translatez= 1.78
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						y2 = y2 - 0.0005;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
					}


				}

				else if (translatex > -0.3 && translatey <= 1.4 && translatez >= 0.5) {
					translatex = translatex - 0.0005;
					translatey = translatey + 0.0015;
					translatez = translatez - 0.0025;
					//cout << translatez;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}



				}

				else if (translatex <= 0.3 && translatey > 0.7 && translatez >= 0) {
					translatex = translatex + 0.0015;
					translatey = translatey - 0.0008;
					translatez = translatez - 0.00075;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}




				}

				else {
					path = -10;
					if (round1 == -1) {
						round1 = 60;

					}
					else if (round2 == -1) {
						round2 = 60;
					}
					else if (round3 == -1) {
						round3 = 60;
					}
				}
			}

			else if (path == -4) {


				if (mode == 1) {
					//z2 = z2 - 0.002;
					//z3 = 0;
					z2 = z2 - 0.0006;
					y2 = y2 - 0.0001;
				}

				if (translatex > -0.17 && translatey >= -1.4 && translatez > 1.78) {


					translatex = translatex - 0.0004;
					translatez = translatez - 0.0001;
					//cout << translatey;
					//translatex= 0.15
					//translatey= 1.4
					//translatez= 1.78
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						y2 = y2 - 0.0005;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
					}


				}

				else if (translatex < 0.3 && translatey <= 1.4 && translatez >= 0.5) {
					translatex = translatex + 0.0005;
					translatey = translatey + 0.0015;
					translatez = translatez - 0.0025;
					//cout << translatez;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}



				}

				else if (translatex >= -0.3 && translatey > 0.7 && translatez >= 0) {
					translatex = translatex - 0.0015;
					translatey = translatey - 0.0008;
					translatez = translatez - 0.00075;
					if (mode == 2) {
						y3 = translatey;
						x3 = translatex;
						z3 = z3 - 0.0004;
						z2 = z2 - 0.0004;
						//cout << translatez;
					}

				}

				else {
					path = -10;
					if (round1 == -1) {
						round1 = 60;

					}
					else if (round2 == -1) {
						round2 = 60;
					}
					else if (round3 == -1) {
						round3 = 60;
					}
				}
			}





			else if (shoot == true) {
				translatex = 0.0;
				translatey = 0.6;
				translatez = 1.8;
				rotationx = 0;
				rotationy = 0;
				path = -10;
				x2 = 0.0;
				y2 = 2.0;
				//y2 = 1.7;
				z2 = 5.5;
				//z2 = 4;

				x3 = 0;
				y3 = 0;
				z3 = 0.5;

				straight = false;
				rounds = rounds + 1;
				shoot = false;

			}



		}




		else {

			if (lastpath == 1) {

				//z3 = translatez;
				z2 = z2 - 0.0003;
				y2 = y2 - 0.000037;
				//z3 = 0;


				if (translatex <= 0.5 && translatey <= 1 && translatez >= 1) {


					translatex = translatex + 0.0002;
					translatey = translatey + 0.00019;
					translatez = translatez - 0.0005;

				}

				else if (translatex > -0.49 && translatey <= 1.2 && translatez <= 1.3) {
					translatex = translatex - 0.00055;
					translatey = translatey + 0.0001;
					translatez = translatez + 0.00025;

				}
				else if (translatex < 0 && translatez >0) {
					translatex = translatex + 0.000625;
					translatey = translatey - 0.00000125;
					translatez = translatez - 0.000125;

				}

				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					z2 = 5.5;
					x3 = 0;
					y3 = 0;
					z3 = 0.5;

				}
			}

			else if (lastpath == -1) {
				//z3 = translatez;
				z2 = z2 - 0.0003;
				y2 = y2 - 0.000037;
				//z3 = 0;


				if (translatex >= -0.5 && translatey <= 1 && translatez >= 1) {


					translatex = translatex - 0.0002;
					translatey = translatey + 0.00019;
					translatez = translatez - 0.0005;

				}

				else if (translatex < 0.49 && translatey <= 1.2 && translatez <= 1.3) {
					translatex = translatex + 0.00055;
					translatey = translatey + 0.0001;
					translatez = translatez + 0.00025;

				}

				else if (translatex > 0 && translatez > 0) {
					translatex = translatex - 0.000625;
					translatey = translatey - 0.00000125;
					translatez = translatez - 0.000125;
					//cout << translatez;
				}
				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					//y2 = 1.7;
					z2 = 5.5;
					//z2 = 4;

					x3 = 0;
					y3 = 0;
					z3 = 0.5;

				}


			}

			else if (lastpath == 2) {

				//z3 = translatez;
				z2 = z2 - 0.0003;
				y2 = y2 - 0.000037;
				//z3 = 0;

				if (translatex < 0.45 && translatey <= 1 && translatez >= 1.5) {


					translatex = translatex + 0.000175;
					translatey = translatey + 0.00019;
					translatez = translatez - 0.0001;


				}

				else if (translatex > -0.45 && translatey <= 1.2 && translatez > 1.3) {
					translatex = translatex - 0.00055;
					translatey = translatey + 0.0001;
					translatez = translatez - 0.0001;
					//cout << translatez;



				}

				else if (translatex < 0.45 && translatey <= 1.3 && translatez >= 0.7) {
					translatex = translatex + 0.00055;
					translatey = translatey + 0.00005;
					translatez = translatez - 0.0003;
					//cout << translatez;
				}

				else if (translatex > -0.45 && translatey >= 0.9) {
					translatex = translatex - 0.00065;
					translatey = translatey - 0.0002;
					//translatez = translatez + 0.0004;
					//cout << translatez;
				}

				else if (translatex <= 1 && translatey <= 1 && translatez >= 0) {
					translatex = translatex + 0.000275;
					translatey = translatey + 0.00005;
					translatez = translatez - 0.00035;
					//cout << translatez;
				}

				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					z2 = 5.5;
					x3 = 0;
					y3 = 0;
					z3 = 0.5;

				}

			}

			else if (lastpath == -2) {

				//z3 = translatez;
				z2 = z2 - 0.0003;
				y2 = y2 - 0.000037;
				//z3 = 0;

				if (translatex > -0.45 && translatey <= 1 && translatez >= 1.5) {


					translatex = translatex - 0.000175;
					translatey = translatey + 0.00019;
					translatez = translatez - 0.0001;


				}

				else if (translatex < 0.45 && translatey <= 1.2 && translatez > 1.3) {
					translatex = translatex + 0.00055;
					translatey = translatey + 0.0001;
					translatez = translatez - 0.0001;
					//cout << translatez;



				}

				else if (translatex > -0.45 && translatey <= 1.3 && translatez >= 0.7) {
					translatex = translatex - 0.00055;
					translatey = translatey + 0.00005;
					translatez = translatez - 0.0003;
					//cout << translatez;
				}

				else if (translatex < 0.45 && translatey >= 0.9) {
					translatex = translatex + 0.00065;
					translatey = translatey - 0.0002;
					//translatez = translatez + 0.0004;
					//cout << translatez;
				}

				else if (translatex >= -1 && translatey <= 1 && translatez >= 0) {
					translatex = translatex - 0.000275;
					translatey = translatey + 0.00005;
					translatez = translatez - 0.00035;
					//cout << translatez;
				}

				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					z2 = 5.5;
					x3 = 0;
					y3 = 0;
					z3 = 0.5;

				}

			}

			else if (lastpath == 3) {

				//z3 = translatez;
				z2 = z2 - 0.0005;
				y2 = y2 - 0.000037;
				//z3 = 0;


				if (translatex < 0.17 && translatey <= 1.4 && translatez>1.78) {


					translatex = translatex + 0.0002;
					translatey = translatey + 0.0019;
					translatez = translatez - 0.00005;
					//cout << translatez;
					//translatex= 0.15
					//translatey= 1.4
					//translatez= 1.78


				}

				else if (translatex > -0.3 && translatey >= 0.45 && translatez >= 0.5) {
					translatex = translatex - 0.00025;
					translatey = translatey - 0.0005;
					translatez = translatez - 0.0009375;


				}

				else if (translatex <= 0.3 && translatey < 0.7 && translatez >= 0) {
					translatex = translatex + 0.0005;
					translatey = translatey + 0.0000125;
					translatez = translatez - 0.000375;



				}

				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					z2 = 5.5;
					x3 = 0;
					y3 = 0;
					z3 = 0.5;
				}
			}

			else if (lastpath == -3) {

				//z3 = translatez;
				z2 = z2 - 0.0005;
				y2 = y2 - 0.000037;
				//z3 = 0;


				if (translatex > -0.17 && translatey <= 1.4 && translatez > 1.78) {


					translatex = translatex - 0.0002;
					translatey = translatey + 0.0019;
					translatez = translatez - 0.00005;
					//cout << translatez;
					//translatex= 0.15
					//translatey= 1.4
					//translatez= 1.78


				}

				else if (translatex < 0.3 && translatey >= 0.45 && translatez >= 0.5) {
					translatex = translatex + 0.00025;
					translatey = translatey - 0.0005;
					translatez = translatez - 0.0009375;


				}

				else if (translatex > -0.3 && translatey < 0.7 && translatez >= 0) {
					translatex = translatex - 0.0005;
					translatey = translatey + 0.0000125;
					translatez = translatez - 0.000375;



				}

				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					z2 = 5.5;
					x3 = 0;
					y3 = 0;
					z3 = 0.5;
				}
			}

			else if (lastpath == 4) {

				//z3 = translatez;
				z2 = z2 - 0.0004;
				y2 = y2 - 0.000042;
				//z3 = 0;



				if (translatex < 0.17 && translatey >= -1.4 && translatez>1.78) {


					translatex = translatex + 0.0001;
					translatez = translatez - 0.000025;
					//cout << translatey;
					//translatex= 0.15
					//translatey= 1.4
					//translatez= 1.78


				}

				else if (translatex > -0.3 && translatey <= 1.4 && translatez >= 0.5) {
					translatex = translatex - 0.000125;
					translatey = translatey + 0.000375;
					translatez = translatez - 0.000625;
					//cout << translatez;


				}

				else if (translatex <= 0.3 && translatey > 0.7 && translatez >= 0) {
					translatex = translatex + 0.000375;
					translatey = translatey - 0.0002;
					translatez = translatez - 0.0001875;



				}

				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					z2 = 5.5;
					x3 = 0;
					y3 = 0;
					z3 = 0.5;

				}



			}

			else if (lastpath == -4) {

				//z3 = translatez;
				z2 = z2 - 0.0004;
				y2 = y2 - 0.000042;
				//z3 = 0;


				if (translatex > -0.17 && translatey >= -1.4 && translatez > 1.78) {


					translatex = translatex - 0.0001;
					translatez = translatez - 0.000025;
					//cout << translatey;
					//translatex= 0.15
					//translatey= 1.4
					//translatez= 1.78


				}

				else if (translatex < 0.3 && translatey <= 1.4 && translatez >= 0.5) {
					translatex = translatex + 0.000125;
					translatey = translatey + 0.000375;
					translatez = translatez - 0.000625;
					//cout << translatez;


				}

				else if (translatex >= 0.3 && translatey > 0.7 && translatez >= 0) {
					translatex = translatex - 0.000375;
					translatey = translatey - 0.0002;
					translatez = translatez - 0.0001875;



				}

				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					z2 = 5.5;
					x3 = 0;
					y3 = 0;
					z3 = 0.5;
				}



			}

			else if (lastpath == 0) {

				z2 = z2 - 0.0002;
				z3 = z3 - 0.0002;





				if (translatez > 0) {
					translatez = translatez - 0.001;
					translatey = translatey + 0.000025;
					if (rotationy > 0 && translatex<0.5 && translatex>-0.5) {
						translatex = translatex + 0.000025;


					}
					else if (rotationy < 0 && translatex<0.5 && translatex>-0.5) {
						translatex = translatex - 0.000025;

					}



				}
				else {
					lastpath = -10;
					replay = false;
					translatex = 0.0;
					translatey = 0.6;
					translatez = 1.8;
					rotationx = 0;
					rotationy = 0;
					x2 = 0.0;
					y2 = 2.0;
					z2 = 5.5;
					x3 = 0;
					y3 = 0;
					z3 = 0.5;

				}
			}

			else {
				lastpath = -10;
				replay = false;
				translatex = 0.0;
				translatey = 0.6;
				translatez = 1.8;
				rotationx = 0;
				rotationy = 0;
				x2 = 0.0;
				y2 = 2.0;
				z2 = 5.5;
				x3 = 0;
				y3 = 0;
				z3 = 0.5;
				cout << 'here';
			}






		}
	}
	glutPostRedisplay();
}




void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("OpenGL - 3D Template");
	glutDisplayFunc(Display);


	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45.0f, 1000 / 600, 0.1f, 300.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.0f, 2.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glutIdleFunc(Anim);
	glutSpecialFunc(processSpecialKeys);
	glutSpecialUpFunc(keySpecialUp);
	glutKeyboardFunc(Key);
	glutMainLoop();
}
