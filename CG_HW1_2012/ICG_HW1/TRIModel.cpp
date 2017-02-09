/* 
NTU CSIE ICG2012
R01944040 Liu Chengyin
*/

#include "TRIModel.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <GL/glut.h>
using namespace std;

#define MIN_DIAG_LEN 1000

void Triangle::setColor(int fcolor[3], int bcolor[3])
{
	for(int i = 0; i < 3; i++)
		frontColor[i] = (float)fcolor[i] / 255;
	for(int i = 0; i < 3; i++)
		backColor[i] = (float)bcolor[i] / 255;
}

istream &operator>> (istream &is, Triangle &tri)
{
	// color
	int fcolor[3], bcolor[3];
	for(int i = 0; i < 3; i++)
		is >> fcolor[i];
	for(int i = 0; i < 3; i++)
		is >> bcolor[i];
	tri.setColor(fcolor, bcolor);
	// coordidates & normal
	for(int i = 0; i < 3; i++) 
	{
		is >> tri.vertex[i].x >> tri.vertex[i].y >> tri.vertex[i].z;
		is >> tri.normal[i].x >> tri.normal[i].y >> tri.normal[i].z;
	}
	return is;
}
   
ostream &operator<< (ostream &os, const Triangle &tri)
{
	for(int i = 0; i < 3; i++) 
		os << "vertex " << i + 1 << ": " << tri.vertex[i].x << ", " << tri.vertex[i].y << ", " << tri.vertex[i].z << endl;
	os << endl;
    return os;
}


bool TRIModel::loadFromFile(const char* fileName)
{
	char str[20] = {0};
	max.x = max.y = max.z = -100000.0;
	min.x = min.y = min.z = 100000.0;

	fstream inFile(fileName, fstream::in);
	if(!inFile)
	{
		cout << "Can not open object File \"" << fileName << "\" !" << endl;
		return false;
	}

	// clean up the old data
	triangleList.clear();

	cout << "Loading \"" << fileName << "\" !" << endl;
	while(1) 
	{
		// model mesh type
		inFile >> str;
		if(inFile.eof())
			break;
		// read a triangle
		Triangle triTmp;
		inFile >> triTmp;
		if(triTmp.vertex[0].x == 0.0 && triTmp.vertex[0].y == 0.0 && triTmp.vertex[0].z == 0.0)
			printf("%d\n", triangleList.size());
		// for each of the 3 vetices
		for(int j = 0; j < 3; j++) 
		{
			// x, y, z
			for(int k = 0; k < 3; k++) 
			{
				if(triTmp.vertex[j][k] < min[k])
					min[k] = triTmp.vertex[j][k];
				if(triTmp.vertex[j][k] > max[k])
					max[k] = triTmp.vertex[j][k];
			}
		}
		triangleList.push_back(triTmp);
	}
	inFile.close();

	// calculate center
	center = (min + max) / 2;
	// center the model
	max -= center;
	min -= center;
	for(unsigned int i = 0; i < triangleList.size(); i++) 
		for(int j = 0; j < 3; j++) 
			triangleList[i].vertex[j] -= center;
	center.x = center.y = center.z = 0.0;

	// upscale uniformly
	float diag = (max - min).length();
	if(diag < MIN_DIAG_LEN)
		unifromScale(MIN_DIAG_LEN / diag);

	return true;
}

void TRIModel::copy(TRIModel * t)
{
	for(int i = 0; i < 3; i++){
		center[i] = t->center[i];
		max[i] = t->max[i];
		min[i] = t->min[i];
	}
	triangleList = t->triangleList;
}

TRIModel::TRIModel(){
}

TRIModel::~TRIModel(){
}


void TRIModel::drawAxes()
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glBegin(GL_LINES);
		// x axis
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(300.0, 0.0, 0.0);
		// y axis
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 300.0, 0.0);
		// z axis
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 300.0);
	glEnd();
	glPopMatrix();
}

