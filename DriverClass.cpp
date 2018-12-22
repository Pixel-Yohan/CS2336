//
// YOHAN G. FLORES | CS 23306.001 | C++ Section
//
//Make calls to create a Parking Lot and manage vehicles and the such.

#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include "Vehicle.h"
#include "Motorcycle.cpp"
#include "Bus.cpp"
#include "Car.cpp"
#include "ParkingLot.cpp"
using namespace std;

int main(){
    cout<<"Hi! Welcome to Build-A-Parking-Lot."<<endl;
    ParkingLot *userParkingLot;
    int num_of_levels;
    cout<<"Enter how many parking levels you would like to have, or 0 to have a default parking lot: ";
    while(!(cin >> num_of_levels) || num_of_levels<0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input please enter a positive integer: ";
    }
    if(num_of_levels==0){
        userParkingLot= new ParkingLot;
        cout << "This is what your parking lot looks like:" << endl;
        userParkingLot->printLot();
    }
    else {
        int spots_per_level;
        cout << "\nEnter how many spots per level you would like to have: ";
        while (!(cin >> spots_per_level) || spots_per_level < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please enter a positive integer: ";
        }
        int rows;
        cout << "\nEnter how many rows per level you would like to have: ";
        while (!(cin >> rows) || spots_per_level < 1 || (spots_per_level % rows != 0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please enter a positive integer that divides into " << spots_per_level << " :";
        }
        int motorcycle_spots;
        cout << "\nEnter how many motorcycle spots you would like to have: ";
        while (!(cin >> motorcycle_spots) || motorcycle_spots < 0 || (motorcycle_spots > spots_per_level)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please enter a positive integer that is <= 0 " << spots_per_level << " :";
        }
        int compact_spots;
        int large_spots;
        //check to see that the user has not decided to make an entire parking lot full of motorcycle spots
        if (motorcycle_spots != spots_per_level) {
            cout << "\nEnter how many compact spots you would like to have: ";
            while (!(cin >> compact_spots) || compact_spots < 0 ||
                   (compact_spots > (spots_per_level - motorcycle_spots))) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input please enter a positive integer that is <="
                     << (spots_per_level - motorcycle_spots) << " :";
            }
            large_spots = spots_per_level - (compact_spots + motorcycle_spots);
        }
            //if all the spots are indeed motorcycle spots then the rest of the spots have to be zero.
        else {
            compact_spots = 0;
            large_spots = 0;
        }
        userParkingLot = new ParkingLot(num_of_levels, spots_per_level, rows, large_spots, motorcycle_spots,
                                        compact_spots);
        cout << "This is what your parking lot looks like:" << endl;
        userParkingLot->printLot();
    }
    //to keep the program running
    bool keepRunning=true;
    //to allow the keep adding until full function
    bool keepAdding;
    //to allow the keep removing until full function
    bool keepRemoving;

    while(keepRunning) {
        int process_choice;
        cout << "What would you like to do today?" <<endl;
        cout << "1. Add Vehicles" <<endl;
        cout << "2. Remove Vehicles" << endl;
        cout << "3. Exit" <<endl;
        while(!(cin >> process_choice) || process_choice<0 || process_choice>3){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please enter 1, 2, or 3 :";
        }
        switch(process_choice) {
            case 1:
                keepAdding = true;
                keepRemoving = false;
                break;
            case 2:
                keepAdding = false;
                keepRemoving = true;
                break;
            case 3:
                keepAdding = false;
                keepRemoving = false;
                keepRunning = false;
                break;
        }

        while (keepAdding) {
            cout << "What kind of vehicle would you like to park in your lot?" << endl;
            cout << "1. Motorcycle\n2. Car\n3. Bus" << endl;

            int vehicleChoice;
            while (!(cin >> vehicleChoice) || vehicleChoice > 3 || vehicleChoice < 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input please enter an integer between 1 and 3: ";
            }
            Vehicle *vehicle;
            switch (vehicleChoice) {
                case 1:
                    vehicle = new Motorcycle("Red", 400.0);
                    break;
                case 2:
                    vehicle = new Car("Black", 1500);
                    break;
                case 3:
                    vehicle = new Bus("Yellow", 44000.0);
                    break;
            }

            //finds parking to park user vehicle choice
            //change to have an else condition in the other vehicle objects.

            vector<ParkingSpot *> toPark = userParkingLot->findParking(vehicle);
            if (toPark[0] != nullptr) {
                for (int i = 0; i < toPark.size(); i++) {
                    toPark[i]->park(vehicle);
                }
                cout << "This is what your parking lot looks like now: \n";
                userParkingLot->printLot();
            } else {
                cout << "There appears to be no space to park your vehicle!" << endl;
                cout << "Please park another type of vehicle.";
                //might ask the user if he wants to add another lot
            }

            cout << "Would you like to park another vehicle in your parking lot?" << endl;
            cout << "1. Yes\n 2. No\n";

            int userChoice;
            while (!(cin >> userChoice) || userChoice > 2 || userChoice < 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input please enter 1 or 2: ";
            }
            //if user selects no then simply or stop the program.
            if (userChoice == 2) {
                keepAdding = false;
                break;
            }
        }
        //next steps remove until no more available.
        //already have remove function inside parking spot.
        while (keepRemoving) {
            cout << "What kind of vehicle would you like to remove from your lot?" << endl;
            cout << "1. Motorcycle\n2. Car\n3. Bus" << endl;

            int vehicleChoice;
            while (!(cin >> vehicleChoice) || vehicleChoice > 3 || vehicleChoice < 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input please enter an integer between 1 and 3: ";
            }
            string removeVehicle;
            switch (vehicleChoice) {
                case 1:
                    removeVehicle = "Motorcycle";
                    break;
                case 2:
                    removeVehicle = "Car";
                    break;
                case 3:
                    removeVehicle = "Bus";
                    break;
            }
            vector<ParkingSpot *> parkingToRemove = userParkingLot->findVehicleToRemove(removeVehicle);
            //no vehicle of that type to remove
            if (parkingToRemove[0] == nullptr) {
                cout << "\nSorry there is no vehicle of type " << removeVehicle << " to remove from your parking lot.";
                cout << "\nPlease try to remove another type of vehicle.";
            } else {
                for (int i = 0; i < parkingToRemove.size(); i++) {
                    parkingToRemove[i]->removeVehicle();
                }
                cout << "\nThis is now your parking lot: " << endl;
                userParkingLot->printLot();
            }
            cout << "Would you like to remove another vehicle in your parking lot?" << endl;
            cout << "1. Yes\n 2. No\n";
            int userChoice;
            while (!(cin >> userChoice) || userChoice > 2 || userChoice < 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input please enter 1 or 2: ";
            }
            //if user selects no then simply or stop the program.
            if (userChoice == 2) {
                keepRemoving = false;
                break;
            }
        }
    }
    cout << "Thanks for using this program!" << endl;
    return 0;
}
