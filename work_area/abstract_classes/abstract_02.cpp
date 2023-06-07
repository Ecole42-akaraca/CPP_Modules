#include <iostream>
#include <string>

class Brain {
   public:
    std::string ideas[100];
};

class Animal {
   protected:
    Brain* brain;

   public:
    Animal() {
        brain = new Brain();
    }

    virtual ~Animal() {
        delete brain;
    }

    virtual void speak() = 0;
};

class Dog : public Animal {
   public:
    void speak() {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
   public:
    void speak() {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    const int num_animals = 6;  // Array size
    Animal* animals[num_animals];

    // Fill the array with dogs and cats
    for (int i = 0; i < num_animals; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Loop over the array and call the speak function on each animal
    for (int i = 0; i < num_animals; i++) {
        animals[i]->speak();
    }

    // Delete each animal properly
    for (int i = 0; i < num_animals; i++) {
        delete animals[i];
    }

    return 0;
}