//
// YOHAN G. FLORES | CS 23306.001 | C++ Section
//
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "ParkingLevel.cpp"
#include "Vehicle.h"

using namespace std;
/*
 * Constructs a Parking Lot Object
 *
 */

class ParkingLot{
    private:
        //Parking Lot Characteristics
        int num_of_levels, spots_per_level,spots_per_row;
        int large_spots, motorcycle_spots, compact_spots;
        float large_percent,motorcycle_percent,compact_percent;
        //vector where levels will be stored
        vector<ParkingLevel*> level_list;
    public:
        /*
         * Default Constructor:
         *  5 levels, 30 spots per level, 10 spots per row.
         *  20 percent of spots are large, 20 are motorcycle spots.
         *  Spots are calculated using percent*total spots
         *  Creates the Level Objects.
         */
        ParkingLot(){
            num_of_levels=5;
            spots_per_level=30;
            spots_per_row=10;
            large_percent=.20;
            large_spots= static_cast<int>(spots_per_level*large_percent);
            motorcycle_percent=.20;
            motorcycle_spots= static_cast<int>(spots_per_level*motorcycle_percent);
            compact_percent=1-(large_percent+motorcycle_percent);
            compact_spots= static_cast<int>(spots_per_level*compact_percent);
            //stores parking levels
            for(int i=0;i<num_of_levels;i++){
                ParkingLevel* parkingLevel;
                parkingLevel = new ParkingLevel(i, large_spots, compact_spots, motorcycle_spots, (spots_per_level/spots_per_row));
                level_list.push_back(parkingLevel);
            }
        }
        /*
         * Non-default Constructor:
         * Spots are calculated using percent*total spots.
         */
        ParkingLot(int num_levels,int spots_level,int spots_row,int large,int motorcycle,int compact){
            //this->large_percent=large_percent;
            //this->motorcycle_percent=motorcycle_percent;
            //this->compact_percent= 100 -(large_percent+motorcycle_percent);
            this->num_of_levels = num_levels;
            this->spots_per_level = spots_level;
            this->spots_per_row = spots_row;
            this->large_spots=large;
            this->motorcycle_spots=motorcycle;
            this->compact_spots=compact;
            /*
            large_spots= static_cast<int>(spots_per_level*large_percent);
            motorcycle_spots= static_cast<int>(spots_per_level*motorcycle_percent);
            compact_spots= static_cast<int>(spots_per_level*compact_percent);
            //stores parking levels.
             */

            for(int i=0; i<num_levels;i++){
                //insert objects of Parking_Levels
                ParkingLevel* parkingLevel;
                parkingLevel = new ParkingLevel(i, large_spots, compact_spots, motorcycle_spots, spots_per_row);
                level_list.push_back(parkingLevel);
            }
        }
        //destructor
        ~ParkingLot(){
            for(int i=0;i<level_list.size();i++){
                delete level_list[i];
                level_list[i]=NULL;
            }
            level_list.clear();
            level_list.shrink_to_fit();

            //delete this;
        }
        /*
         * Adds a level to the parking lot. The level will contain all the same
         * characteristics as the previous levels.
         * Cannot take negative values because that wouldn't be adding.
         * Will make sure that I don't get negative levels in my main method
         */
        void addLevel(int numOfLevels){
            for(int i=0;i<numOfLevels;i++){
                ParkingLevel* parkingLevel;
                parkingLevel = new ParkingLevel(num_of_levels, large_spots, compact_spots, motorcycle_spots,spots_per_row);
                level_list.push_back(parkingLevel);
                num_of_levels+=1;
            }
        }
        /*
         * Determines if the parking lot is fully occupied.
         * Loops through the levels list to see if they are full.
         */
        bool isFull(){
            for(int i=0;i<level_list.size();i++){
                if(level_list[i]->isFull()==false){
                    return false;
                }
            }
            return true;
        }
        /*
         * Determines if the parking lot is empty.
         * Loops through the levels list to see if they are full.
         */
        bool isEmpty(){
            for(int i=0;i<level_list.size();i++){
                if(level_list[i]->isFull()==true){
                    return false;
                }
            }
            return true;
        }
        /* Loops through level list to find ParkingSpot objects that are full and of the same vehicle type we
         * are searching.
         *
         *
         * @Parameter: string VehicleType.
         * @Return: vector of ParkingSpot pointers.
         */
        vector<ParkingSpot*> findVehicleToRemove(string vehicleType){
            //if the parking lot is empty...there is nothing to remove therefore return a null pointer.
            vector<ParkingSpot*> parkingToRemove;
            //loops through levels because the parking lot contains some vehicles
            for(int i=0;i<level_list.size();i++){
                //if it doesn't find any parking to remove from it returns parkingToRemove[0]=nullptr
                parkingToRemove=level_list[i]->findVehicleToRemove(vehicleType);
                if(parkingToRemove[0]!= nullptr){
                    return parkingToRemove;
                }
            }
            parkingToRemove.push_back(nullptr);
            return parkingToRemove;
        }

