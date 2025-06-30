/*

#include <iostream>
#include <memory>
using namespace std;

class Shapes {
public:
    void virtual printShape() const = 0;
    virtual ~Shapes(){}

};

class Square: public Shapes {
public:
    void printShape()const override {
        cout << "Shape is Square" << endl;
    }

};

class Circle: public Shapes {
public:
    void printShape() const override {
        cout << "Shape is Circle" << endl;
    }
};

class Triangle: public Shapes {
public:
    void printShape() const override {
        cout << "Shape is Triangle" << endl;
    }
};


class ShapeFactory{

public:
    static unique_ptr<Shapes> createShape(const string& type) {
        if (type == "Circle") {
            return make_unique<Circle>();
        } else if (type == "Square") {
            return make_unique<Square>();
        } else if (type == "Triangle") {
            return make_unique<Triangle>();
        } else {
            return nullptr;
        }

    }

};


int main() {
    unique_ptr<Shapes> shape1 = ShapeFactory::createShape("Circle");
    shape1->printShape();

    unique_ptr<Shapes> shape2 = ShapeFactory::createShape("Square");
    shape2->printShape();

    unique_ptr<Shapes> shape3 = ShapeFactory::createShape("Triangle");
    shape3->printShape();

    return 0;

}

*/




#include<iostream>
#include<memory>
#include<vector>
using namespace std;

// Abstract Class with at least one pure virtual function
class Vehicle{
    public:
        virtual void showVehicle() const = 0;
        virtual ~Vehicle(){};
};

// Concrete class
class Bike: public Vehicle{
    public:
        void showVehicle() const override {
            cout<< "Its a Bike" << endl;
        }
};

// Concrete class
class Car: public Vehicle{
    public:
        void showVehicle() const override {
            cout<< "Its a Car" << endl;
        }

};

// Concrete class
class Aeroplane: public Vehicle{
    public:
        void showVehicle() const override {
            cout<< "Its an Aeroplane" << endl;
        }
};

// Concrete class
class Truck: public Vehicle{
    public:
        void showVehicle() const override {
            cout<< "Its an Truck" << endl;
        }
};

// Factory class
class VehicleFactory{
    public:
        static unique_ptr<Vehicle> createVehicle (const string& type){
            if (type == "Bike") {
                return make_unique<Bike>();
            } else if (type == "Car") {
                return make_unique<Car>();
            }  else if (type == "Aeroplane") {
                return make_unique<Aeroplane>();
            }  else if (type == "Truck") {
                return make_unique<Truck>();
            } else return nullptr;
        }
};


// config file. Just adding in config file would create new objects. there is no need to Client code.
class Config{
    public:
        static vector<string> readVehicleTypesFromConfig(){
            return {"Bike", "Car", "Aeroplane", "Truck"};
        }
};


// Client Side code
int main(){
    /*
    unique_ptr<Vehicle> vehicle1 = VehicleFactory::createVehicle("Bike");
    vehicle1->showVehicle();

    unique_ptr<Vehicle> vehicle2 = VehicleFactory::createVehicle("Car");
    vehicle2->showVehicle();

    unique_ptr<Vehicle> vehicle3 = VehicleFactory::createVehicle("Aeroplane");
    vehicle3->showVehicle();

    vector<unique_ptr<Vehicle>> vehicleList;
    vehicleList.push_back(move(vehicle1));
    vehicleList.push_back(move(vehicle2));
    vehicleList.push_back(move(vehicle3));
    
    for (const auto& vehicle : vehicleList){
        vehicle->showVehicle();
    } 
    */

    vector<string> vehicleTypes = Config::readVehicleTypesFromConfig();

    vector<unique_ptr<Vehicle>> vehicleList;
    for (const string& type : vehicleTypes) {
        vehicleList.push_back(VehicleFactory::createVehicle(type));
    }

    for (const auto& vehicle : vehicleList) {
        if (vehicle) {
            vehicle->showVehicle();
        } else {
            cout << "Error: No vehicle encountered!" << endl;   
        }
    }


    return 0;
}

