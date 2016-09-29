#pragma once
#include "Shape.h"
#include <iostream>
#include <string>
#include<vector>
#include <math.h>

using namespace std;

template<class T> //template for this class
class ShapeBuilder {
	
public:
	ShapeBuilder(){}

	//common functions for both cuboid and cylinder hence this class is inherited 
	virtual inline T volume() { return 0; } // volume of the 3d shape
	virtual inline T base_area() { return 0; }	// base area of the 3d shape
	virtual Shape<T> Para_In(ShapeBuilder<T> *s) { return Shape<T>(); } // function to take in 3d shape parameters deppoending on cuboid or cylinder

	// Singleton 
	static ShapeBuilder<T> *objBDM_instance() {
		if (!objBD_instance) //create a new instance of this object if found null
			objBD_instance = new ShapeBuilder<T>;
		return objBD_instance;
	}

	static void destroyShapeBuilder()
	{
		delete objBD_instance;
		objBD_instance = NULL;
	}
	~ShapeBuilder(){} 
protected:
	T h; //height is a common parameter for both cuboid and cylinder hence put it in protected for inheriting it
private:
	static ShapeBuilder<T> *objBD_instance; //static pointer object of this class
};

template<class T>
ShapeBuilder<T> *ShapeBuilder<T>::objBD_instance = 0;