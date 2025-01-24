# Vehicle Rental System

## Overview
The Vehicle Rental System is designed to manage various vehicle types including Cars, Trucks, and Motorcycles. The system allows users to:
- Add vehicles to the rental inventory.
- Perform custom calculations for each vehicle type (e.g., fuel usage for cars, load factor for trucks).
- Sort the inventory based on specific attributes (e.g., fuel efficiency, load factor, number plate digits).

The system demonstrates Object-Oriented Programming (OOP) concepts such as inheritance, access control (private and protected inheritance), and sorting.

## Features
### Vehicle Class (Base Class)
- Attributes:
  - `int id`: Unique identifier for the vehicle.
  - `string make`: Manufacturer of the vehicle.
  - `string model`: Model of the vehicle.
  - `float weight`: Weight of the vehicle (in kilograms).
- Methods:
  - `display()`: Displays vehicle details (ID, make, model, and weight).

### Car Class (Derived from Vehicle)
- Attributes:
  - `float fuelEfficiency`: Fuel efficiency of the car (in km/l).
  - `int passengerCapacity`: Maximum number of passengers.
- Methods:
  - `calculateTotalFuelUsed(float distance)`: Calculates the total fuel used for a given distance.
  - `sortCarsByFuelEfficiency(Car** cars, int count)`: Sorts an array of cars by fuel efficiency.

### Truck Class (Derived from Vehicle)
- Attributes:
  - `float cargoCapacity`: Maximum cargo capacity (in tons).
  - `float cargoLoad`: Current cargo load (in tons).
- Methods:
  - `calculateLoadFactor()`: Calculates the load factor based on current cargo load and maximum capacity.
  - `sortTrucksByLoadFactor(Truck** trucks, int count)`: Sorts an array of trucks based on load factor.

### Motorcycle Class (Derived from Vehicle)
- Attributes:
  - `int horsepower`: Horsepower of the motorcycle.
  - `string numberPlate`: The motorcycle's number plate (formatted as XX99YY).
- Methods:
  - `calculatePowerToWeightRatio()`: Calculates the power-to-weight ratio using horsepower and weight.
  - `sortMotorcyclesByNumberPlateDigits(Motorcycle** motorcycles, int count)`: Sorts motorcycles by the extracted two-digit number from their number plates.

### VehicleRentalSystem Class
- Attributes:
  - Arrays to store vehicles:
    - `Car* cars[5]`
    - `Truck* trucks[5]`
    - `Motorcycle* motorcycles[5]`
  - Counters for the number of vehicles:
    - `int carCount`
    - `int truckCount`
    - `int motorcycleCount`
- Methods:
  - `addCar(int id, string make, string model, float weight, float fuelEfficiency, int passengerCapacity)`: Adds a car to the system.
  - `addTruck(int id, string make, string model, float weight, float cargoCapacity, float cargoLoad)`: Adds a truck to the system.
  - `addMotorcycle(int id, string make, string model, float weight, int horsepower, string numberPlate)`: Adds a motorcycle to the system.
  - `sortInventoryByAttribute()`: Sorts the inventory based on custom attributes for each vehicle type.
  - `displayRental()`: Displays the current rental inventory.
  - 
Compile and Run:

g++ task1.cpp

./a.out



