#pragma once
#include "Shape.h"
#include "ShapeBuilder.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

template<class T> //template for this class
class CuboidBuilder : public ShapeBuilder<T> {
public:
	CuboidBuilder() {}
	virtual inline T volume() { return h*w*l; } //return volume of cuboid
	virtual inline T base_area() { return w*l; } //return base area of cuboid
	virtual Shape<T> Para_In(ShapeBuilder<T> *s);	//Function which taking in dimension parameters(not inline as definition is big!)
	~CuboidBuilder(){}  
protected:
private:
	Shape<T> object;
	T w; // width of the cuboid
	T l; // length of the cuboid
};

template<class T>
Shape<T> CuboidBuilder<T>::Para_In(ShapeBuilder<T> *s)
{
	cout << "\nWhat is the height?(cm)\t";
	cin >> h;
	cout << "What is the width?(cm)\t";
	cin >> w;
	cout << "What is the length?(cm)\t";
	cin >> l;

	object.setH(h); //set the height of cuboid
	object.setW(w); //set the width of cuboid
	object.setL(l); //set length of cuboid

	cout << "\nVolume of this cuboid sensor is (cm^3):\t" << s->volume() << "\n\n";
	object.setV(s->volume()); //calculate volume of cuboid
	object.setBA(s->base_area()); //calculate base area of cuboid

	return object; //return entire object to the vector in the main program
	//returning entire objects grants us access to every member associated with this object
}