void TRIModel::drawBox()
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
		glVertex3f(max.x, max.y, max.z);
		glVertex3f(max.x, min.y, max.z);
		glVertex3f(max.x, min.y, min.z);
		glVertex3f(max.x, max.y, min.z);

		glVertex3f(max.x, max.y, max.z);
		glVertex3f(min.x, max.y, max.z);
		glVertex3f(min.x, min.y, max.z);
		glVertex3f(max.x, min.y, max.z);

		glVertex3f(max.x, max.y, max.z);
		glVertex3f(min.x, max.y, max.z);
		glVertex3f(min.x, max.y, min.z);
		glVertex3f(max.x, max.y, min.z);
		
		glVertex3f(min.x, min.y, min.z);
		glVertex3f(min.x, max.y, min.z);
		glVertex3f(min.x, max.y, max.z);
		glVertex3f(min.x, min.y, max.z);

		glVertex3f(min.x, min.y, min.z);
		glVertex3f(max.x, min.y, min.z);
		glVertex3f(max.x, max.y, min.z);
		glVertex3f(min.x, max.y, min.z);

		glVertex3f(min.x, min.y, min.z);
		glVertex3f(max.x, min.y, min.z);
		glVertex3f(max.x, min.y, max.z);
		glVertex3f(min.x, min.y, max.z);
	glEnd();
	glPopMatrix();
}

void TRIModel::drawModel()
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glBegin(GL_LINES);
	for(unsigned int i = 0; i < triangleList.size(); i++) 
	{
		Triangle tri = triangleList[i];
		// set color
		glColor3f(tri.frontColor.r, tri.frontColor.g, tri.frontColor.b);
		// draw the model using lines
		for(int j = 0; j < 3; j++)
		{
			glVertex3f(tri.vertex[j].x, tri.vertex[j].y, tri.vertex[j].z);
			glVertex3f(tri.vertex[(j + 1) % 3].x, tri.vertex[(j + 1) % 3].y, tri.vertex[(j + 1) % 3].z);
		}
	}
	glEnd();
	glPopMatrix();
}

void TRIModel::initTransform()
{
	// translation
	//translate[0] = translate[1] = translate[2] = 0.0;
	translate.setIdentity();
	// scaling
	//scale[0] = scale[1] = scale[2] = 1.0;
	scale.setIdentity();
	// shear
	shear.setIdentity();
	// rotation
	rotate.setIdentity();
}

void TRIModel::unifromScale(float s)
{
	if(s == 0.0)	return;

	for(int i = 0; i < 3; i++)
	{
		min[i] *= s;
		max[i] *= s;
	}
	for(unsigned int i = 0; i < triangleList.size(); i++) 
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++) 
			{
				triangleList[i].vertex[j][k] *= s;
			}
		}
	}
}

void TRIModel::updateScale(float x, float y, float z) 
{
	float tmp[16] = {0};
	tmp[0] = x;
	tmp[5] = y;
	tmp[10] = z;
	tmp[15] = 1.0;

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(tmp);
	glMultMatrixf(scale.m);
    glGetFloatv(GL_MODELVIEW_MATRIX, scale.m);
	glPopMatrix();
}

void TRIModel::updateTranslate(float x, float y, float z) 
{
	float tmp[16] = {0};
	tmp[0] = tmp[5] = tmp[10] = tmp[15] = 1.0;
	tmp[12] = x;
	tmp[13] = y;
	tmp[14] = z;

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(tmp);
	glMultMatrixf(translate.m);
    glGetFloatv(GL_MODELVIEW_MATRIX, translate.m);
	glPopMatrix();
}

void TRIModel::updateShear(float angle, int to, int from) 
{
	float tmp[16] = {0};
	tmp[0] = tmp[5] = tmp[10] = tmp[15] = 1.0;
	tmp[from * 4 + to] = tan(DegToRad(angle));

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(tmp);
	glMultMatrixf(shear.m);
    glGetFloatv(GL_MODELVIEW_MATRIX, shear.m);
	glPopMatrix();
}

void TRIModel::updateRotationx(float angle, float x, float y, float z) 
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//if(useWorldCoord) 
	//{
		//glRotatef(angle, x, y, z);
	    float tmp[16] = {0};
	    tmp[5] = cos(DegToRad(angle));
		tmp[6] = sin(DegToRad(angle));
		tmp[9] = -sin(DegToRad(angle));
		tmp[10] = cos(DegToRad(angle));
		tmp[0] = 1;
	    tmp[15] = 1;
		glLoadMatrixf(tmp);
	    glMultMatrixf(rotate.m);
	//}
	//else {
	//	glMultMatrixf(mObjRotate.m);
	//	glRotatef(angle, x, y, z);
	//}
    glGetFloatv(GL_MODELVIEW_MATRIX, rotate.m);
	glPopMatrix();
}

