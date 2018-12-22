# ParkingLevels
Semester long project for my CS 2336 (Computer Science II) class. God bless Dr.Mehra, she was so patient in helping me with all
the questions I had with my code.

**PLEASE NOTE THAT THIS PROGRAM RELIES ON USER ENTERING A CHOICE # not "yes/no" or some word.

NOTE:

l: empty large parking spot.
c: empty compact parking spot.
m: empty motorcycle parking spot.
M: occupied spot by motorcycle.
C: occupied spot by car.
B: ccupied spot by bus.


[Invoking Default Constructor Sample Run:]
Hi! Welcome to Build-A-Parking-Lot.
Enter how many parking levels you would like to have, or 0 to have a default parking lot:0
 0

This is what your parking lot looks like:
Level 1 : llllllcccc cccccccccc ccccmmmmmm
Level 2 : llllllcccc cccccccccc ccccmmmmmm
Level 3 : llllllcccc cccccccccc ccccmmmmmm
Level 4 : llllllcccc cccccccccc ccccmmmmmm
Level 5 : llllllcccc cccccccccc ccccmmmmmm

[Parking a Motorcycle with default constructor]
What would you like to do today?
1. Add Vehicles
2. Remove Vehicles
3. Exit

1

What kind of vehicle would you like to park in your lot?
1. Motorcycle
2. Car
3. Bus

1

This is what your parking lot looks like now:
Level 1 : llllllcccc cccccccccc ccccMmmmmm
Level 2 : llllllcccc cccccccccc ccccmmmmmm
Level 3 : llllllcccc cccccccccc ccccmmmmmm
Level 4 : llllllcccc cccccccccc ccccmmmmmm
Level 5 : llllllcccc cccccccccc ccccmmmmmm

(as you can tell we did indeed park a motorcycle)

[Parking a vehicle until no more space is available for it]
This is what your parking lot looks like now:
Level 1 : BBBBBlCccc cccccccccc ccccMmmmmm
Level 2 : BBBBBlcccc cccccccccc ccccmmmmmm
Level 3 : BBBBBlcccc cccccccccc ccccmmmmmm
Level 4 : BBBBBlcccc cccccccccc ccccmmmmmm
Level 5 : BBBBBlcccc cccccccccc ccccmmmmmm

Would you like to park another vehicle in your parking lot?
1. Yes
 2. No

1
What kind of vehicle would you like to park in your lot?
1. Motorcycle
2. Car
3. Bus

3
There appears to be no space to park your vehicle!
Please park another type of vehicle.Would you like to park another vehicle in your parking lot?
1. Yes
 2. No
(user now knows there is no space for buses. user should therefore try to populate other
types of vehicles).

[Removing a Bus]

Level 1 : llllllcccc cccccccccc ccccmmmmmm
Level 2 : BBBBBlcccc cccccccccc ccccmmmmmm
Level 3 : BBBBBlcccc cccccccccc ccccmmmmmm
Level 4 : BBBBBlcccc cccccccccc ccccmmmmmm
Level 5 : BBBBBlcccc cccccccccc ccccmmmmmm

[After removing all Bus vehicles]

Level 1 : llllllcccc cccccccccc ccccMmmmmm
Level 2 : llllllcccc cccccccccc ccccmmmmmm
Level 3 : llllllcccc cccccccccc ccccmmmmmm
Level 4 : llllllcccc cccccccccc ccccmmmmmm
Level 5 : llllllcccc cccccccccc ccccmmmmmm

Sorry there is no vehicle of type Bus to remove from your parking lot.

[When we don't invoke the default constructor]

Hi! Welcome to Build-A-Parking-Lot.
Enter how many parking levels you would like to have, or 0 to have a default parking lot:10
 10

Enter how many spots per level you would like to have:20
 20

Enter how many rows per level you would like to have:2
 2

Enter how many motorcycle spots you would like to have:3
 3

Enter how many compact spots you would like to have:5
 5
This is what your parking lot looks like:
Level 1 : llllllllll llcccccmmm
Level 2 : llllllllll llcccccmmm
Level 3 : llllllllll llcccccmmm
Level 4 : llllllllll llcccccmmm
Level 5 : llllllllll llcccccmmm
Level 6 : llllllllll llcccccmmm
Level 7 : llllllllll llcccccmmm
Level 8 : llllllllll llcccccmmm
Level 9 : llllllllll llcccccmmm
Level 10 : llllllllll llcccccmmm
What would you like to do today?
1. Add Vehicles
2. Remove Vehicles
3. Exit
(program proceeds as normal like other test cases shown above).

[Exiting Program]
What would you like to do today?
1. Add Vehicles
2. Remove Vehicles
3. Exit

3
Thanks for using this program!
