#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/*
	Subject Çeviri:
		Form doldurmak yeterince can sıkıcı olduğundan dolayı,
			 bu işi gün gün boyunca bürokratlarımızdan bunu yapmasını istemek zalimlik olur.
			Neyseki stajyerler var.
		Bu alıştırmada, Intern sınıfını uygulamalısınız.
		Stajyerin adı, derecesi, benzersiz özellikleri yoktur.
		Bürokratların umursadığı tek şey işlerini yapmalarıdır.

	Ancak stajyerlerin önemli bir kapasitesi vardır:
		-> makeForm() işlevi
			: iki dizi alır. Birincisi bir formun adı, ikincisi ise formun hedefidir.
			: Hedefi ikinci parametreye başlatılacak olan bir Form nesnesine (adı parametre olarak iletilen olan) bir işaretçi döndürür.

	Çıktı şu şekilde olmalıdır:
		-> Intern creates <form>
		-> Parametre olarak iletilen form adı yoksa açık bir hata mesajı yazdırın.

	if/elseif/else ormanı kullanmak gibi okunamayan ve çirkin çözümlerden kaçınmalısınız.
	Değerlendirme sürecinde bu tür şeyler kabul edilmeyecektir.
	Artık Piscine'de (havuzda) değilsiniz.
	Her zamanki gibi, her şeyin beklendiği gibi çalıştığını test etmeniz gerekir.
	Örneğin, aşağıdaki kod "Bender" üzerinde hedeflenen bir RobotomyRequestForm oluşturur:
-------------------------------------------------------------------------------------------------------
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
-------------------------------------------------------------------------------------------------------
*/

/*
Url:

Yorum:
	Burada stajyerin yapacağı iş, formu doldurmaktır, yani bir önceki proje bizlere verilen 3 farklı formun,
		stajyer tarafından isteğe bağlı bir şekilde oluşturulacağıdır.
		İmzalama ve yürütme işlemleri bürokratlar tarafından aynı şekilde sağlanmaktadır.
*/
void leak(){

	{
		std::cout << RED "---------------- Subject Example (LEAK) ----------------" END<< std::endl;
		/* Subject'de verilen örnek kod bloğu, burada istisna döndürülmeyeceği bilindiğiden dolayı try-catch kullanılmamıştır,
			lakin oluşturduğumuz form heap'te yer açılarak oluşturulduğundan dolayı delete edilmelidir,
			burada leak vardır. */
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}

	{
		std::cout << RED "---------------- Simple Example ----------------" END<< std::endl;
		/* Bu projede bizden istenilen: stajyerin istenilen formu oluşturmasıdır. */
		try
		{
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *rrf << std::endl;
			if (rrf)
				delete rrf;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << RED "---------------- Standard Example ----------------" END << std::endl;
		/* Stajyer ve bürokratların birlikte kullanım örneği */
		try
		{
			Bureaucrat Alice("Alice", 33);
			std::cout << Alice << std::endl;

			Intern Stajyer;
			AForm *form;
			form = Stajyer.makeForm("presidential pardon", "Sorry");
			std::cout << *form << std::endl;

			Alice.signForm(*form);

			std::cout << *form << std::endl;

			Alice.executiveForm(*form);

			if (form)
				delete form;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << RED "---------------- Standard Example (1) ----------------" END << std::endl;
		try
		{
			Bureaucrat John("John", 21);
			std::cout << John << std::endl;

			Intern Stajyer;
			AForm *form;
			form = Stajyer.makeForm("Shrubbery Creation", "Tree");
			std::cout << *form << std::endl;

			John.signForm(*form);

			std::cout << *form << std::endl;

			John.executiveForm(*form);

			if (form)
				delete form;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << RED "---------------- Standard Example (2) ----------------" END << std::endl;
		/* Tüm formların çalışma örneği */
		try
		{
			Bureaucrat Jack("Jack", 21);
			std::cout << Jack << std::endl;

			Intern Stajyer;
			AForm *formP;
			AForm *formR;
			AForm *formS;
			formP = Stajyer.makeForm("presidential pardon", "PARDON");
			std::cout << *formP << std::endl;

			formR = Stajyer.makeForm("robotomy request", "REQUEST");
			std::cout << *formR << std::endl;

			formS = Stajyer.makeForm("shrubbery creation", "CREATION");
			std::cout << *formS << std::endl;

			Jack.signForm(*formP);
			Jack.signForm(*formR);
			Jack.signForm(*formS);

			std::cout << *formP << std::endl;
			std::cout << *formR << std::endl;
			std::cout << *formS << std::endl;

			Jack.executiveForm(*formP);
			Jack.executiveForm(*formR);
			Jack.executiveForm(*formS);

			if (formP)
				delete formP;
			if (formR)
				delete formR;
			if (formS)
				delete formS;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << RED "---------------- Standard Example (3) (LEAK) ----------------" END << std::endl;
		/* Bir formun stajyer tarafından oluşturulup, diğer formun oluşturulamadığı zamanda nasıl bir durum sergilendiğini öğrenmek için oluşturuldu.
			formA, formB'den önce oluşturulduğundan ve formB hatalı olduğundan dolayı istisna döndürecektir,
			bu durumda formA'nın işaretçi değişkeni try'ın altında olduğundan dolayı, catch kısmında freelemiyoruz bundan dolayı leak oluşuyor.
			 */
		try
		{
			Bureaucrat Michel("Michel", 11);
			std::cout << Michel << std::endl;

			Intern Stajyer;
			AForm *formA = nullptr;
			AForm *formB = nullptr;
			formA = Stajyer.makeForm("shrubbery creation", "Tree");
			std::cout << *formA << std::endl;

			formB = Stajyer.makeForm("Robotomy Request", "robot");
			std::cout << *formB << std::endl;

			Michel.signForm(*formA);
			Michel.signForm(*formB);

			std::cout << *formA << std::endl;
			std::cout << *formB << std::endl;

			Michel.executiveForm(*formA);
			Michel.executiveForm(*formB);

			if (formA != nullptr)
				delete formA;
			if (formB != nullptr)
				delete formB;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << RED "---------------- Standard Example (4)----------------" END << std::endl;
		/* Standard Example (3)'nin leaksiz hali,
			oluşturulan AForm nesnesine atama yapmadan çıktısını alamayız!!!.
			*/
		AForm *formA = nullptr;
		AForm *formB = nullptr;
		try
		{
			Bureaucrat Michel("Michel", 11);
			std::cout << Michel << std::endl;

			Intern Stajyer;
			formA = Stajyer.makeForm("shrubbery creation", "Tree");
			std::cout << *formA << std::endl;

			formB = Stajyer.makeForm("Robotomy Request", "robot");
			std::cout << *formB << std::endl;

			Michel.signForm(*formA);
			Michel.signForm(*formB);

			std::cout << *formA << std::endl;
			std::cout << *formB << std::endl;

			Michel.executiveForm(*formA);
			Michel.executiveForm(*formB);

			if (formA != nullptr)
				delete formA;
			if (formB != nullptr)
				delete formB;
		}
		catch(const std::exception &e)
		{
			if (formA != nullptr)
				delete formA;
			if (formB != nullptr)
				delete formB;
			std::cerr << e.what() << std::endl;
		}
	}

}

int	main(){

	leak();
	// system("leaks Form");
	return (0);
}
