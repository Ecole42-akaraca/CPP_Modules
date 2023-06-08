#include "Easyfind.hpp"
/*
	---> C++ Templated containers, iterators, algorithms / Şablonlu konteynerlar, yineliyiciler, algoritmalar <---
	---> Easy find / Kolay bulmak <---
	Subject Çeviri:
		İlk kolay egzersiz, doğru adımlarla başlamak için harika bir fırsattır.
		
		easyfind adlı bir şablon fonksiyon yazın ve bir T türü kabul edin.
		İki parametre alır.
		İlk parametresi T türünde ve ikinci parametresi tamsayıdır.
		
		T'nin bir tamsayı konteyneri olduğu varsayımıyla, bu işlev, ilk parametredeki ikinci parametrenin ilk oluşumunu bulmalıdır.
		
		Eğer bir oluşum bulunamazsa, istisna fırlatabilirsiniz veya kendi belirleyeceğiniz bir hata değeri döndürebilirsiniz.
		İlham almak için, standart konteynerlerin nasıl davrandığını inceleyin.
		
		Tabii ki, her şeyin beklediğiniz gibi çalıştığından emin olmak için kendi testlerinizi uygulayın ve teslim edin.

		!!! Bağlantılı konteynerleri ele almanız gerekmez.

Not:
	Templated containers nedir?
		Bu, bir şablon (template) sınıfının, içinde birden fazla veri türü barındırabilen bir veri yapısı veya koleksiyon oluşturması anlamına gelir.
		Örneğin, bir vektör, bir dizi veya bir liste, C++'da şablonlu konteynerlar örnekleri olabilir.
		Bu konteynırlar, kodun tekrar kullanılabilirliğini artırarak ve bir veri yapısının birden fazla veri türü ile kullanılabilmesini sağlayarak programlama dilinin esnekliğini artırır.

	Iterators nedir?
		Bir veri yapısındaki elemanlara teker teker erişebilmek için kullanılan nesnelerdir.
		Bir veri yapısı üzerinde işlem yapabilmek için öncelikle iterator kullanarak veri yapısı içinde hareket edilir.
		Örneğin, bir STL (Standard Template Library) konteynırı içindeki elemanlara erişmek için iterator kullanılır.
		Iteratorler, veri yapısının tipine göre değişiklik gösterir ve genellikle veri yapısının içinde bulunan elemanların sayısı, mevcut elemana erişme ve bir sonraki elemana geçme gibi fonksiyonları içerirler.

	Algorithms nedir?
		Algoritmalar, belirli bir amaç doğrultusunda sıralanmış mantıksal adımlar kümesidir.
		Bilgisayar biliminde, belirli bir işlevi yerine getirmek için kodlanmış bir dizi adımdır.
		C++ Standard Library, STL (Standard Template Library) adı altında bir dizi hazır algoritma sunar.
		Bu algoritmalar, sıklıkla sıralama, arama, değiştirme ve özetleme işlemlerini gerçekleştirmek için kullanılır.
		Algoritmalar, genellikle STL konteynırları üzerindeki verileri işlemek için kullanılan iteratorlarla birlikte kullanılır.

Eva Rules:
As usual, there has to be the main function that contains enough tests to prove the program work as expected.
If there isn't, do not grade tihs exercise.
If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

	>	Her zaman olduğu gibi, programın beklendiği gibi çalıştığını kanıtlamak için yeterli testi içeren ana işlev olmalıdır.
	Eğer yoksa egzersizi derecelendirmeyin.
	Arayüz olmayan herhangi bir sınıf, geleneksel kanonik sınıf formunda değilse, bu alıştırmaya not vermeyin.

Template function / Şablon işlevi:
There is a templated function easyFind(T, int) that does what the subject requires.
It has to use stl algorithms.
If it does not (like manual search using iterators for example), count it as wrong.

	>	Konunun gerektirdiğini yapan şablonlu bir easyFind(T, int) işlevi vardır.
	STL algoritmalarını kullanmak zorundadır.
	Olmazsa (örneğin yineleyicileri kullanan manuel arama gibi), yanlış olarak sayın.

*/
int main(){

	std::vector<int> intVec;

	intVec.push_back(10);
	intVec.push_back(20);
	intVec.push_back(30);

	easyfind(intVec, 30);
	easyfind(intVec, 50);
	printer(intVec);

	std::vector<double> doubleVec;

	doubleVec.push_back(5);
	doubleVec.push_back(7);
	doubleVec.push_back(8.42);

	easyfind(doubleVec, 7);
	easyfind(doubleVec, 8);
	printer(doubleVec);

//----------------------------------------------vector<std::string> için örnek------------------------------------------------------------------//
	// std::vector<std::string> stringVec;
	// stringVec.push_back("Jack");
	// stringVec.push_back("Carl");
	// stringVec.push_back("Alice");
	// stringVec.push_back("Emanuel");
	// printer(stringVec);
	return (0);
}
