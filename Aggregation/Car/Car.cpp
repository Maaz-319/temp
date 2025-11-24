#include "Engine.cpp"

class Car{
    string name;
    Engine engine;
    public:
    Car(string n, int power, string type): engine(power, type) {
        name = n;
    }

    void showCar() {
        cout << "\nCar Brand: " << name << "\nEngine: " << engine.power << " HP, Type: " << engine.type;
    }
};

int main() {
    Car c("Toyota", 180, "Hybrid");
    c.showCar();
    return 0;
}