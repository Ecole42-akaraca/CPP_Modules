#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
	Subject Çeviri:
		Artık temel formlara sahip olduğumuza göre, gerçekten bir şey yapan birkaç tane daha yapmanın zamanı geldi.

	Her durumda, Form temel(base) sınıfı "soyut(abstract)bir sınıf" olmalıdır ve bu nedenle AForm olarak yeniden adlandırılmalıdır.
	Form özniteliklerinin gizli kalması gerektiğini ve temel sınıfta olduklarını unutmayın.

	Aşağıdaki somut sınıfları ekleyin.
	->	ShrubberyCreationForm: Required grades: sign 145, exec 137
		Create a file <target> _shrubbery in the working directory, and write ASCII trees inside it.
		: "ShrubberyCreationForm" sınıfını oluşturun ve imza yetki seviyesi 145, yürütme yetki seviyesini 137 olarak tanımlayın.
		: Çalışma dizininde bir <target> _shrubbery dosyası oluşturun ve içine "ASCII trees" yazın.

	->	RobotomyRequestForm: Required grades: sign 72, exec 45
		Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time.
		Otherwise, informs that the robotomy failed.
		: "RobotomyRequestForm" sınıfını oluşturun ve imza yetki seviyesi 72, yürütme yetki seviyesini 45 olarak tanımlayın.
		: Bazı delme sesleri çıkarır. Ardından <target> %50 şansla başarılı bir şekilde robotize edildiğini bildirir. Aksi halde robotomy'ın başarısız olduğunu bildirir.

	->	PresidentialPardonForm: Required grades: sign 25, exec 5
		Informs that <target> has been pardoned by Zaphod Beeblebrox.
		: "PresidentialPardonForm" sınıfını oluşturun ve imza yetki seviyesi 25, yürütme yetki seviyesini 5 olarak tanımlayın.
		: <target> öğesinin Zaphod Beeblebrox tarafından affedildiğini bildirir.
	
	Hepsi yapıcılarında yalnızca bir parametre alır: "the target of the form", formun hedefi.
		For example, "home" if you want to plant shrubbery at home.
		: Örneğin, evde çalı dikmek istiyorsanız "ev".

	"execute( Bureaucrat const & executor ) const" üye işlevini temel(base) forma ekleyin.
	Formun somut(concrete) sınıfların eylemini yürütmek için bir işlev uygulayın.
	Formun imzalanıp imzalanmadığını ve formu uygulamaya çalışan bürokratın notunun yeterince yüksek olup olmadığını kontrol etmelisiniz.
	Aksi takdirde, uygun bir istisna atın.

	Her somut sınıftaki veya temel sınıftaki gereksinimleri kontrol etmek isteyip istemediğiniz (daha sonra formu yürütmek için başka bir işlev çağırın) size kalmış. 

	Son olarak, "executeForm( Form const & form )" üye fonksiyonunu Bürokrat'a ekleyin. ???????? "(AForm const & form)" olmalı ???????
	Formu yürütmeye çalışmalıdır. Başarılı olursa şöyle yazdırın:
		: <bureaucrat> executed <form>
	Değilse, açık bir hata mesajı yazdırın.
		: ..............................

*/

