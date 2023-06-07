#include <iostream>
using namespace std;

// Hayvanlar sınıfı (Animal class)
class Animal {
public:
    virtual void sound() {
        cout << "Hayvan sesi." << endl;
    }
};

// Köpekler sınıfı (Dogs class), Hayvanlar sınıfından türetilmiştir.
class Dogs : public Animal {
public:
    void sound() override {
        cout << "Hav Hav." << endl;
    }
};

// Kediler sınıfı (Cats class), Hayvanlar sınıfından türetilmiştir.
class Cats : public Animal {
public:
    void sound() override {
        cout << "Miyav." << endl;
    }
};

int main() {
    // Hayvanlar sınıfından bir örnek oluşturulur.
    Animal* myAnimal;

    // Köpekler sınıfından bir örnek oluşturulur ve myAnimal işaretçisine atanır.
    Dogs myDog;
    myAnimal = &myDog;

    // Köpekler sınıfında ezilmiş olan sound() işlevi çağrılır.
    myAnimal->sound();

    // Kediler sınıfından bir örnek oluşturulur ve myAnimal işaretçisine atanır.
    Cats myCat;
    myAnimal = &myCat;
    
    myAnimal->sound();
}
