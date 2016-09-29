#pragma once
#include "Shape.h"
#include "ShapeBuilder.h"
#include <iostream>
#include <string>
#include <math.h>
#include<unordered_set>
#include<algorithm>

using namespace std;

template<class T> //template for this class
class CylinderBuilder : public ShapeBuilder<T> {
public:
	CylinderBuilder() {} //constructor for the class
	virtual inline T volume() { return h*M_PI*r*r; } //Volume of the cylinder
	virtual inline T base_area() { return M_PI*r*r; } //Base Area of the cylinder
	virtual Shape<T> Para_In(ShapeBuilder<T> *s);	//function to take in the parameters of the cylinder
	virtual ~CylinderBuilder(){} //destructor for the class
protected:
private:
	Shape<T> object; //include shape object here to point to the Shape class to return the volume
	T r; //height and radius of the cylinder respectively
};

template<class T>
Shape<T> CylinderBuilder<T>::Para_In(ShapeBuilder<T> *s) {

	cout << "\nWhat is the height?(cm)\t";
	cin >> h;
	cout << "What is the radius?(cm)\t";
	cin >> r;

	object.setH(h); //set height of the cylinder
	object.setR(r); //set radius of the cylinder

	cout << "\nVolume of cylindrical stone (cm^3):\t" << s->volume() << "\n\n";
	object.setV(s->volume()); //set volume of the cylinder
	object.setBA(s->base_area());	//set base area of the cylinder

	return object;
}