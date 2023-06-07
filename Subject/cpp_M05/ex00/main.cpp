#include <iostream>
#include "Bureaucrat.hpp"

/*
	Subject Çeviri:
		exception class'lar Orthodox Canoncial Form'a uymak zorunda değildir.

	Ofisler, koridorlar, formlar ve bekleme kuyruklarından oluşan yapay bir kabus tasarlayın.

	Bürokrat class'ını oluşturun(Bureaucrat).

	Bürokrat sınıfı şunları içermektedir:
		-> "A constant name"
			: const name oluşturun.
		
		-> A grade that ranges from 1 (highset possible grade) to 150 (lowest possible grade).
			: 1 en yüksek not/seviye, 150 en düşük not/seviye arasında değişmektedir.

	Geçersiz bir not kullanarak bir Bürokrat örneği oluşturmaya yönelik herhangi bir girişim bir istisna atmalıdır/vermelidir(must throw an exception):
		: "Bureaucrat::GradeTooHighException" veya "Bureaucrat::GradeTooLowException" atmalıdır/vermelidir.

	Bu özniteliklerin(name ve grade) her ikisi için de alıcılar/method/fonksiyon sağlanmalıdır.
		: "getName()" ve "getGrade()" methodları kullanılmalıdır.
	Bürokrat notunu arttırmak veya azaltmak için iki üye işlevi(method)'de uygulayın.
	Derece aralığın dışındaysa, her ikiside oluşturucuyla aynı istisnaları atar/fırlatır/verir.

	!!! 1.derece en yüksek, 150.derece en düşük olduğu için, bürokrat seviyesini arttırmak için:
		Bürokrat seviyesi 3 ise, 2 verilmelidir.
	
	Fırlatılan istisnalar, try ve catch blokları kullanılarak yakalanabilir olmalıdır.
-------------------------------------------------------------------------------------------------------------
	try
	{
		// do some stuff with bureaucrats
		// bürokratlarala bir şeyler yapmak
	}
	catch (std::exception & e)
	{
		// handle exception
		// istisna eklemek
	}
-------------------------------------------------------------------------------------------------------------

	"<<" operatörü ile bir şeyler yazdırmak için aşırı yükleme uygulayacaksınız.
		: <name>, bureaucrat grade <grade>.
	Her şeyin doğru bir şekilde çalıştığını kanıtlamak için bazı testler uygulayın.
*/

