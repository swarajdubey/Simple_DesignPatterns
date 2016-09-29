#pragma once
#define _USE_MATH_DEFINES //keyword to acesss default PI value in math library 
#include <iostream>
#include <string>
using namespace std;

template<class T> //template for this class
class Shape {
public:
	Shape(){}
	//make these functions inline as the definition is not big which makes the execution time faster

	//setters (set dimensions)
	inline void setV(const T &v) { volume = v; } //set volume of shape		
	inline void setBA(const T &ba) { base_area = ba; } //set base area of shape
	inline void setH(const T &height) { h = height; }	//set height of shape
	inline void setW(const T &width) { w = width; } //set width of shape
	inline void setL(const T &length) { l = length; }	//set length of shape
	inline void setR(T radius) { r = radius; }			//set radius parameter value

	//getters (return dimensions)
	inline T getV() { return volume; } //return volume of the shape	
	inline T getBA() { return base_area; } //return base area of the shape
	inline T getH() { return h; } //return height of the object(depends on object calling this)
	inline T getW() { return w; } //return width of the cuboid
	inline T getL() { return l; } //return length of the object(depends on object calling this)
	inline T getR() { return r; } //return radius of cylinder

	~Shape() {}

protected:
	T h; //height of shape
	T w; //width of shape
	T l; //length of shape(cylinder in this case)
	T r; //radius of shape(cylinder in this case)
	T volume; //volume of shape
	T base_area; //base area of shape


	//Singleton 
	static Shape<T> *getShapteInstance() {
		if (!shape_instance)
			shape_instance = new Shape<T>;
		return shape_instance;
	}

	static void destroyInstance()
	{
		delete shape_instance;
		shape_instance = NULL;
	}
private:
	static Shape<T> *shape_instance;
};

template<class T>

Shape<T> *Shape<T>::shape_instance = 0; //initialize the instance to null