void TRIModel::updateRotationy(float angle, float x, float y, float z) 
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//if(useWorldCoord) 
	//{
		//glRotatef(angle, x, y, z);
	    float tmp[16] = {0};
	    tmp[0] = cos(DegToRad(angle));
		tmp[8] = sin(DegToRad(angle));
		tmp[2] = -sin(DegToRad(angle));
		tmp[10] = cos(DegToRad(angle));
		tmp[5] = 1;
	    tmp[15] = 1;
		glLoadMatrixf(tmp);
	    glMultMatrixf(rotate.m);
	//}
	//else {
	//	glMultMatrixf(mObjRotate.m);
	//	glRotatef(angle, x, y, z);
	//}
    glGetFloatv(GL_MODELVIEW_MATRIX, rotate.m);
	glPopMatrix();
}

void TRIModel::updateRotationz(float angle, float x, float y, float z) 
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//if(useWorldCoord) 
	//{
		//glRotatef(angle, x, y, z);
	    float tmp[16] = {0};
	    tmp[0] = cos(DegToRad(angle));
		tmp[1] = sin(DegToRad(angle));
		tmp[4] = -sin(DegToRad(angle));
		tmp[5] = cos(DegToRad(angle));
		tmp[10] = 1;
	    tmp[15] = 1;
		glLoadMatrixf(tmp);
	    glMultMatrixf(rotate.m);
	//}
	//else {
	//	glMultMatrixf(mObjRotate.m);
	//	glRotatef(angle, x, y, z);
	//}
    glGetFloatv(GL_MODELVIEW_MATRIX, rotate.m);
	glPopMatrix();
}


void Camera::initTransform() 
{
	lookAtDist = 1000;
	// position
	position[0] = position[1] = 0.0;  position[2] = lookAtDist;
	// look at
	lookAt[0] = lookAt[1] = lookAt[2] = 0.0;
	// up vector
	up[0] = up[2] = 0.0;  up[1] = 1.0;
	// angles
	revAngle[0] = revAngle[1] = revAngle[2] = 0.0;
	//rotate
	rotate.setIdentity();
}

void Camera::updateRotationx(float angle, float x, float y, float z)
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	//glRotatef(angle, x, y, z);
	float tmp[16] = {0};
	    tmp[5] = cos(DegToRad(angle));
		tmp[6] = sin(DegToRad(angle));
		tmp[9] = -sin(DegToRad(angle));
		tmp[10] = cos(DegToRad(angle));
		tmp[0] = 1;
	    tmp[15] = 1;
	glLoadMatrixf(tmp);
	glMultMatrixf(rotate.m);
    glGetFloatv(GL_MODELVIEW_MATRIX, rotate.m);
	glPopMatrix();
}

void Camera::updateRotationy(float angle, float x, float y, float z)
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	//glRotatef(angle, x, y, z);
	float tmp[16] = {0};
	    tmp[0] = cos(DegToRad(angle));
		tmp[8] = sin(DegToRad(angle));
		tmp[2] = -sin(DegToRad(angle));
		tmp[10] = cos(DegToRad(angle));
		tmp[5] = 1;
	    tmp[15] = 1;
	glLoadMatrixf(tmp);
	glMultMatrixf(rotate.m);
    glGetFloatv(GL_MODELVIEW_MATRIX, rotate.m);
	glPopMatrix();
}

void Camera::updateRotationz(float angle, float x, float y, float z)
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	//glRotatef(angle, x, y, z);
	float tmp[16] = {0};
	    tmp[0] = cos(DegToRad(angle));
		tmp[1] = sin(DegToRad(angle));
		tmp[4] = -sin(DegToRad(angle));
		tmp[5] = cos(DegToRad(angle));
		tmp[10] = 1;
	    tmp[15] = 1;
	glLoadMatrixf(tmp);
	glMultMatrixf(rotate.m);
    glGetFloatv(GL_MODELVIEW_MATRIX, rotate.m);
	glPopMatrix();
}

void Camera::updateRevolution(float angle, int x, int y, int z) 
{
	if(x == 1)
		revAngle[0] = angle;
	else if(y == 1)
		revAngle[1] = angle;
	else if(z == 1)
		revAngle[2] = angle;

	float yaw = DegToRad(revAngle[0]);
	float pitch = DegToRad(revAngle[1]);
	
	position.x = lookAtDist * cosf(pitch) * sinf(yaw) - lookAt[0];
	position.y = lookAtDist * sinf(pitch)             - lookAt[1];
	position.z = lookAtDist * cosf(pitch) * cosf(yaw) - lookAt[2];

	up.x = -sinf(pitch) * sinf(yaw);
	up.y =  cosf(pitch);
	up.z = -sinf(pitch) * cosf(yaw);
}