/*
Url:
	https://cplusplus.com/doc/tutorial/exceptions/
	https://stackoverflow.com/questions/22493294/what-is-the-meaning-of-this-header-virtual-const-char-what-const-throw
	https://en.cppreference.com/w/cpp/language/noexcept_spec

Yorum:
	try-catch bloklarıyla hata ayıklama işlemini gerçekleştirebiliyoruz.
	Bu işlem türü run time esnasında gerçekleşir.
	Bu işlemde amaç hatanın nerede ve ne zaman olduğunu kontrol etmeyi değil,
		kontrol dışı gelişen hataları kullanıcıya göstermektir.
	
	"catch(const std::exception &e)" exception sınıfından türetilen hataları yakalamak için kullanılır.
	Bu kod bloğu herhangi bir std::exception tipindeki hatayı yakalar ve hatanın ne olduğuna dair bilgileri
		"e" adlı bir nesneye aktarır. Bu nesne, hatanın türüne ve ayrıntılarına erişmek için kullanılır.

	Bu yapı, programın hata durumlarıyla başa çıkmasını sağlar ve programın beklenmeyen bir şekilde çökmesini veya durmasını engelleyebilir.
	Hata durumlarının nasıl ele alınacağına karar vermek için catch bloğuna uygun kod eklenmelidir.

	Try-catch blokları, hata durumlarını yakalama ve işleme için ek bellek kullanımı gerektirebilir,
		ancak, programın güvenliğini artırır ve beklenmedik hata durumlarından korur.

-------------------------------------------- --------------------------------------------
	catch(const std::exception e)			| 	catch(const std::exception &e)
	{										|	{
		std::cerr << e.what() << std::endl;	|		std::cerr << e.what() << std::endl;
	}										|	}
-------------------------------------------- --------------------------------------------
	Üstteki örneklerde;
	- "e" ifadesinde, istisnanın kopyası yakalama değişkenine atanır.
		Bu, istisnanın bellekteki yeni bir alanını oluşturur ve daha fazla bellek kullanır.
		Ancak, yakalama değişkeninin değeri değiştirilebilir, bu nedenle bu kullanım, 
		yakalama değişkeninin değerini değiştirmek gerektiği durumlarda kullanılabilir.
		
	- "&e" ifadesinde, istisnanın referans türünde bir yakalama değişkeni tanımlanır.
		Bu, istisna atıldığında yakalama bloğuna geçirilen istisnanın referansını tutar.
		Buradaki amaç, istisnanın kendisini yakalmak yerine, yakalama değişkeni aracılıyla yakalama bloğu içinde kullanım kolaylığı sağlar.
		Yakalama değişkeninin referans türü, maliyeti düşük ve verimli bir yol sağlar.
		İstisnanın kopyalanması yerine, yalnızca referansı taşındığı için daha hızlı ve daha az bellek kullanır.
		Ayrıca, 'const' anahtar kelimesi kullanarak, yakalama değişkeninin değerinin değiştirilmesini önlersiniz.
		Bu nedenle '&e' ifadesi, hem işlevsel hem de performans açısından iyi bir tercihtir.		
*/
int	main(){

	{
		std::cout <<RED "---------------- Different Try-Catch Int Example ----------------" END<< std::endl;
		/* Basit bir int try catch örneği */
		try
		{
			int x = 10;
			while (1)
			{
				if (x == 0)
					throw 1;
				else
					x--;
			}
		}
		catch(int value)
		{
			if (value == 1)
				std::cout << "int: x is equal to zero!" << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Different Try-Catch Char Example ----------------" END<< std::endl;
		/* Basit bir char try catch örneği */
		try
		{
			int x = 10;
			while (1)
			{
				if (x == 0)
					throw 'a';
				else
					x--;
			}
		}
		catch(char word)
		{
			if (word == 'a')
				std::cout << "char: x is equal to zero!" << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Different Try-Catch to many Catch Exception Example ----------------" END<< std::endl;
		/* Basit bir try catch örneği, tüm istisnaları yakalama */
		try
		{
			// int x = -10;
			// int x = 10;
			int x = 100;
			while (1)
			{
				if (x > 99)
					throw 'x';
				else if (x < 0)
					throw -1;
				else if (x == 0)
					throw 1;
				else
					x--;
			}
		}
		catch(char word) // sadece char istisnalarını yakalar
		{
			std::cout << "word: x is equal to zero!" << std::endl;
		}
		catch(int value) // sadece int istisnalarını yakalar
		{
			std::cout << "value: x is equal to zero!" << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Different Try-Catch All Exception Example ----------------" END<< std::endl;
		/* Basit bir try catch örneği, tüm istisnaları yakalama */
		try
		{
			// int x = -10;
			// int x = 10;
			int x = 100;
			while (1)
			{
				if (x > 99)
					throw 'x';
				else if (x < 0)
					throw -1;
				else if (x == 0)
					throw 1;
				else
					x--;
			}
		}
		catch(...) //tüm istisnaları yakalamak için "..." kullanılır
		{
			std::cout << "x is not suitable" << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Standard Output - No Exception Example ----------------" END<< std::endl;
		/* İstisna olmadan standart çıktı örneği */
		try
		{
			Bureaucrat Sam("Sam", 42);
			std::cout << Sam << std::endl;
		}
		catch(const std::exception &e) // sadece std istisnalarını yakalar
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Too High Grade Example ----------------" END<< std::endl;
		/* Derecesi çok yüksek olan yapıcıyı çağırırken istisna atın */
		try
		{
			Bureaucrat Jack("Jack", 0);
			std::cout << Jack << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Too Low Grade Example ----------------" END<< std::endl;
		/* Derecesi çok düşük olan yapıcıyı çağırırken istisna atın */
		try
		{
			Bureaucrat Michael("Michael", 170);
			std::cout << Michael << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Calling Grade Up Example ----------------" END<< std::endl;
		/* Derece yükseltirken istisna atın */
		try
		{
			Bureaucrat Jim("Jim", 3);
			std::cout << Jim << std::endl;
			Jim.upGrade();
			std::cout << Jim << std::endl;
			Jim.upGrade();
			std::cout << Jim << std::endl;
			Jim.upGrade();
			std::cout << Jim << std::endl;
			Jim.upGrade();
			std::cout << Jim << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Calling Grade Down Example ----------------" END<< std::endl;
		/* Derece azaltırken istisna atın */
		try
		{
			Bureaucrat Emanuel("Emanuel", 147);
			std::cout << Emanuel << std::endl;
			Emanuel.downGrade();
			std::cout << Emanuel << std::endl;
			Emanuel.downGrade();
			std::cout << Emanuel << std::endl;
			Emanuel.downGrade();
			std::cout << Emanuel << std::endl;
			Emanuel.downGrade();
			std::cout << Emanuel << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Calling Copy Example ----------------" END<< std::endl;
		/* Nesnelerin eşitlenmesi */
		try
		{
			Bureaucrat Arthur("Arthur", 25);
			std::cout << Arthur << std::endl;
			Bureaucrat ArthurTwin(Arthur);
			std::cout << ArthurTwin << std::endl;

			Bureaucrat Alfred("Alfred", 44);
			std::cout << Alfred << std::endl;
			Alfred = Arthur;
			std::cout << Alfred << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout <<RED "---------------- Without Try-Catch True Use Example ----------------" END<< std::endl;
		/* Try - Catch olmadan doğru kullanılırsa */
		Bureaucrat Emily("Emily", 100);
		std::cout << Emily << std::endl;
	}

	// {
	//	// Hata döndürüyor
	// 	std::cout <<RED "---------------- Without Try-Catch Wrong Use Example ----------------" END<< std::endl;
	// 	/* Try - Catch olmadan yanlış kullanılırsa ve istisna döndürmeye çalışırsa abort döndürür.
	//  	İstisnasyı tutacak bir yapı olmadığından dolayı hata döndürüyor.
	//		*/
	// 	Bureaucrat Felix("Felix", 0);
	// 	std::cout << Felix << std::endl;
	// }

	// {
	//	// Hata döndürüyor
	// 	std::cout <<RED "---------------- Standard/Normal Exception Handling Example ----------------" END<< std::endl;
	// 	/* Try - Catch yapısı ile nerede karşılaşirizin örneği, "floating point exception" döndürecektir. */
	// 	int s1 = 0, s2 = 10;
	// 	int a = s2 / s1;
	// 	(void)a;
	// }

	// {
	// 	// Hata döndürüyor
	// 	std::cout <<RED "---------------- Uncaught Exception Example ----------------" END<< std::endl;
	// 	/* Fırlatılan istisna değerinin tutacak bir catch değeri yoksa döndürülen hatadır.
	//		Fırlatılan değer int, tutucu değer bir class olduğundan dolayı hata verecektir.
	// 		*/
	// 	try
	// 	{
	// 		int x = 10;
	// 		if(x == 10)
	// 			throw 1;
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cerr << "VaaDAA" << std::endl;
	// 	}
	// 	// catch(...)
	// 	// {
	// 	// }
	// }

	return (0);
}
