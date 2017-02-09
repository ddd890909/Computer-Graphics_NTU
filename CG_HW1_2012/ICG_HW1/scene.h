/*
#ifndef SCENE_H
#define SCENE_H

#include "utils.h"
#include <vector>
using namespace std;

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
	void updateRotation(float angle, float x, float y, float z);
	void updateRevolution(float angle, int x, int y, int z);
};


class Model 
{
public:
	vector<Triangle> triangleList;
	Vector center;
	Vector max, min; // bbox
	Vector translate;
	Vector scale;
	Matrix4x4 rotate; 
	Matrix4x4 shear; 
	
	Model() {};
	~Model() {};
	bool loadFromFile(const char* fileName);
	void copy(Model *);
	void unifromScale(float s);
	void drawAxes();
	void drawBBox();
	void drawModel();
	void initTransform();
	void updateRotation(float angle, float x, float y, float z);
	void updateShear(float angle, int to, int from);
};


#endif
*/