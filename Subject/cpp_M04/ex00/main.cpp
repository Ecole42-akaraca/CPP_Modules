#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void test()
// {
// 	{
// 		std::cout <<RED "---------------- Subject Example ----------------" END<< std::endl;
// 		const Animal *meta = new Animal();
// 		/*
// 			Tip dönüşümünde, base class'da makeSound fonk. virtual yapıya sahip olduğundan dolayı kendi class'ı içerisindeki fonk. çağıracaktır.
// 		*/
// 		const Animal *j = new Dog();
// 		const Animal *i = new Cat();

// 		std::cout << j->getType() << " " << std::endl;
// 		std::cout << i->getType() << " " << std::endl;

// 		i->makeSound();
// 		j->makeSound();
// 		meta->makeSound();

// 		delete j;
// 		delete i;
// 		delete meta;
// 	}

// 	{
// 		std::cout <<RED "\n---------------- Subject WrongAnimal Example ----------------" END<< std::endl;
// 		const WrongAnimal *meta = new WrongAnimal();
// 		const WrongAnimal *i = new WrongCat();

// 		std::cout << i->getType() << " " << std::endl;

// 		i->makeSound();
// 		meta->makeSound();
// 		//makeSound methodu virtual olmadığından dolayı base class'ın methodunu kullanır bu yüzden istenilen çıktı alınamaz.

// 		delete	i;
// 		delete	meta;
// 		//i nesnesini delete yaparken, base class'ın destructor'u virtual olmadığından dolayı cat class'ının destructoru çağrılmaz bu yüzden leak oluşur.
// 	}
// }

/*
	Önemli bir not!!!: Class içindeki fonksiyon olarak belirttiğim işlemler aslında method olarak adlandırılıyor.
*/
int	main(){

	//scope
	{
		std::cout <<RED "---------------- Subject Example ----------------" END<< std::endl;
		const Animal *meta = new Animal();
		/*
			Tip dönüşümünde, base class'da makeSound fonk. virtual yapıya sahip olduğundan dolayı kendi class'ı içerisindeki fonk. çağıracaktır.
		*/
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete j;
		delete i;
		delete meta;
	}

	{
		std::cout <<RED "\n---------------- Subject WrongAnimal Example ----------------" END<< std::endl;
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		meta->makeSound();
		//makeSound methodu virtual olmadığından dolayı base class'ın methodunu kullanır bu yüzden istenilen çıktı alınamaz.

		delete	i;
		delete	meta;
		//i nesnesini delete yaparken, base class'ın destructor'u virtual olmadığından dolayı cat class'ının destructoru çağrılmaz bu yüzden leak oluşur.
	}
	// test();
	// system("leaks Polymorphism");
	return (0);
}
