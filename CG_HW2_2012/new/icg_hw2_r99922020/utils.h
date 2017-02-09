/*
 * NTUCSIE ICG2010
 * R99922020 Yu-Hsiang Huang
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592653589793
#define toRad(deg) (deg * PI / 180)

char *textFileRead(char *fn);
int textFileWrite(char *fn, char *s);

class Vector {
public:
	Vector() { x = y = z = w = 0.0; }
        Vector(float v[3]): x(v[0]), y(v[1]), z(v[2]) {}
        Vector(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
        Vector(float _x, float _y, float _z, float _w): x(_x), y(_y), z(_z), w(_w) {}
	inline Vector operator+ (float s) const { return Vector(x + s, y + s, z + s); }
	inline Vector operator- (float s) const { return Vector(x - s, y - s, z - s); }
	inline Vector operator* (float s) const { return Vector(x * s, y * s, z * s); }
	inline Vector operator/ (float s) const { return (s != 0.f) ? Vector(x / s, y / s, z / s) : Vector(0.0, 0.0, 0.0); }
	inline Vector operator+ (const Vector &v) const { return Vector(x + v.x, y + v.y, z + v.z); }
	inline Vector operator- (const Vector &v) const { return Vector(x - v.x, y - v.y, z - v.z); }
	Vector &operator+= (const Vector &v);
	Vector &operator-= (const Vector &v);
	inline float operator[] (int axis) const { return (&x)[axis]; }
	inline float &operator[] (int axis) { return (&x)[axis]; }
	inline float length() const { return sqrtf(x * x + y * y + z * z); }
	inline float *vec() { return (float *)&x; }
	
	union {
		float x, r;
	};
	union {
		float y, g;
	};
	union {
		float z, b;
	};
	union {
		float w, a;
	};
};

class Matrix4x4 {
public:
        Matrix4x4() {}
	Matrix4x4(float _m[16]);
	void setIdentity();
	Matrix4x4 &invert() const;
	Vector mul(const Vector &p) const; 
	Matrix4x4 mul(const Matrix4x4 &n) const; 
	inline float operator[] (int idx) const { return m[idx]; }
	inline float& operator[] (int idx) { return m[idx]; }

	float m[16];
};

class Triangle {
public:
	Vector vertex[3];
	Vector normal[3];
	Vector frontColor;
	Vector backColor;
	
	Triangle() {}
	void setColor(int fcolor[3], int bcolor[3]);  // color: 0~255 -> 0~1
	
	friend istream &operator>> (istream &is, Triangle &tri);
};

#endif
