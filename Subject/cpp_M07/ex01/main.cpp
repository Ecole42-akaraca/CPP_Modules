#include "Iter.hpp"

/*
	---> C++ templates / şablonlar <---
	---> Iter / Iteration / İterasyon / Yineleyici / Döngüyle Gezme<---
	Subject Çeviri:
	
	3 parametre alan ve hiçbir şey döndürmeyen bir işlev şablonu yineleyicisi uygulayın.

		- İlk parametre bir dizinin adresidir.
		- İkincisi, dizinin uzunluğudur.
		- Üçüncüsü, dizinin her öğesinde çağrılacak bir işlevdir.
	
	Testlerinizi içeren bir main.cpp dosyası oluşturun.
	Yürütülebilir bir test oluşturmak için yeterli kodu sağlayın.

	(Yineleme işlevi) / (iter function) şablonunuz herhangi bir dizi türüyle çalışmalıdır.
	Üçüncü parametre, somutlaştırılmış bir işlev şablonu olabilir.

Not:

	Iter nedir?
		Templates iter, bir dizinin her bir elemanı üzerinde bir işlem yapmak için kullanılabilecek bir C++ işlev şablonudur.
		Bu şablon, herhangi bir dizi türüyle çalışabilir ve üç parametre alır:
			Bir dizi adresi,
			Dizinin uzunluğu,x
			Her bir öğeyi işlemek için çağrılacak bir işlev.
		iter şablonu, bir dizinin her bir elemanı için verilen işlevi çağırmak için kullanılabilir.
		Bu sayede, dizideki tüm elemanları tek tek işlemek için tekrarlayıcı kod yazmaktan kaçınılabilir.
	
	Iteratorlar, bir koleksiyonun elemanlarını sırayla gezmek veya erişmek için kullanılan nesnelerdir.
	C++ dilinde, standart kütüphanede begin() ve end() gibi işlevler, bir koleksiyonun başlangıç ve sonunu temsil eden iteratorları döndürür.

	Elma, armut ve muz içeren bir dizi oluşturalım ve bu diziyi iter şablonu kullanarak yazdıralım:
-----------------------------------------------------------------------------------------------------------------------
		#include <iostream>
		#include <algorithm>

		template<typename T>
		void printElement(T element)
		{
			std::cout << element << std::endl;
		}

		template<typename T>
		void iter(T *arr, int length, void (*func)(T))
		{
			for(int i = 0; i < length; i++)
			{
				func(arr[i]);
			}
		}

		int main()
		{
			std::string fruitArray[] = {"elma", "armut", "muz"};
			int length = sizeof(fruitArray) / sizeof(fruitArray[0]); // sizeof(std::string)'in uzunluğu 32 bayt döndürür. Bu yüzden bu işlem 96 / 32'den 3 gelir.
			iter(fruitArray, length, printElement<std::string>);
			
			return 0;
		}
-----------------------------------------------------------------------------------------------------------------------

	Bu yapıda girilen 2. bilgi yani uzunluk bilgisi kullanıcıya bırakılmıştır.
	iter'e gönderilen yapıda arrayin uzunluğu ölçülemiyor.
	Bundan dolayı array'in uzunluğundan daha uzun bir değer girildiğince yazdırma işleminde hatalar meydana gelmektedir.
*/
int main(){

	// Awesome tab[5];
	// iter(tab, 5, print);

	int tab2[] = {0, 1, 2, 3, 4};
	iter(tab2, 5, print);
	std::cout << "--" << std::endl;

	int arr1[] = {1, 2, 3, 4, 5};
	double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char arr3[] = {'a', 'b', 'c', 'd', 'e'};
	std::string arr4[] = {"ahmet", "karaca", "42"};

	iter(arr1, 5, print<int>);    // Output: 1 2 3 4 5 
	std::cout << "--" << std::endl;
	iter(arr2, 5, print<double>); // Output: 1.1 2.2 3.3 4.4 5.5
	std::cout << "--" << std::endl;
	iter(arr3, 5, print<char>);   // Output: a b c d e
	std::cout << "--" << std::endl;
	iter(arr4, 3, print<std::string>); // Output: ahmet karaca 42
	std::cout << "--" << std::endl;
	return (0);
}
