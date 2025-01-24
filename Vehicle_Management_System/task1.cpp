#include <iostream>
#include <string>
using namespace std;

class vehicle
{

protected:
    int id;
    string make;
    string model;
    float weight;

public:
    vehicle(int id, string make, string model, float weight)
    {
        this->id = id;
        this->make = make;
        this->model = model;
        this->weight = weight;
    }

    virtual void display() const
    {
        cout << "ID: " << id << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Weight: " << weight << endl;
    }
};

class car : protected vehicle
{
private:
    float fuelEfficiency;
    int passengerCapacity;

public:
    car(int id, string make, string model, float weight, float fuelEfficiency, int passengerCapacity) : vehicle(id, make, model, weight), fuelEfficiency(fuelEfficiency), passengerCapacity(passengerCapacity) {}

    float calculateTotalFuelUsed(float distance) const
    {
        return distance / fuelEfficiency;
    }

    static void sortCarsbyFuelEfficiency(car **cars, int count)
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (cars[j]->fuelEfficiency > cars[j + 1]->fuelEfficiency)
                {
                    car *temp = cars[j];
                    cars[j] = cars[j + 1];
                    cars[j + 1] = temp;
                }
            }
        }
    }

    void display() const override
    {
        vehicle::display();
        cout << "Fuel Efficiency:  " << fuelEfficiency << " km/l" << endl;
        cout << "Passenger Capacity: " << passengerCapacity << endl;
    }
};

class truck : private vehicle
{
private:
    float cargoCapacity;
    float CargoLoad;

public:
    truck(int id, string make, string model, float weight, float cargoCapacity, float CargoLoad) : vehicle(id, make, model, weight), cargoCapacity(cargoCapacity), CargoLoad(CargoLoad) {}

    float calculateLoadFactor() const
    {
        return CargoLoad / cargoCapacity;
    }

    static void sortTrucksByLoadFactor(truck **trucks, int count)
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (trucks[j]->calculateLoadFactor() > trucks[j + 1]->calculateLoadFactor())
                {
                    truck *temp = trucks[j];
                    trucks[j] = trucks[j + 1];
                    trucks[j + 1] = temp;
                }
            }
        }
    }
    void display() const override
    {
        vehicle::display();
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
        cout << "Cargo Load: " << CargoLoad << " tons" << endl;
    }
};

class motorcycle : protected vehicle
{
    int horsepower;
    string numberPlate;

public:
    motorcycle(int id, string make, string model, float weight, int horsepower, string numberPlate) : vehicle(id, make, model, weight), horsepower(horsepower), numberPlate(numberPlate) {}
    float calculatePowertoWeightRatio() const
    {
        return horsepower / weight;
    }

    static void sortMotorcyclesByNumberPlateDigits(motorcycle **motorcycles, int count)
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                // number XY of first motorcycle
                string digit1 = motorcycles[j]->numberPlate.substr(2, 1);
                string digit2 = motorcycles[j]->numberPlate.substr(3, 1);
                int num1 = (digit1[0] - '0') + (digit2[0] - '0');

                // number XY of second
                string digit3 = motorcycles[j + 1]->numberPlate.substr(2, 1);
                string digit4 = motorcycles[j + 1]->numberPlate.substr(3, 1);
                int num2 = (digit3[0] - '0') + (digit4[0] - '0');

                if (num1 > num2)
                {

                    motorcycle *temp = motorcycles[j];
                    motorcycles[j] = motorcycles[j + 1];
                    motorcycles[j + 1] = temp;
                }
            }
        }
    }

    void display() const override
    {
        vehicle::display();
        cout << "Horsepower: " << horsepower << endl;
        cout << "Number Plate: " << numberPlate << endl;
    }
};

class vehicleRentalSystem
{
    car *cars[5];
    truck *trucks[5];
    motorcycle *motorcycles[5];
    int carCount;
    int truckCount;
    int motorcycleCount;

public:
    vehicleRentalSystem()
    {
        carCount = 0;
        truckCount = 0;
        motorcycleCount = 0;
    }

    void addcar(int id, string make, string model, float weight, float fuelEfficiency, int passengerCapacity)
    {
        if (carCount < 5)
        {
            cars[carCount++] = new car(id, make, model, weight, fuelEfficiency, passengerCapacity);
        }

        else
        {
            cout << "Full" << endl;
        }
    }

    void addtruck(int id, string make, string model, float weight, float cargoCapacity, float cargoLoad)
    {
        if (truckCount < 5)
        {
            trucks[truckCount++] = new truck(id, make, model, weight, cargoCapacity, cargoLoad);
        }
        else
        {
            cout << "Full" << endl;
        }
    }

    void addmotorcycle(int id, string make, string model, float weight, int horsepower, string numberPlate)
    {
        if (motorcycleCount < 5)
        {
            motorcycles[motorcycleCount++] = new motorcycle(id, make, model, weight, horsepower, numberPlate);
        }
        else
        {
            cout << "Full" << endl;
        }
    }

