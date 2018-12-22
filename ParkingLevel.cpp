//
// YOHAN G. FLORES | CS 23306.001 | C++ Section
//

//
// YOHAN G. FLORES CS II
//
#include <string>
#include <vector>
#include <iostream>
#include "ParkingSpot.cpp"
using namespace std;

class ParkingLevel{
    private:
        int num_of_level,large_spots,compact_spots,motorcycle_spots, rows;
        int total;
        //vector where ParkingSpot pointers will be stored
        vector <ParkingSpot*> spotList;
    public:
        //Single constructor, don't need a default constructor since ParkingLot will send this
        //object default values if the default constructor is invoked in a ParkingLot object.
        ParkingLevel(int num_of_level,int large_spots, int compact_spots, int motorcycle_spots, int rows){
            this->num_of_level=num_of_level;
            this->large_spots=large_spots;
            this->compact_spots=compact_spots;
            this->motorcycle_spots=motorcycle_spots;
            this->rows=rows;
            total=large_spots+compact_spots+motorcycle_spots;
            //we can treat a 1d array by doing row_size*row_num + index
            //so can we make a single loop and know when we're at the next row?

            //Create parking spots that are of type Large
            for(int i=0; i<large_spots;i++){
                ParkingSpot* parkingspot;
                parkingspot= new ParkingSpot("large");
                spotList.push_back(parkingspot);
            }
            //Create parking spots that are of type Compact
            for(int i=0;i<compact_spots;i++){
                ParkingSpot* parkingspot;
                parkingspot= new ParkingSpot("compact");
                spotList.push_back(parkingspot);
            }
            //Create parking spots that are of type motorcycle
            for(int i=0;i<motorcycle_spots;i++){
                ParkingSpot* parkingspot;
                parkingspot= new ParkingSpot("motorcycle");
                spotList.push_back(parkingspot);
            }
        }
        //destructor
        ~ParkingLevel(){
            for(int i=0;i<spotList.size();i++){
                delete spotList[i];
                spotList[i]=NULL;
            }
            spotList.clear();
            spotList.shrink_to_fit();
            //delete this;
        }
        /*
         * Loops through spotList and determines if the level is full.
         */
        bool isFull(){
            for(int i=0;i<spotList.size();i++){
                if(!spotList[i]->isOccupied()){
                    return false;
                }
            }
            return true;
        }

        /*
         * Finds parking spot inside the level. We first make sure that there are enough spaces
         * in a row to fit the vehicle's spaces (int howMany). If there's not enough then we simply
         * return a vector that has a nullPtr element.
         *
         *
         * If there are enough spaces in a row to fit the vehicle then we loop through the spots list
         * treating it as a 2D vector. If the spot we are accessing in the nested for loop is not occupied
         * and it's of the same type of parking as the string typeOfParking then we consider it as a possibility
         * to add to my list of foundSpots.
         *
         * If we find enough consecutive spots to park the vehicle then we go back
         * to the first spot that we found and add it to the list for as many spots the vehicle needs.
         * Otherwise we reset the count to 0 and keep searching for consecutive parking spots that will fit the vehicle.
         *
         *If by any chance there aren't any available parking spots to park the vehicle we return a vector with
         * a null pointer.
         *
         * @PARAMETERS: typeofParking string that tells us what kind of vehicle to search for in occupied parking spots.
         *              howMany string which tells us how many spots we are looking for.
         * @RETURN: return a vector of ParkingSpot Objects.
         */
        vector<ParkingSpot*> findParking(string typeOfParking, int howMany){
            //Loops through the spots in a level.
            vector<ParkingSpot*>foundSpots;
            //if our vehicle needs more spots than are available per row
            //then we won't find any spots
            if(howMany>(spotList.size()/rows)){
                foundSpots.push_back(nullptr);
                return foundSpots;
            }
            for(int i=0;i<rows;i++){
                int count=0;
                for(int j=0;j<(spotList.size()/rows);j++){
                    ParkingSpot * spot = spotList[i*(total/rows)+j];
                    //if spot is empty consider it
                    if(!spot->isOccupied() && spot->typeOfParking()==typeOfParking){
                        count++;
                    }
                    //otherwise reset count to 0
                    else{
                        count=0;
                    }
                    //if we find howMany consecutive spots store those pointers
                    //and return.
                    if(count==howMany){
                        //
                        int start = (j)-(howMany-1);
                        //loop from where we found the first available spot
                        //to where the last spot found is at.
                        for (int k = start; k < start + howMany; k++) {
                            foundSpots.push_back(spotList[i * (total / rows) + k]);
                        }

                        return foundSpots;

                    }

                }
            }
            foundSpots.push_back(nullptr);
            return foundSpots;
        }

        /*
         * Loop through ParkingSpot objects. If we find a paring spot that is occupied and it has a vehicle of type
         * string VehicleType then we consider that ParkingSpot for removal. However, if we find that it's of type bus
         * then we need to also remove the other 4 spots that are being occupied by the bus.
         *
         * @PARAMETER: string VehicleType that tells the type of vehicle we are searching for
         * @RETURN: vector<ParkingSpot*> returns the ParkingSpot where said vehicle was found or a null pointer element
         *          if the vehicle wasn't found.
         */
        vector<ParkingSpot*> findVehicleToRemove(string vehicleType){
            vector<ParkingSpot*> foundParking;
            //iterate trough the spots in our parking level.
            for(int i=0;i<rows;i++){
                for(int j=0;j<(spotList.size()/rows);j++){
                    ParkingSpot * spot = spotList[i*(total/rows)+j];
                    //if spot is occupied and of the vehicle type we're looking for
                    if(spot->isOccupied() && spot->typeOfVehicleParked()==vehicleType){
                        //pushback that spot into our spot list
                        foundParking.push_back(spot);
                        //however if it's of the bus type we need to also collect the other four spots
                        //to the right.
                        if(vehicleType=="Bus"){
                            for(int k=1;k<5;k++){
                                foundParking.push_back(spotList[i*(total/rows)+j+k]);
                            }
                        }
                        return foundParking;
                    }
                }
            }
            foundParking.push_back(nullptr);
            return foundParking;
        }
        void printLevel(){
            for(int i=0;i<rows;i++){
                //this will help separate rows.
                if(i>0){
                    cout<< " ";
                }
                for(int j=0;j<(total/rows);j++){
                    ParkingSpot * spot = spotList[i*(total/rows)+j];
                    spot->print();
                }
            }
        }


};