        /*
         * Returns a vector of pointers to parking spot(s) available for parking.
         * This will be returned so parking spot can park the vehicle.
         * If the vehicle only occupies one space then the vector will simply return one element.
         *
         *
         * We first check if the vehicle object can park in a motorcycle spot, if it can't then check if it
         * can park in a compact spot, if it can't then check if it can park in a large spot.
         * We do this because we want to leave large parking spots for buses ideally. So if possible try to fill up
         * the smaller parking types.
         *
         *
         * @PARAMETER: Takes any derived vehicle object
         * @RETURN: Returns a vector of ParkingSpot objects or a null pointer if parking wasn't found.
         */
        vector<ParkingSpot*> findParking(Vehicle* vehicleObj){
            //gets the information of the parking types that the vehicle can park in.
            vector<ParkingSpot*>foundSpaces;
            vector<string> parkingType = vehicleObj->getParkingType();
            //iterators will iterate through the getParkingType() vector received from the object to look for
            //parking attributes. even indexes (like 0,2,4) will always contain the type of parking they accept
            //odd indexes will contain the number of parking spaces it takes to cover that type of parking.

            vector<string>::iterator large;
            vector<string>::iterator motorcycle;
            vector<string>::iterator compact;
            //finds if large is found in the vehicle object as possible to park in
            large=find (parkingType.begin(),parkingType.end(),"large");

            //finds if motorcycle is found in the vehicle object as possible to park in
            motorcycle=find (parkingType.begin(),parkingType.end(),"motorcycle");
            //finds if compact is found in the vehicle object as possible to park in
            compact=find(parkingType.begin(),parkingType.end(),"compact");
            //if it can park in motorcycle spots
            //if motorcycle iterator does not reach the end it means that it did find it
            if(motorcycle!=parkingType.end()){
                //gives the index after "motorcycle", this element will tell us how many motorcycle spaces it takes
                ptrdiff_t difference = distance(parkingType.begin(),motorcycle)+1;
                //convert string number to an actual int.
                int numOfSpaces = stoi(parkingType[difference]);
                //look for motorcycle parking in each level
                for(int i=0;i<level_list.size();i++){
                    vector<ParkingSpot*> availableSpaces =(level_list[i]->findParking("motorcycle",numOfSpaces));
                    if(availableSpaces[0]!= nullptr){
                        return availableSpaces;
                    }
                }
            }
            //if it can park in compact spots
            if(compact!=parkingType.end()){
                //gives the index after "compact", this element will tell us how many compact spaces it takes
                ptrdiff_t difference = distance(parkingType.begin(),compact)+1;
                int numOfSpaces = stoi(parkingType[difference]);
                //look for motorcycle parking in each level
                for(int i=0;i<level_list.size();i++){
                    vector<ParkingSpot*> availableSpaces =(level_list[i]->findParking("compact",numOfSpaces));
                    if(availableSpaces[0]!= nullptr){
                        return availableSpaces;
                    }
                }
            }
            //if it can park in large spots
            if(large!=parkingType.end()){
                //gives the index after "large", this element will tell us how many large spaces it takes
                ptrdiff_t difference = distance(parkingType.begin(),large)+1;
                int numOfSpaces = stoi(parkingType[difference]);
                //look for motorcycle parking in each level
                for(int i=0;i<level_list.size();i++){
                    vector<ParkingSpot*> availableSpaces =(level_list[i]->findParking("large",numOfSpaces));
                    if(availableSpaces[0]!= nullptr){
                        return availableSpaces;
                    }
                }
            }
            //if we didn't find any parking return a null pointer.
            foundSpaces.push_back(nullptr);
            return foundSpaces;
        }
        /*
         * Prints the entire parking lot by looping through the levels and finding what types of parking spots there are
         * depending on their type it will print out the type it is.
         * This is when we finally use the variable spots_per_row.
         * "l" is for large spots, "c" is for compact spots, "m" for motorcycle spots.
         * "M" is for a parked motorcycle vehicle, "B" is for a parked motorcycle vehicle,
         * "C" is for a parked car vehicle.
         */
        void printLot(){
            for(int i=0;i<level_list.size();i++){
                ParkingLevel * level = level_list[i];
                cout<< "Level " << (i+1) << " : ";
                level->printLevel();
                //Every new level will be separated by a new line character.
                cout << "\n";
            }
        }

};