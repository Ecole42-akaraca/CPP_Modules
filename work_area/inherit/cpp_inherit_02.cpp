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
class Dogs : virtual public Animal {
    
protected:
    int a;
public:
	Dogs():Animal(){}
    void sound() {
        cout << "Hav Hav." << endl;
    }
};

// Kediler sınıfı (Cats class), Hayvanlar sınıfından türetilmiştir.
class Cats : virtual public Animal {
public:
	Cats(): Animal(){
	}
    void sound(){
        cout << "Miyav." << endl;
    }
};

class Cow : public Dogs, public Cats {
    
private:
    int k;
    public:
		Cow(): Animal(), Dogs(), Cats(){
		}
        void sound() {
            
            cout << "lol" << endl;
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
