/* 
NTU CSIE ICG2012
R01944040 Liu Chengyin
*/

#include <iostream>
#include <vector>
#include "utils.h"

#pragma once

using namespace std;


class Triangle
{
public:
	Vector vertex[3];
	Vector normal[3];
	Vector frontColor;
	Vector backColor;
	
	Triangle() {}
	void setColor(int fcolor[3], int bcolor[3]);  // color: 0~255 -> 0~1
	
	friend istream &operator>> (istream &is, Triangle &tri);
	friend ostream &operator<< (ostream &os, const Triangle &tri);

};

class TRIModel
{
public:
	vector<Triangle> triangleList;
	Vector center;

	bool loadFromFile(const char* fileName);
	void copy(TRIModel *);

	TRIModel();
	~TRIModel();
	
	Vector max, min; 
	//Vector translate;
	//Vector scale;
	Matrix4x4 rotate; 
	Matrix4x4 shear; 
	Matrix4x4 translate;
	Matrix4x4 scale;
	
	void initTransform();
	void drawAxes();
	void drawBox();
	void drawModel();

	void unifromScale(float s);

	void updateScale(float x, float y, float z);
	void updateTranslate(float x, float y, float z);
	void updateRotationx(float angle, float x, float y, float z);
	void updateRotationy(float angle, float x, float y, float z);
	void updateRotationz(float angle, float x, float y, float z);
	void updateShear(float angle, int to, int from);

};

class Camera 
{
public:
	int lookAtDist;
	Vector position;
	Vector lookAt;
	Vector up;
	Vector revAngle; // revolution: yaw, pitch, roll
	Matrix4x4 rotate; // rotation

	void initTransform();
	void updateRotationx(float angle, float x, float y, float z);
	void updateRotationy(float angle, float x, float y, float z);
	void updateRotationz(float angle, float x, float y, float z);
	void updateRevolution(float angle, int x, int y, int z);
};