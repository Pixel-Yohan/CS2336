//
// YOHAN G. FLORES | CS 23306.001 | C++ Section
//

#ifndef CSIICOURSEPROJECT_VEHICLE_H
#define CSIICOURSEPROJECT_VEHICLE_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Vehicle{
private:
    /*
     * Those these variables weren't required in the project they're here to show
     * how Vehicle is an important class. Often, real world parking lots know the
     * cars they are storing. This is just to showcase that our vehicle class could
     * do much more.
     */
    string color;
    float weight;
public:
    //getter of color
    virtual string getColor()=0;
    //getter of weight
    virtual float getWeight()=0;
    //returns the type of Vehicle it is
    virtual string getType()=0;
    //returns a vector that tells the type of parking a vehicle accepts
    virtual vector<string> getParkingType()=0;
};
#endif //CSIICOURSEPROJECT_VEHICLE_H
