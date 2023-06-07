#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

// void test()
// {
// 	{
// 		std::cout <<RED "---------------- Subject Example ----------------" END<< std::endl;
// 		const Animal *j = new Dog();
// 		const Animal *i = new Cat();

// 		delete j;
// 		delete i;
// 	}

// 	{
// 		std::cout <<RED "\n---------------- Subject for Pure Virtual Example ----------------" END<< std::endl;
// 		// Animal all;
// 		// Animal old = Animal();
// 		// Class'lar artık "Abstract Class" olduklarında doğrudan kendi class tiplerinde nesne(object) oluşturamazlar, alt classları ile oluşturulabilirler.
// 	}
// }

int	main(){

	{
		std::cout <<RED "---------------- Subject Example ----------------" END<< std::endl;
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		delete j;
		delete i;
	}

	{
		std::cout <<RED "\n---------------- Subject for Pure Virtual Example ----------------" END<< std::endl;
		// Animal all;
		// Animal old = Animal();
		// Class'lar artık "Abstract Class" olduklarında doğrudan kendi class tiplerinde nesne(object) oluşturamazlar, alt classları ile oluşturulabilirler.
	}
	// test();
	// system("leaks Pure");
	return (0);
}
