#include "Component.cpp"

class Computer{
    string name;
    int count = 0;
    Component * components;

    public:

    Computer(const string& s) {
        name = s;
        components = new Component[10];
    }
    void addComponent(const Component& c){
        if (count < 10) {
            components[count++] = c;
        }
    }
    void showComputer() {
        cout << "Computer Brand: " << name << " ";
        for(int i=0; i<count;i++) components[i].showComponent();
    }
    ~Computer() {
        delete[] components;
    }
};

int main() {
    Computer pc("Dell");
    pc.addComponent(Component("CPU", "3.4 GHZ"));
    pc.addComponent(Component("RAM", "16 GB"));
    pc.addComponent(Component("STORAGE", "512 GB SSD"));
    pc.showComputer();
    return 0;
}