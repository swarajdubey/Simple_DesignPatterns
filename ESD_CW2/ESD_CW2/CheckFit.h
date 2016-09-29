#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class CheckFit {
public:
	//return true if shape fits in else return false
	//to check if the cuboid fits inside the cylinder

	static CheckFit* getCHeckFitInstance()
	{
		//create only one instance
		if (checkfitinstace == NULL){checkfitinstace = new CheckFit();}
		return checkfitinstace;
	}

	static void destroyUniqueInstace()
	{
		delete checkfitinstace;
		checkfitinstace = NULL;
	}

	bool checkCuboidFitInCylinder(const T &cylinder_height, const T &cylinder_radius, const T &cuboid_length, const T &cuboid_width, const T &cuboid_height)
	{
		if ((2* cylinder_radius)>cuboid_length && (2 * cylinder_radius)>cuboid_width)//if length and width are going in first
		{
			//if height of the cylinder greater than the height of the cuboid
			if (cylinder_height>cuboid_height){return true;}
			else{return false;}
		}
		else if ((2 * cylinder_radius)>cuboid_width && (2 * cylinder_radius)>cuboid_height)
		{
			if (cylinder_height>cuboid_length){return true;}
			else{return false;}
		}
		else{return false;}
	}

	//check if the cylindrical stone can fir inside the container
	bool checkCylinderFitInCylinder(T cylinder_container_height,T cylinder_container_radius, T cylinder_stone_height, T cylinder_stone_radius)
	{
		if (cylinder_container_radius>cylinder_stone_radius && cylinder_container_height>cylinder_stone_height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	CheckFit(){}
	~CheckFit(){}
	static CheckFit *checkfitinstace;
};
template <class T>
CheckFit<T> *CheckFit<T>::checkfitinstace = NULL;