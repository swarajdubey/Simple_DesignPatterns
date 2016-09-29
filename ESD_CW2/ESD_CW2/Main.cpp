#include "SetShape.h"
#include "CylinderBuilder.h"
#include "CuboidBuilder.h"
#include "CheckFit.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(void)
{
	int i = 0;
	double *cylinder_container = new double;			//temporarily storage for container's volume 
	double *sensors_volume = new double;			//temporarily storage for two sensors' volume 
	double *stones_volume = new double;				//temporarily storage for stone's volume 
	double *water_volume = new double;				//temporarily storage for water's volume 
	double *number_of_stones = new double;				//storage for number of stones
	double *occupied_volume = new double;
	*number_of_stones = -1;
	char opt;

	CheckFit<double> *checkfit= CheckFit<double>::getCHeckFitInstance();
	CuboidBuilder<double> cuboid,cuboid2; //cuboid builder object
	CylinderBuilder<double> cylinder; //cylinder builder object
	SetShape<double> *direct=SetShape<double>::getSetShapeInstance(); //object for main builder class to instantiate different object through common method
	vector<Shape<double>> objvec;	//object product vector

	while (true) {

		cout << "Enter dimensions of cylindrical container:\n";
		direct->setObject(&cylinder); //cylinder construction object (done by builder pattern)
		objvec.push_back(direct->Build());	//entire cylinder object now inside this vector

		cout << "Enter dimensions of the first cuboid sensor module:\n";
		direct->setObject(&cuboid);
		objvec.push_back(direct->Build()); //entire cylinder object now inside this vector

		//check here whether the cuboid sensor will make the water overflow 
		if (checkfit->checkCuboidFitInCylinder(objvec[0].getH(), objvec[0].getR(), objvec[1].getL(), objvec[1].getW(), objvec[1].getH()) == true)
		{
			cout << "Enter dimensions of the second cuboid sensor module:\n";
			direct->setObject(&cuboid2);
			objvec.push_back(direct->Build()); //entire cylinder object now inside this vector

			//check here whether the cuboid sensor will make the water overflow 
			if (checkfit->checkCuboidFitInCylinder(objvec[0].getH(), objvec[0].getR(), objvec[2].getL(), objvec[2].getW(), objvec[2].getH()) == true)
			{

				cout << "Enter dimensions of cylindrical stones?\n";
				direct->setObject(&cylinder);
				objvec.push_back(direct->Build());//entire cylindrical object now inside this vector

				//check if the cylindrical stone can fit inside or not
				if (checkfit->checkCylinderFitInCylinder(objvec[0].getH(), objvec[0].getR(), objvec[3].getH(), objvec[3].getR())==true)
				{
					//check for overflow here
					*cylinder_container = objvec.at(i).getV();		//get container's volume from vector
					*water_volume = *cylinder_container * 0.75;				//get 75% liquid volume in the container

					*sensors_volume = objvec.at(i + 1).getV() + objvec.at(i + 2).getV();		//get sensor's volume from vector

					if ((*water_volume + *sensors_volume) > *cylinder_container) //this means overflow has occured
					{
						cout << "An overflow has already occured, please check the sensor dimensions \n";
					}
					else {
						*stones_volume = objvec.at(i + 3).getV();			//get stone's volume from vector
						*occupied_volume = (*sensors_volume) + (*water_volume);
						//cout << "occupied volume is: " << *occupied_volume << endl;
						while (*occupied_volume <= *cylinder_container)
						{
							*number_of_stones = (*number_of_stones) + 1;
							*occupied_volume = (*occupied_volume) + (*stones_volume);
						}

						cout << "The number of the stones that can fit in the container until the brink of overflowing:\n\n\t\t";
						cout << *number_of_stones << "\n\n";
						*number_of_stones = -1;

					}
					
				}
				else{cout << "Cylindrical stone can't fit inside\n";}
	
			}
			else{cout << "Cuboid sensor cannot fit \n";}
		}
		else{cout << "Cuboid sensor cannot fit \n";}


		//do the calculations here
		//cout << "container volume: " << *cylinder_container << " , sensors volume: " << *sensors_volume << " , water: " << *water_volume << endl;
		
		i = -1; //reset the counter here for vector index(should reach 0 upon incrementing this counter to prevent out of bound)
		cout << "Do you want to test for another case? [Y/N]\t";
		cin >> opt;

		if (opt == 'N' || opt == 'n') break;
		cout << endl;

		objvec.clear();
		i++;
	}

	//free up the memory allocated to double type pointer variables
	checkfit->destroyUniqueInstace(); //delete the unique instance at the end of the program
	delete cylinder_container;
	delete sensors_volume;
	delete stones_volume;
	delete water_volume;
	delete number_of_stones;

	system("PAUSE");
}