/*
Url:
	https://ascii.co.uk/art/shrubbery

Yorum:
	Üç farklı form türünün bürokratlar tarafından yetki seviyelerine göre imzalanıp, yürütme işlemine tabi tutulması hakkında kısa bir çalışma yapılmıştır.
	Birden çok yapının en okunur ve temiz bir şekilde yazım örneğidir.

*/
int	main(){

	{
		std::cout <<RED "---------------- Stack Memory Allocation Example ----------------" END<< std::endl;
		/* Stack'te yer açarak oluşturduğumuz formları bu şekilde kullanıyoruz.
			Form için try-catch yapısı bürokratın kod bloğu içerisinde bulunduğu için, her forma özel olarak istisna döndürme işlemini yapmamıza gerek kalmıyor.
			*/
		try
		{
			Bureaucrat Michel("Michel", 33);
			std::cout << Michel << std::endl;

			PresidentialPardonForm P("Pardon");
			RobotomyRequestForm R("Request");
			ShrubberyCreationForm S("Creation");

			std::cout << P << std::endl;
			std::cout << R << std::endl;
			std::cout << S << std::endl;

			Michel.signForm(P);
			Michel.signForm(R);
			Michel.signForm(S);

			std::cout << P << std::endl;
			std::cout << R << std::endl;
			std::cout << S << std::endl;

			Michel.executeForm(P);
			Michel.executeForm(R);
			Michel.executeForm(S);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

	}

	{
		std::cout <<RED "---------------- Heap Memory Allocation Example ----------------" END<< std::endl;
		/* Heap'te yer açarak oluşturduğumuz formları bu şekilde kullanıyoruz. */
		try
		{
			Bureaucrat Alice("Alice", 5);
			std::cout << Alice << std::endl;

			AForm *P = new PresidentialPardonForm("Pardon");
			AForm *R = new RobotomyRequestForm("Request");
			AForm *S = new ShrubberyCreationForm("Creation");

			std::cout << *P << std::endl;
			std::cout << *R << std::endl;
			std::cout << *S << std::endl;

			Alice.signForm(*P);
			Alice.signForm(*R);
			Alice.signForm(*S);

			std::cout << *P << std::endl;
			std::cout << *R << std::endl;
			std::cout << *S << std::endl;

			Alice.executeForm(*P);
			Alice.executeForm(*R);
			Alice.executeForm(*S);

			delete P;
			delete R;
			delete S;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Improper Use ----------------" END<< std::endl;
		/* Birden fazla form türü olduğundan dolayı ve her forma ait bir istisna döndürüldüğünden dolayı bu şekilde bir kullanım uygun değildir.
			Bu şekilde kullanmak yerine, sadece bürokratlar için try-catch yapısının oluşturup, bürokratlardan methodları çağırıp kullanmak daha uygundur.
			Bu tarzda bir kullanım tercih edilirsede, her form için uygun hata mesajı vermek zorunda kalınır ve her nesne türü için özel olarak kod bloğu yazılmak zorunda kalınır.
			Bu tarz bir kullanımda istisna döndüren bir yapıda, try-catch kullanılmaz ve istisna döndürürse hata alınır.
			*/
		try
		{
			Bureaucrat John("John", 5);
			std::cout << John << std::endl;

			PresidentialPardonForm P("Pardon");
			RobotomyRequestForm R("Request");
			ShrubberyCreationForm S("Creation");

			std::cout << P << std::endl;
			std::cout << R << std::endl;
			std::cout << S << std::endl;

			try
			{
				P.beSigned(John);
				std::cout << BLUE << John.getName() << " signed "\
				<< P.getName() << END << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << PURPLE << John.getName() << " couldn't sign "\
				<< P.getName() << " because " << e.what() << '\n' << END;
			}

			try
			{
				R.beSigned(John);
				std::cout << BLUE << John.getName() << " signed "\
				<< R.getName() << END << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << PURPLE << John.getName() << " couldn't sign "\
				<< R.getName() << " because " << e.what() << '\n' << END;
			}

			try
			{
				S.beSigned(John);
				std::cout << BLUE << John.getName() << " signed "\
				<< S.getName() << END << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << PURPLE << John.getName() << " couldn't sign "\
				<< S.getName() << " because " << e.what() << '\n' << END;
			}

			std::cout << P << std::endl;
			std::cout << R << std::endl;
			std::cout << S << std::endl;

			try
			{
				P.execute(John);
				std::cout << BLUE << John.getName() << " executed " << P.getName() << END << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << PURPLE << John.getName() << " couldn't executed "\
				<< P.getName() << " because " << e.what() << '\n' << END;
			}

			try
			{
				R.execute(John);
				std::cout << BLUE << John.getName() << " executed " << R.getName() << END << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << PURPLE << John.getName() << " couldn't executed "\
				<< R.getName() << " because " << e.what() << '\n' << END;
			}

			try
			{
				S.execute(John);
				std::cout << BLUE << John.getName() << " executed " << S.getName() << END << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << PURPLE << John.getName() << " couldn't executed "\
				<< S.getName() << " because " << e.what() << '\n' << END;
			}
		}
		catch(const std::exception &e)
		{
			std::cerr << PURPLE << e.what() << END << std::endl;
		}
	}
	return (0);
}
