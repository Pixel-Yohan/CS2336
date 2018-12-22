//
// YOHAN G. FLORES | CS 23306.001 | C++ Section
//

#include <vector>
#include <string>
#include <iostream>
#include "Vehicle.h"
using namespace std;

class ParkingSpot{
private:
    Vehicle* vehicleParked;
    bool occupied;
    string type;
public:
    /*
     * All ParkingSpot objects will be defaulted with occupied=false because
     * we first need to create the parking lot before we can park vehicles.
     * Type will be used to indicate what type of parking it is: large, compact, motorcycle
     */
    ParkingSpot(string type){
        this->type=type;
        occupied=false;
    }
    ~ParkingSpot(){
        delete vehicleParked;
        vehicleParked=NULL;
        //delete this;
    }

    /*
     * Stores the address of the vehicle parked in the parking lot.
     * sets bool occupied to true, and stores the type of vehicle in string.
     * @PARAM: A derived object from Vehicle.
     */
    void park(Vehicle* vehicleObj){
        vehicleParked=vehicleObj;
        occupied=true;
    }
    /*
     * Remove the vehicle from the ParkingSpot and set occupied to false
     *
     */
    void removeVehicle(){
        vehicleParked=NULL;
        occupied=false;
    }
    /*
     * Return if a vehicle is currently parked in a ParkingSpot object.
     */
    bool isOccupied(){
        return occupied;
    }
    /*
     * Return the type of vehicle that is parked in the ParkingSpot (if any).
     */
    string typeOfVehicleParked(){
        if(occupied) {
            return vehicleParked->getType();
        }
        else{
            return "No vehicle parked";
        }
    }

    /*
     * Returns the type of parking it is: "Large", "Compact", "Motorcyle".
     */
    string typeOfParking(){
        return type;
    }

    void print(){
        string toReturn;
        if(occupied){
            toReturn= vehicleParked->getType();
            cout << toReturn.substr(0,1);
        }
        else {
            //if not occupied then return the first letter of the type of parking it is.
            //in order to work properly we must have the type be entered by the user all in lower case.
            cout << type.substr(0, 1);
        }
    }
};