#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
	Subject Çeviri:
		Artik bürokrotlara sahip olduğumuza göre, onlara yapacak bir şeyler verelim.
		Bir yığın form doldurmaktan daha iyi bir aktivite olabilir mi?

	Form class'ını oluşturun.

	Form sınıfı şunları içermektedir:
		-> "A constant name"
			: 'const name' oluşturun.
		-> "A boolean indicating whether it is signed (at construction, it’s not)"
			: Formun imzalanıp imzalanmadığını gösteren bir bool değişkeni (constructor'da false, yani imzalanmamış olarak tanımlanmalıdır.).
			: 'bool signed'
		-> "A constant grade required to sign it"
			: Formu imzalama yetkisinin belirlenmesi için gerekli yetki seviyesi.
			: 'const int signGrade'
		-> "And a constant grade required to execute it"
			: Formu yürütmek için geçerli yetki seviyesi.
			: 'const int executeGrade'

	Tüm öznitelikler private(özel) olacaktır, proctected değil. //Bu şekilde belirtmesinin nedeni, Form class'nın ilerleyen subjectlerde base class olacağından dolayıdır.

	Formun grade(seviye, erişim, izin) yapısı, Bürokratlar için geçerli olan kuralların aynısını takip eder.
	Bu nedenle bir formun notu sınırlar dışındaysa aşağıdaki istisnalar atılacaktır:
		: Form::GradeTooHighException and Form::GradeTooLowException.
	
	Daha önce olduğu gibi, tüm öznitelikler için alıcılar yazın ve tüm formun bilgilerini basan ekleme (<<) operatörnün aşırı yüklenmesi oluşturun.

	Parametre olarak Bürokrat alan Forma ayrıca bir "beSigned()" üye işlevi ekleyin.
	Bürokratın grade(not, seviye) yeterince yüksekse (gerekli olandan fazla veya eşit) form durumunu imzalı olarak değiştirir.

	Unutmayın; 1.derece 2.dereceden daha yüksektir. Not çok düşükse bir "Form::GradeTooLowException" atın.

	Son olarak, Bürokrat'a bir "signForm()" üye işlevi ekleyin. Form imzalandıysa şöyle bir çıktı verecektir.
		: <bureaucrat> signed <form>
	Aksi taktirde, şöyle bir şey yazdıracaktır.
		: <bureaucrat> could'nt sign <form> because <reason>
	Her şeyin beklendiği gibi çalıştığından emin olmak için bazı testler uygulayın ve teslim edin.
	
*/

/*
Url:

Yorum:
Bürokratların sahip olduğu yetki seviyesi ile, belirli yetki seviyelerine sahip formların imzanlanması ve yürütülmesi için bürokratların yeterlilikleri kontrol ediliyor.
Bu çalışmada sadece imzalama için kontrol işlemi bulunmaktadır, yürütme/işleme alma için kontrol bulunmamaktadır.

Belirli kriterlerde oluşturulan formların bürokratlar tarafından imzalanırken try-catch işlemine tabi tutulur.
Bu işlemde istisna döndürülebilir, nedeni bürokratın form için yeterli yetkinliğe sahip olmamasından dolayıdır.

*/
int	main(){

	{
		std::cout <<RED "---------------- Standard Output - No Exception Example ----------------" END<< std::endl;
		/* İstisna olmadan standart çıktı örneği */
		try
		{
			Bureaucrat Alice("Alice", 25);
			std::cout << Alice << std::endl;

			Form Ex05("Ex05", 100, 75);
			std::cout << Ex05 << std::endl;

			Alice.signForm(Ex05);
			std::cout << Ex05 << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Form Too High Sign Grade Example ----------------" END<< std::endl;
		/* Derecesi çok yüksek olan bir form yapıcıyı/constructor'ı çağırırken istisna atın */
		try
		{
			Form Stick("Stick", 0, 75);
			std::cout << Stick << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Form Too Low Sign Grade Example ----------------" END<< std::endl;
		/* Derecesi çok düşük olan bir form yapıcıyı/constructor'ı çağırırken istisna atın */
		try
		{
			Form Wood("Wood", 999, 75);
			std::cout << Wood << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Form Too High Execute Grade Example ----------------" END<< std::endl;
		/* Derecesi çok yüksek olan bir form yapıcıyı/constructor'ı çağırırken istisna atın */
		try
		{
			Form Axe("Axe", 100, 0);
			std::cout << Axe << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Form Too Low Execute Grade Example ----------------" END<< std::endl;
		/* Derecesi çok düşük olan bir form yapıcıyı/constructor'ı çağırırken istisna atın */
		try
		{
			Form Fire("Fire", 100, 755);
			std::cout << Fire << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Bureaucrat Too Low Sign Grade Example ----------------" END<< std::endl;
		/* Bir bürokratın yetki seviyesinden yüksek bir formu imzalarken istisna atın */
		try
		{
			Bureaucrat Jack("Jack", 125);
			std::cout << Jack << std::endl;

			Form Box("Box", 100, 75);
			std::cout << Box << std::endl;

			Jack.signForm(Box);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Signed Form Example ----------------" END<< std::endl;
		/* İmzalanmış bir formun tekrardan imzlanma durumda istisna atın. */
		try
		{
			Bureaucrat Michel("Michel", 25);
			std::cout << Michel << std::endl;

			Bureaucrat John("John", 33);
			std::cout << John << std::endl;

			Form Paper("Paper", 100, 75);
			std::cout << Paper << std::endl;

			Michel.signForm(Paper);
			John.signForm(Paper);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout <<RED "---------------- Calling Copy Example ----------------" END<< std::endl;
		/* Form Nesnelerinin Eşitlenmesi */
		try
		{
			Bureaucrat Emily("Emily", 50);
			std::cout << Emily << std::endl;

			Form Desk("Desk", 20, 20);
			std::cout << Desk << std::endl;

			Form Pencil("Pencil", 100, 75);
			std::cout << Pencil << std::endl;

			Form Duster("Duster", 150, 150);
			std::cout << Duster << std::endl;
			
			Desk = Pencil; //Yetki seviyelerinin eşitlenmesi gerçekleştirilemiyor.

			Emily.signForm(Desk);
			Emily.signForm(Pencil);

			Duster = Pencil; //Form durumları eşitleniyor.
			std::cout << Duster << std::endl;

			Emily.signForm(Duster);
			std::cout << Duster << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}
