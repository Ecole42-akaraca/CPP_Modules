#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
// 		std::cout <<RED "\n---------------- Subject Array Example ----------------" END<< std::endl;
// 		Animal *animals[5];
// 		for(int i = 0; i < 5; i++)
// 		{
// 			if (i % 2 == 0)
// 				animals[i] = new Dog();
// 			else
// 				animals[i] = new Cat();
// 		}
// 		for(int i = 0; i < 5; i++)
// 			delete animals[i];

// 	}

// 	{
// 		std::cout <<RED "\n---------------- Subject Deep Copy Example ----------------" END<< std::endl;
// 		Cat b;
// 		b.getBrain()->setIdea(0, "one");
// 		Cat a = b;
// 		std::cout << "b - memory: " << b.getBrain()->getIdea(0) << std::endl;
// 		std::cout << "a - memory: " << a.getBrain()->getIdea(0) << std::endl;
// 		a.getBrain()->setIdea(0, "two");
// 		std::cout << "b - memory: " << b.getBrain()->getIdea(0) << std::endl;
// 		std::cout << "a - memory: " << a.getBrain()->getIdea(0) << std::endl;
// 	}

// 	{
// 		std::cout <<RED "\n---------------- Subject Shallow Copy Example ----------------" END<< std::endl;
// 		// WrongCat b;
// 		// b.getBrain()->setIdea(0, "one");
// 		// WrongCat a = b;
// 		// std::cout << "b - memory: " << b.getBrain()->getIdea(0) << std::endl;
// 		// std::cout << "a - memory: " << a.getBrain()->getIdea(0) << std::endl;
// 		// a.getBrain()->setIdea(0, "two");
// 		// std::cout << "b - memory: " << b.getBrain()->getIdea(0) << std::endl;
// 		// std::cout << "a - memory: " << a.getBrain()->getIdea(0) << std::endl;
// 		// Bu yapı segmentation fault verecektir, sebebi Cat class'ı içinde bulunan Brain class'nın ortaklaşa(ref göstermesinden dolayı) kullanılmasından dolayıdır.
// 	}

// 	{
// 		std::cout <<RED "\n---------------- Subject for not Pure Virtual Example ----------------" END<< std::endl;
// 		Animal all;
// 		Animal old = Animal();
// 	}
// }

/*
	-> "A copy of a Dog or a Cat mustn’t be shallow."
	: "mustn't be shallow" ifadesi, nesnelerin bellek alanının sadece bir kısmının kopyalanmasına izin veren "shallow copy" işleminden kaçınmaya işaret eder.
		"Shallow copy" işlemi, bir nesnenin adresini başka bir nesneye atar veya bir nesnenin bellek alanının yalnızca bir kısmını başka bir nesneye kopyalar.
		Bu durumda, her iki nesne de aynı bellek alanını kullanır ve bir nesne değiştirildiğinde, diğer nesne de değişir.
		Bu beklenmedik sonuçlara yol açabilir.

	Shallow Copy(Yüzeysel kopya) yönteminde ilk nesne üzerinden farklı bir nesne oluşturulur fakat nesne içerisindeki değerler ilk nesne içerisindeki değerlerin bellek referansı aynı olacak şekilde kopyalanır.
	Bir başka deyişle ikinci nesne içerisine değerler kopyalanırken direk içerikleri ile kopyalanmazlar ve bellek referansları ile kopyalanırlar.
	
	-> "Thus, you have to test that your copies are deep copies!"
	: Deep copy(Detay,derin kopya) terimi ise nesnenin değerlerinin ve tamamının içerikleri ile kopyalanması ve yeni bellek referansı oluşturulmasını ifade eder.
	Kopya üzerindeki nesneler farklı bellek referanslarını işaret edeceği için kopya nesne üzerinde yapılan değişiklikler ilk nesneyi etkilemeyecektir.
*/
int	main(){

	{
		std::cout <<RED "---------------- Subject Example ----------------" END<< std::endl;
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		delete j;
		delete i;
	}

	{
		std::cout <<RED "\n---------------- Subject Array Example ----------------" END<< std::endl;
		Animal *animals[5];
		for(int i = 0; i < 5; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for(int i = 0; i < 5; i++)
			delete animals[i];

	}

	{
		std::cout <<RED "\n---------------- Subject Deep Copy Example ----------------" END<< std::endl;
		Cat b;
		b.getBrain()->setIdea(0, "one");
		Cat a = b;
		std::cout << "b - memory: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << "a - memory: " << a.getBrain()->getIdea(0) << std::endl;
		a.getBrain()->setIdea(0, "two");
		std::cout << "b - memory: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << "a - memory: " << a.getBrain()->getIdea(0) << std::endl;
	}

	{
		std::cout <<RED "\n---------------- Subject Shallow Copy Example ----------------" END<< std::endl;
		// WrongCat b;
		// b.getBrain()->setIdea(0, "one");
		// WrongCat a = b;
		// std::cout << "b - memory: " << b.getBrain()->getIdea(0) << std::endl;
		// std::cout << "a - memory: " << a.getBrain()->getIdea(0) << std::endl;
		// a.getBrain()->setIdea(0, "two");
		// std::cout << "b - memory: " << b.getBrain()->getIdea(0) << std::endl;
		// std::cout << "a - memory: " << a.getBrain()->getIdea(0) << std::endl;
		// Bu yapı segmentation fault verecektir, sebebi Cat class'ı içinde bulunan Brain class'nın ortaklaşa(ref göstermesinden dolayı) kullanılmasından dolayıdır.
	}

	{
		std::cout <<RED "\n---------------- Subject for not Pure Virtual Example ----------------" END<< std::endl;
		Animal all;
		Animal old = Animal();
	}
	// test();
	// system("leaks Brain");
	return (0);
}
