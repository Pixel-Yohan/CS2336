//
// YOHAN G. FLORES | CS 23306.001 | C++ Section
//
#include <vector>
#include <string>
#include <iostream>
#include "Vehicle.h"


//basically implements Vehicle Object methods
class Bus: public Vehicle{
private:
    string color;
    float weight;
public:
    Bus(string color, float weight){
        this->color=color;
        this->weight=weight;
    }
    ~Bus(){}
    string getColor() override{
        return color;
    }
    float getWeight() override{
        return weight;
    }
    string getType() override{
        return "Bus";
    }
    vector<string> getParkingType() override{
        vector<string> parkingType;
        parkingType.push_back("large");
        parkingType.push_back("5");
        return parkingType;
    }
};
