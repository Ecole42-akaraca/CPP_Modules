#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/*
	Subject Çeviri:
		Interface & recap - Arayüz(arabirim) & özet

	Arayüz C++98 ve C++20'de yoktur.
	Ancak pure abstract class(saf soyut sınıflar)'lara arayüzler(interfaces) denir.
	Bu nedenle bu alıştırmada arayüz çalışması yapılmaktadır.

	Aşağıdaki AMateria sınıfının tanımını tamamlayın ve gerekli üye işlevlerini uygulayın.
-------------------------------------------------------------------------------------------
	class	AMateria{

		protected:
			[...]
		public:
			AMateria( std::string const &type );
			[...]
			std::string const &getType( ) const; // Materyal tipini döndürür.

			virtual AMateria *clone( ) const = 0;
			virtual void use( ICharacter &target );
	};
-------------------------------------------------------------------------------------------

	Materia'nın somut sınıfları Ice ve Cure'u uygulayın.
	Türlerini(type) ayarlamak için küçük harfler kullanın: Ice için "ice", Cure için "cure"
	Üye methodu olan clone(), aynı tipte yeni bir tür döndürür. (örn: Ice Materia'yı klonlarsanız yeni bir Ice Materia elde edersiniz.(bellekte yeniden tahsis edilir))

	use(ICharacter &) fonksiyonu şu çıktıyı verecektir:
		- Ice: "* shoots an ice bolt at <name> *"
		- Cure: "* heals <name>'s wounds *"

		<name>, name olarak iletilen parametre karakterin adıdır.
		Brackets(parantezler)(<,>) yazdırılmamalıdır.

	??? Bir Materia'yı diğerine aktarırken, type değişkenini kopyalamak mantıklı değildir.(shallow copy X, deep copy ✓)

	Aşağıdaki arayüzü uygulayacak olan somut karakter sınıfını yazın:
-------------------------------------------------------------------------------------------
	class ICharacter{

		public:
			virtual	~ICharacter(){}
			virtual std::string const & getName() const = 0;
			virtual void equip( AMateria *m ) = 0;
			virtual void unequip( int idx ) = 0;
			virtual void use( int idx, ICharacter &target ) = 0;
	};
-------------------------------------------------------------------------------------------

	Karakter(Character) 4 yuvalık(slot) bir envantere sahiptir, bu da en fazla 4 Materia anlamına gelir.
	Envanter yapım(constructor) aşamasında boştur. Materialar buldukları ilk boş yuvaya yerleştirilir.
	Bu şu anlama gelmektedir:
		Envanter 0.yuvadan 3.yuvaya kadardır.
		Dolu bir envantere bir Materia eklemeye veya var olmayan bir Materia'yı kullanmaya/çıkarmaya çalışılırsa hiçbir şey yapılmasın.(Hata oluşumları istenilmemektedir.)
		unequip() fonksiyonu Materia'yı silmemelidir.

	??? Karakterinizin yere bıraktığı Materia'ları istediğiniz gibi kullanın.
		unequip() veya başka bir fonksiyonu çağırmadan önce adreslerini kaydedin.
		Bellek sızıntılarından kaçınmanız gerektiğini unutmayın.

	use(int, ICharacter &) fonksiyonu yuva[idx](slot[idx])'te Materia'yı kullanması ve hedefe parametreyi "AMateria::use" işlevine iletmesi gerekir.

	??? !!! Karakterinizin envanteri her türlü AMateria tipini(type) destekliyebilmelidir.

	Karakterinizin adını parametre olarak alan bir oluşturucu olmalıdır.
	Bir karakterin herhangi bir kopyası (copy constructor veya copy assignment operator) "deep copy" olmalıdır.
	Kopyalama sırasında, bir karakterin Materia'ları envantere yenileri yerleştirilmeden önce envanter temizlenmelidir.
	Elbette bir karakter yok edildiğinde(deleted) Materia'larda silinmelidir(destroyed).

	Aşağıdaki arayüzü uygulayacak bir somut sınıf MateriSource'yi yazın:
-------------------------------------------------------------------------------------------
	class IMateriaSource{

		public:
			virtual ~IMateriaSource(){}
			virtual void learnMateria( AMateria * ) = 0;
			virtual AMateria *createMateria( std::string const &type ) = 0;
	};
-------------------------------------------------------------------------------------------

	- learnMateria(AMateria*):
		Parametre olarak iletilen Materia'yı kopyalar ve daha sonra klonlanabilmesi için bellekte saklar.
		Karakter gibi, MateriaSource'da en fazla 4 Materia bilebilir. Materia'ların benzersiz olmaları beklenmez(aynı Materia'lar stacklenebilir).

	- createMateria(std::string const &):
		Yeni bir Materia döndürür.
???		Parametre olarak iletilen Materia türü, daha önceden öğrenilen Materia türüne eşit ise bu bir kopyadır.
		Tür bilinmiyorsa 0 döndürür.

	Özetle, MateriaSource'unuz gerektiğinde bunları oluşturmak için Materia "şablonlarını(templates)" öğrenebilmelidir.
	Sadece türünü(type) tanımlayan bir dizi(string) kullanarak yeni bir Materia oluşturabileceksiniz.

	Şu kodu çalıştırın:
-------------------------------------------------------------------------------------------
	int	main(){

		IMateriaSource *src = new MateriaSource();
		src->learnMateria( new Ice() );
		src->learnMateria( new Cure() );

		ICharacter *me = new Character( "me" );
		
		AMateria *tmp;
		tmp = src->createMateria( "ice" );
		me->equip( tmp );
		tmp = src->createMateria( "cure" );
		me->equip( tmp );

		ICharacter *bob = new Character( "bob" );

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

		return (0);
	}
-------------------------------------------------------------------------------------------

	Çıktı şu şekilde olmalıdır:
-------------------------------------------------------------------------------------------
	$> clang++ -W -Wall -Werror *.cpp
	$> ./a.out | cat -e
	* shoots an ice bolt at bob *$ * heals bob's wounds *$
-------------------------------------------------------------------------------------------

	Materia ->	Bir video oyunu olan Final Fantasy VII'nin Materia adlı bir öğesine atıfta bulunuyor.
				Bu öğeler oyuncuların karakterlerine çeşitli yetenekler ve güçler kazandırır.


	Interface anlamı:
		Diğer class'lara rehberlik görevi üstlenen bir yapıdır.
		Yaptığı iş sadece diğer classlara yön göstermektir.
 		Bir interface'in kod bloğu içeren methodları olamaz, çünkü bir interface'de bulunan tüm methodlar saf sanal fonksiyonlardır.
		Interface yapılar sadece tanımlamalardan ibarettir, içerisinde hiçbir yapıcı metod ekleyemeyiz.

	Abstract Class anlamı:
		Bir abstract class, kod bloklarını içeren methodlara da sahip olabilir.
		Ancak, bu methodlar normal fonksiyonlar olarak tanımlanmalıdır, yani pure virtual function değildirler.
		Bir class en az bir pure virtual yapı içeriyorsa abstract class olmaktadır.
		Bu methodların kod blokları bulunmaz. Sadece rehberlik görevini yerine getirir.
*/

// void leak()
// {

// 		IMateriaSource *src = new MateriaSource();
// 		src->learnMateria( new Ice() );
// 		src->learnMateria( new Cure() );

// 		ICharacter *me = new Character( "me" );
		
// 		AMateria *tmp;

// 		tmp = src->createMateria( "ice" );
// 		me->equip( tmp );
// 		tmp = src->createMateria( "cure" );
// 		me->equip( tmp );

// 		ICharacter *bob = new Character( "bob" );

// 		me->use(0, *bob);
// 		me->use(1, *bob);

// 		delete bob;
// 		delete me;
// 		delete src;
// }


// void test(){

// 		// Character a;
		
// 		// a.abc = "ahmet";
// 		// Character b = a;

// 		// b.abc = "karaca";

// 		// printf("%s -- %s\n", a.abc.c_str(), b.abc.c_str());
// 		//------------------------------------------------------//
// 		// MateriaSource a;
		
// 		// a.abc = "ahmet";
// 		// MateriaSource b = a;

// 		// b.abc = "karaca";

// 		// printf("%s -- %s\n", a.abc.c_str(), b.abc.c_str());


// 		IMateriaSource *src = new MateriaSource();
// 		src->learnMateria( new Ice() );
// 		src->learnMateria( new Ice() );
// 		src->learnMateria( new Ice() );
// 		src->learnMateria( new Ice() );
// 		src->learnMateria( new Cure() );

// 		ICharacter *me = new Character( "me" );

// 		AMateria *tmp;

// 		tmp = src->createMateria( "ice" );
// 		delete tmp;
// 		tmp = src->createMateria( "ice" );
// 		me->equip(tmp);
// 		me->unequip(0);
// 		me->equip(tmp);
// 		me->equip(tmp);

// 		tmp = src->createMateria( "cure" );
// 		me->equip(tmp);

// 		me->unequip(0); // bu işlem materia'ların yere düşmesine neden oluyor ve freelenmiyor, 
// 			//eğerki bu işlemin ardından me->equip(tmp) kullanılırsa materialar karakter tarafından yerden alınır ve kullanılmaya başlar.
// 		// me->equip(tmp);

// 		ICharacter *Jack = new Character( "Jack" );

// 		me->use(0, *Jack);
// 		me->use(1, *Jack);
// 		me->use(2, *Jack);
// 		me->use(3, *Jack);
// 		me->use(4, *Jack);

// 		delete Jack;
// 		delete me;
// 		delete src;
// }

int	main(){

	{
		IMateriaSource *src = new MateriaSource(); // Materia'ları öğrenmek veya oluşturmak için gerekli.
		src->learnMateria( new Ice() ); // kullanılacak olan materia oluşturuluyor.
		src->learnMateria( new Cure() );

		ICharacter *me = new Character( "me" ); // saldıran karakter belirleniyor.
		
		AMateria *tmp;

		tmp = src->createMateria( "ice" ); // bilinmeyen bir materia türü girilme durumu burada gerçekleşiyor.
		me->equip( tmp ); // karakterin envanterine materia ekleniyor.
		tmp = src->createMateria( "cure" );
		me->equip( tmp );

		ICharacter *bob = new Character( "bob" ); // düşman belirleniyor.

		me->use(0, *bob); // bob'a envanterde bulunan materia ile saldırıda bulunuluyor.
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	// test();
	// leak();
	// system("leaks Interface");
	return (0);
}
