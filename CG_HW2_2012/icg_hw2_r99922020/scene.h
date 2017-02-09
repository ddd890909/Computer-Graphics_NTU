
#ifndef SCENE_H
#define SCENE_H

#include "utils.h"
#include <vector>
using namespace std;

class Camera {
public:
	int lookAtDist;
	Vector position;
	Vector lookAt;
	Vector up;
	Vector revAngle; // revolution: yaw, pitch, roll
	Matrix4x4 rotate; // rotation
	
	Camera();
	void initTransform();
	void updateRotation(float angle, float x, float y, float z);
	void updateRevolution(float angle, int x, int y, int z);
	friend ostream &operator<< (ostream &os, const Camera &tri);
};

class Model {
public:
	vector<Triangle> triangleList;
	Vector center;
	Vector max, min; // bbox
	Vector translate;
	Vector scale;
	Matrix4x4 rotate; 
	Matrix4x4 shear; 
	Vector ambient, diffuse, specular;
	float shininess;
	
	Model();
	bool loadFromFile(const char* fileName);
	void copy(Model *);
	void unifromScale(float s);
	void drawAxes();
	void drawBBox();
	void drawModel(int mode = 0);
	void initTransform();
	void initMaterial();
	void updateMaterial(); 
	void updateRotation(float angle, float x, float y, float z, bool useWorldCoord = true);
	void updateShear(float angle, int to, int from);
	friend ostream &operator<< (ostream &os, const Model &tri);
};

class Light {
public:
	int index;
	bool isOn;
	int dist;
	Vector position;
	Vector revAngle;  // revolution: yaw, pitch, roll
	Vector ambient, diffuse, specular;
	float constAtt, linearAtt, quadAtt;

	Light() {}
	Light(int idx);
	void initTransform();
	void initLightParam();
	void updatePosition();
	void updateColor();
	void updateAttenuation();
	void updateRevolution(float angle, int x, int y, int z);
	friend ostream &operator<< (ostream &os, const Light &tri);
};

#endif