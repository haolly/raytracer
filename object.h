#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "vec3.h"
using namespace std;

enum Type {SPECULAR, DIFFUSED}; 

class Object {

public:

	Vec3 surfaceColor;
	double transparency;
	Type objectType;

	Object(Vec3 surfaceColor, double transparency, Type objectType);
	virtual vector<double> intersectionPoints(const Vec3 &rayOrigin, const Vec3 &rayDirection) = 0;
	virtual Vec3 getNormal(const Vec3 point) = 0;
};

class Sphere : public Object {

public:

	Vec3 center;
	double radius;

	Sphere(Vec3 center, double radius, Vec3 surfaceColor, double transparency, Type objectType);
	vector<double> intersectionPoints(const Vec3 &rayOrigin, const Vec3 &rayDirection);
	Vec3 getNormal(const Vec3 point);
};

class Cylinder : public Object {

public:

	double radius, height;
	Vec3 upVector;

	Cylinder(Vec3 upVector, double radius, double height, Vec3 surfaceColor, double transparency, Type objectType);
	vector<double> intersectionPoints(const Vec3 &rayOrigin, const Vec3 &rayDirection);
	Vec3 getNormal(const Vec3 point);
};

class Cone : public Object {

public:

	double radius, height;
	Vec3 upVector, inclineVector;

	Cone(Vec3 upVector, Vec3 inclineVector, double radius, double height, Vec3 surfaceColor, double transparency, Type objectType);
	vector<double> intersectionPoints(const Vec3 &rayOrigin, const Vec3 &rayDirection);
	Vec3 getNormal(const Vec3 point);
};

class Triangle : public Object {

public:

	Vec3 p1, p2, p3;

	Triangle(Vec3 p1, Vec3 p2, Vec3 p3, Vec3 surfaceColor, double transparency, Type objectType);
	vector<double> intersectionPoints(const Vec3 &rayOrigin, const Vec3 &rayDirection);
	Vec3 getNormal(const Vec3 point);
};

#endif