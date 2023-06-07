#include "Array.hpp"
#include "Array.tpp"
#include "Color.hpp"

/*
	---> C++ templates / şablonlar <---
	---> Array / Dizi <---
	Subject Çeviri:
	T tipi öğeler içeren ve aşağıdaki davranış ve işlevleri uygulayan bir sınıf şablonu Dizisi geliştirin:

		Parametresiz oluşturma: Boş bir dizi oluşturur.

		Parametre olarak işaretsiz(unsigned) bir int n ile oluşturma: Varsayılan olarak başlatılan n öğelik bir dizi oluşturur.
			İpucu: int * a = new int();'i derlemeye çalışın. ardından *a'yı görüntüleyin.
				>int *a = new int();
				>std::cout << *a << std::endl;
					> Çıktı: 0

				>int *a = new int(3);
				>std::cout << *a << std::end;
					> Çıktı: 3
		
		Kopyalama ve atama operatörü tarafından yapılanma. Her iki durumda da, kopyalamadan sonra orijinal dizinin veya onun kopyasının değiştirilmesi diğer diziyi etkilememelidir.

		Belleği ayırmak için new[] operatörünü KULLANMALISINIZ. Önleyici tahsis (önceden hafıza tahsisi) yasaktır. Programınız asla ayrılmamış belleğe erişmemelidir.

		Öğelere alt simge operatörü aracılığıyla erişilebilir: [ ].

		[ ] operatörüyle bir öğeye erişirken, dizini sınırların dışındaysa, bir std::exception atılır.

		Dizideki öğelerin sayısını döndüren bir üye işlevi: size(). Bu üye işlev hiçbir parametre almaz ve geçerli örneği değiştirmemelidir.

		Her zamanki gibi, her şeyin beklendiği gibi çalıştığından emin olun ve testlerinizi içeren bir main.cpp dosyasını teslim edin.

Not:
	.tpp dosyalarında define (#ifndef - #define) etmek zorunlu değildir lakin, header dosyalarında olduğu gibi birden fazla kez derlenmesini istemiyorsak eklemeliyiz.

Bu alıştırma, bir dizi gibi davranan bir sınıf şablonu yazmakla ilgilidir.
gerçek dizinin iç tahsisi bir new[] kullanımından gelmiyorsa, bu alıştırmaya not vermeyin.
Alıştırmayı derecelendirmeden önce, değerlendirilen öğrenciden sınıf şablonunun hem basit hem de karmaşık türlerdeki dizilerle çalıştığını kanıtlamasını isteyin.
Öğeler, operatör[] aracılığıyla okumak ve yazmak için erişilebilir olmalıdır (veya yalnızca örnek const ise okunabilir).
Aralık dışında olan bir öğeye erişim, atmalı ve std::exception.
*/
int main(){
	{
		std::cout << RED "---------------- Empty array (int) ----------------" END << std::endl;
		// Empty array
		Array<int> arr1;
		std::cout << "Size of arr1: " << arr1.getSize() << std::endl;
	}

	{
		std::cout << RED "---------------- Array with size (int) ----------------" END << std::endl;
		// Array with default size
		Array<int> arr2(5);
		std::cout << "Size of arr2: " << arr2.getSize() << std::endl;
	}

	{
		std::cout << RED "---------------- Copy constructor (int) ----------------" END << std::endl;
		Array<int> arr2(5);
		Array<int> arr3(arr2);
		std::cout << "Size of arr3: " << arr3.getSize() << std::endl;
	}

	{
		std::cout << RED "---------------- Copy assignment operator (int) ----------------" END << std::endl;
		Array<int> arr1(5);
		Array<int> arr2;
		std::cout << "Size of arr1 before assignment: " << arr1.getSize() << std::endl;
		std::cout << "Size of arr2 before assignment: " << arr2.getSize() << std::endl;

		arr1[0] = 0;
		arr1[1] = 1;
		arr1[2] = 2;

		std::cout << "arr1 elements before assignment: " << arr1 << std::endl;
		std::cout << "arr2 elements before assignment: " << arr2 << std::endl;

		arr2 = arr1;

		std::cout << "Size of arr1 after assignment: " << arr1.getSize() << std::endl;
		std::cout << "arr1 elements after assignment: " << arr1 << std::endl;
		std::cout << "Size of arr2 after assignment: " << arr2.getSize() << std::endl;
		std::cout << "arr2 elements after assignment: " << arr2 << std::endl;

		arr1[0] = -1;
		arr1[1] = -1;
		arr1[2] = -1;
		arr1[3] = -1;

		arr2[4] = 9;

		std::cout << "arr1 elements after assignment & change: " << arr1 << std::endl;
		std::cout << "arr2 elements after assignment & change: " << arr2 << std::endl;
	}

	{
		std::cout << RED "---------------- Accessing elements with [] and printing (int) ----------------" END << std::endl;
		Array<int> arr4(5);
		arr4[0] = 1;
		arr4[1] = 2;
		arr4[2] = 3;
		std::cout << "arr4 elements: ";
		std::cout << arr4 << std::endl;
	}

	{
		std::cout << RED "---------------- Out of bounds exception (int) ----------------" END << std::endl;
		Array<int> arr5(3);
		arr5[0] = 0;
		arr5[1] = 1;
		arr5[2] = 2;
		try
		{
			std::cout << "arr5 elements: ";
			std::cout << arr5[0] << " - ";
			std::cout << arr5[1] << " - ";
			std::cout << arr5[2] << " - ";
			std::cout << arr5[3] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << RED "---------------- Array with size (char) ----------------" END << std::endl;
		Array<char> arr6(4);
		std::cout << "Size of arr6: " << arr6.getSize() << std::endl;
	}

	{
		std::cout << RED "---------------- Printing elements (char) ----------------" END << std::endl;
		Array<char> arr7(4);
		arr7[0] = 'a';
		arr7[1] = 'b';
		//arr7[2] = 'c';
		arr7[3] = 'd';
		std::cout << "arr7 elements: ";
		std::cout << arr7 << std::endl;
	}

	{
		std::cout << RED "---------------- Array with size (char*) ----------------" END << std::endl;
		Array<const char*> arr8(5);
		std::cout << "Size of arr8: " << arr8.getSize() << std::endl; 
	}

	{
		std::cout << RED "---------------- Array with size (std::string) ----------------" END << std::endl;
		Array<std::string> arr9(4);
		std::cout << "Size of arr9: " << arr9.getSize() << std::endl;
	}

	{
		std::cout << RED "---------------- Printing elements (std::string) ----------------" END << std::endl;
		Array<std::string> arr10(4);
		arr10[0] = "Jack";
		arr10[1] = "Micheal";
		arr10[2] = "Emanuel";
		std::cout << "arr10 elements: ";
		std::cout << arr10 << std::endl;
	}

	{
		std::cout << RED "---------------- Different way to Printing elements (std::string) ----------------" END << std::endl;
		//Array<std::string> tab = {"Alice", "Jack"}; tarzında init işlemini gerçekleştiremiyoruz. // Bir başlatıcı listesiyle başlatılamaz hatası döndürüyor: "cannot be initialized with an initializer list"
		std::string elements[] = {"Alice", "Jack"};
		unsigned int size = sizeof(elements) / sizeof(elements[0]);
		Array<std::string> tab(elements, size);
		std::cout << "tab size: " << tab.getSize() << std::endl;
		std::cout << tab << std::endl;
		//hala doğrudan liste kullanarak bir Array nesnesini başlatmak mümkün değildir.
	}

	{
		std::cout << RED "---------------- Wrong use ----------------" END << std::endl;
		Array<int*> tab[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
		std::cout << "tab size: " << tab->getSize() << std::endl;
		std::cout << "tab elements: " << tab << std::endl;
	}

	return 0;
}