    void sortInventoryByAttribute()
    {
        car::sortCarsbyFuelEfficiency(cars, carCount);
        truck::sortTrucksByLoadFactor(trucks, truckCount);
        motorcycle::sortMotorcyclesByNumberPlateDigits(motorcycles, motorcycleCount);
    }

    void displayRental() const
    {
        cout << "Cars (ascending fuel efficiency)" << endl;
        for (int i = 0; i < carCount; i++)
        {
            cars[i]->display();
            cout << "---------------------------------------------" << endl;
        }
        cout << "************************************************" << endl;

        cout << "Trucks (ascending load factor): " << endl;
        for (int i = 0; i < truckCount; i++)
        {
            trucks[i]->display();
            cout << "---------------------------------------------" << endl;
        }
        cout << "************************************************" << endl;

        cout << "Motorcycles: (ascending numberplate digit values) " << endl;
        for (int i = 0; i < motorcycleCount; i++)
        {
            motorcycles[i]->display();
            cout << "------------------------------------------------" << endl;
        }
        cout << "*************************************************" << endl;
    }

    // helpers to test calculations
    car *getCar(int i) const
    {
        if (i < 0 || i >= carCount)
        {
            return nullptr;
        }
        return cars[i];
    }

    truck *getTruck(int i) const
    {
        if (i < 0 || i >= truckCount)
        {
            return nullptr;
        }
        return trucks[i];
    }

    motorcycle *getMotorcycle(int i) const
    {
        if (i < 0 || i >= motorcycleCount)
        {
            return nullptr;
        }

        return motorcycles[i];
    }
};

#include <iostream>
#include <string>
using namespace std;
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main()
{
    vehicleRentalSystem RentCars;
    int choice;
    bool exit = false;

    while (!exit)
    {
        cout << "Vehicle Rental System" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Add Truck" << endl;
        cout << "3. Add Motorcycle" << endl;
        cout << "4. Sort and Display Rental Inventory" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int id;
            string make, model;
            float weight, fuelEfficiency;
            int passengerCapacity;

            cout << "Enter Car Details" << endl;
            cout << "ID: ";
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID. Please enter a valid integer." << endl;
                break;
            }

            cout << "Make: ";
            cin.ignore();
            getline(cin, make);
            cout << "Model: ";
            getline(cin, model);

            cout << "Weight: ";
            cin >> weight;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid weight. Please enter a valid number." << endl;
                break;
            }

            cout << "Fuel Efficiency (km/l): ";
            cin >> fuelEfficiency;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid fuel efficiency. Please enter a valid number." << endl;
                break;
            }

            cout << "Passenger Capacity: ";
            cin >> passengerCapacity;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid passenger capacity. Please enter a valid integer." << endl;
                break;
            }

            RentCars.addcar(id, make, model, weight, fuelEfficiency, passengerCapacity);
            break;
        }
        case 2:
        {
            int id;
            string make, model;
            float weight, cargoCapacity, cargoLoad;

            cout << "Enter Truck Details" << endl;
            cout << "ID: ";
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID. Please enter a valid integer." << endl;
                break;
            }

            cout << "Make: ";
            cin.ignore();
            getline(cin, make);
            cout << "Model: ";
            getline(cin, model);

            cout << "Weight: ";
            cin >> weight;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid weight. Please enter a valid number." << endl;
                break;
            }

            cout << "Cargo Capacity (tons): ";
            cin >> cargoCapacity;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid cargo capacity. Please enter a valid number." << endl;
                break;
            }

            cout << "Cargo Load (tons): ";
            cin >> cargoLoad;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid cargo load. Please enter a valid number." << endl;
                break;
            }

            RentCars.addtruck(id, make, model, weight, cargoCapacity, cargoLoad);
            break;
        }
        case 3:
        {
            int id, horsepower;
            string make, model, numberPlate;
            float weight;

            cout << "Enter Motorcycle Details" << endl;
            cout << "ID: ";
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID. Please enter a valid integer." << endl;
                break;
            }

            cout << "Make: ";
            cin.ignore();
            getline(cin, make);
            cout << "Model: ";
            getline(cin, model);

            cout << "Weight: ";
            cin >> weight;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid weight. Please enter a valid number." << endl;
                break;
            }

            cout << "Horsepower: ";
            cin >> horsepower;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid horsepower. Please enter a valid number." << endl;
                break;
            }

            cout << "Number Plate (format: XX99YY): ";
            cin >> numberPlate;

            RentCars.addmotorcycle(id, make, model, weight, horsepower, numberPlate);
            break;
        }
        case 4:
            RentCars.sortInventoryByAttribute();
            cout << "************************************************" << endl;
            RentCars.displayRental();
            break;
        case 5:
            exit = true;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "Thank you for using the Vehicle Rental System." << endl;

    return 0;
}
