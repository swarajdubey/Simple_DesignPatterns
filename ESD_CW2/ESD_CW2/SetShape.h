#pragma once
#include "Shape.h"
#include "ShapeBuilder.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

template<class T> //template for this class
class SetShape {
public:
	inline void setObject(ShapeBuilder<T>* b) { objectbuilder = b; } //Builder pattern right here that has one common way to make different object representations
	Shape<T> Build() { return objectbuilder->Para_In(objectbuilder); } //based on the shape selected, prompt the user to the shape parameters 

	static SetShape* getSetShapeInstance()
	{
		if (setshapeinstance == NULL)
		{
			setshapeinstance = new SetShape();
		}
		return setshapeinstance;
	}

	static void destroySetShapeInstance()
	{
		delete setshapeinstance;
		setshapeinstance = NULL;
	}
private:
	ShapeBuilder<T>* objectbuilder; //pointer object that can store either object type(essential part of builder class)
	static SetShape* setshapeinstance;
	SetShape() {}
	~SetShape() {} 
};
template <class T>
SetShape<T>* SetShape<T>::setshapeinstance = NULL;