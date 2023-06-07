#include "Serializer.hpp"

/*
	---> C++ casts <---
	---> Serialization / Serileştirme <---
	Subject Çeviri:
	
	Aşağıdaki yöntemlerle bir statik sınıf(static class) Serileştirici uygulayın:
		-> uintptr_t serialize(Data *ptr);
			: Bir işaretçi(pointer) alır ve onu "unitptr_t" işaretsiz tamsayı(integer) türüne dönüştürür.

		-> Data *deserialize(uintptr_t raw);
			: İşaretsiz(unsigned) bir tamsayı(integer) parametresi alır ve onu veri(data) işaretçisine(pointer) dönüştürür.

	Sınıfınızın beklendiği gibi çalıştığını test etmek için program yazın.

	Boş olmayan (veri üyeleri olduğu anlamına gelir) bir veri(data) yapısı(structure) oluşturmalısınız.

	Data nesnesinin adresine "serialize()" işlevini kullanın ve dönüş değerini "deserialize()" işlevine iletin.
	Ardından, "deserialize()" dönüş değerinin orjinal işaretçiye orjinal işaretçiye eşit olduğundan emin olun.

	Veri yapınızın(data structure) dosyalarını teslim etmeyi unutmayın.

Not:
	Serileştirme neden kullanılır?
		Serileştirme, bir nesnenin durumunu kaydetmemizi ve nesneyi yeni bir konumda yeniden oluşturmamızı sağlar.
		Serileştirme, hem nesnenin depolanmasını hem de veri alışverişini kapsar.

	uintptr_t:
		C ve C++ dillerinde kullanılan, unsigned integer tipinde bir tamsayı veri tipidir.
		Bu tip, işaretçilerin tam sayılarla tutulması gereken durumlarda kullanılır.
		İşaretçiler bellekteki bir adresi gösteren değerlerdir ve bu değerler tam sayılarla ifade edilebilir.

		Genellikle işaretçilerin bellek adreslerini veya işaretçilerin gösterdiği verilerin adreslerini tam sayılara dönüştürmek için kullanılır.
		Bu dönüştürme, özellikle verileri disk veya ağ gibi kaynaklarda depolamak veya aktarmak için kullanılan serileştirme işlemlerinde yararlıdır.

		Peki neden bunu kullanmalıyız?
			İşaretçilerin boyutu ve bellek adresleri, platformdan platforma farklılık gösterdiğinden, bir işaretçiyi doğrudan bir tam sayıya dönüştürmek farklı platformlarda çalışan programlar için uyumsuzluklar yaratabilir.
			Bu durum, aşağıdaki sorunlara neden olabilir:

				1. Bellek adresleri farklı boyutlarda olabilir:
					İşaretçiler, bellekte bir nesnenin veya verinin konumunu gösterir.
					Bu nedenle, bir işaretçinin bellek adresi, bellekteki konumun boyutuna bağlıdır.
					Farklı platformlarda, bellek adresleri farklı boyutlarda olabilir.
					Örneğin, bir 32-bit işletim sistemi, bellek adreslerini 32-bit olarak tutarken, 64-bit bir işletim sistemi, bellek adreslerini 64-bit olarak tutabilir.
					Bu nedenle, aynı bellek adresi, farklı platformlarda farklı bir tam sayı değerine dönüştürülebilir.

				2. İşaretçilerin boyutu farklı olabilir:
					İşaretçilerin boyutu, bellek mimarisine bağlı olarak değişir.
					Örneğin, bir 32-bit işletim sisteminde bir işaretçi 32-bit uzunluğunda iken, bir 64-bit işletim sisteminde bir işaretçi 64-bit uzunluğunda olabilir.
					Bu nedenle, işaretçiler ile tam sayılar arasında doğrudan bir dönüşüm yapmak, farklı platformlarda çalışan programlar için uyumsuzluklar yaratabilir.

			Bu uyumsuzluklar, programın yanlış bellek adreslerini kullanmasına ve hatta uygulamanın çökmesine neden olabilir.
			Bu nedenle, işaretçiler ile tam sayılar arasında doğrudan bir dönüşüm yapılmaması ve uintptr_t tipi gibi platformdan bağımsız bir tipin kullanılması önerilir.
			Bu sayede, bellek adreslerini güvenli bir şekilde taşıyabilir ve farklı platformlarda çalışan programlar arasında uyumluluk sağlayabilirsiniz.

		uintptr_t'den başka kullanılabilecek bir yöntem var mıdır?
			Evet, uintptr_t tipi, işaretçilerin tam sayılara dönüştürülebilmesi için standart bir yöntemdir ve çoğu platformda kullanılabilir.
			Ancak bazı durumlarda, uintptr_t kullanmak mümkün olmayabilir veya uygun olmayabilir.
			
			Alternatif olarak, void* tipi, işaretçilerin gösterdiği bellek adreslerini taşıyan bir tip olarak kullanılabilir.
			void* tipi, işaretçiler ile tam sayılar arasında doğrudan bir dönüşüm yapılmasına izin vermez, ancak işaretçilerin bellek adreslerini taşıyabilir.
			Bu nedenle, void* tipi, işaretçilerin tutulduğu bellek adreslerini taşımak için kullanılabilir.

			Bunun yanı sıra, bazı platformlar, işaretçilerin tam sayılara dönüştürülmesine olanak tanıyan özel tipler veya fonksiyonlar sağlayabilir.
			Örneğin, Windows platformu, DWORD_PTR tipini kullanarak işaretçilerin tam sayılara dönüştürülmesine olanak tanır.
			Ancak bu tiplerin kullanımı platforma özeldir ve taşınabilirliği azaltabilir.

		uintptr_t için bir örnek:
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			#include <iostream>
			#include <cstdint>

			int main() {
				// Bir int tipi işaretçi oluşturur
				int *ptr = new int(42);

				// İşaretçinin bellek adresini uintptr_t tipine dönüştürür
				uintptr_t address = reinterpret_cast<uintptr_t>(ptr);

				// Dönüştürülen adresi ekrana yazdırır
				std::cout << "Pointer address: " << address << std::endl;

				// uintptr_t tipinde bir adresi tekrar işaretçiye dönüştürür
				int *newPtr = reinterpret_cast<int *>(address);

				// Yeni işaretçinin gösterdiği veriyi ekrana yazdırır
				std::cout << "New pointer value: " << *newPtr << std::endl;

				// İşaretçiyi siler
				delete ptr;

				return 0;
			}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			Çıktısı şu şekildedir:
				Pointer address: 94040094944944
				New pointer value: 42

		reinterpret_cast <...>(...) nedir? ( reinterpretation / yeniden yorumlama )
			reinterpret_cast C++ dilinde yer alan bir tip dönüştürme operatörüdür.
			Bu operatör, bir türü başka bir türe dönüştürmek için kullanılır.

			reinterpret_cast operatörü, diğer dönüştürme operatörlerine göre daha düşük seviyeli bir dönüştürme yapar.
			Bu nedenle, tip dönüşümleri güvenli bir şekilde yapılmazsa, program hatalarına veya tanımsız davranışlara neden olabilir.

			Bu operatör, özellikle işaretçilerin bir türden diğerine dönüştürülmesinde kullanılır.
			Bu işlem, özellikle sistem seviyesindeki işlemlerde ve bellek yönetimiyle ilgili işlemlerde yararlıdır.

			Örneğin, aşağıdaki kodda, bir double tipi bir değişkenin bellek adresi uintptr_t türüne dönüştürülmektedir:
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				double d = 3.14;
				uintptr_t address = reinterpret_cast<uintptr_t>(&d);
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			Bu örnekte &d ifadesi, d değişkeninin bellek adresini döndürür ve reinterpret_cast operatörü ile bu adres uintptr_t türüne dönüştürülür.

			reinterpret_cast, C++ dilindeki diğer dönüştürme operatörlerinden (static_cast, dynamic_cast, const_cast) farklı olarak, herhangi bir türü başka bir türe dönüştürebilir.
			Ancak, dönüşüm yapılan türler arasında mantıksal bir bağlantı olması gerektiği unutulmamalıdır.

				static_cast: Bu operatör, uygun şekilde dönüştürülebilen türler arasında dönüştürme yapar.
								Bu dönüştürme işlemi, türler arasında uygun bir ilişki olduğunu varsayar.
								Örneğin, bir alt türün üst türüne dönüştürülmesi, tamsayıların kaydırılması, vs. gibi durumlarda kullanılır.

				dynamic_cast: Bu operatör, türetilmiş sınıfların temel sınıflarına dönüştürme işlemi yapar.
								Bu operatör, türetilmiş bir nesnenin temel sınıfının işaretçisini oluşturmak için kullanılır.

				const_cast: Bu operatör, sabitlik niteliğinin kaldırılması için kullanılır.
								Bir değişkenin sabitliği kaldırılarak, bu değişken üzerinde değişiklik yapılabilir.
				
			reinterpret_cast operatörü ise, bir türü başka bir türe dönüştürmek için kullanılır.
			Ancak, dönüştürülen türler arasında mantıksal bir bağlantı olması gerekir.
			Bu operatör, türler arasında uygun bir ilişki olmadığında bile kullanılabilir.

			Örneğin, bir int türünün işaretçi tipine (void*) veya başka bir türe dönüştürülmesi gibi durumlarda kullanılabilir.
			Ancak, bu tür dönüşümleri, programın uyumsuz davranışlara yol açabileceği için dikkatli bir şekilde yapılmalıdır.
			
			C++ standardı içinde başka yöntemler de yer almaktadır.
			Bir yöntem, bir işaretçiyi unsigned long veya unsigned int türüne dönüştürmektir.
			Bu yöntemler, birçok platformda da yaygın olarak kullanılır.
			Örneğin, bir işaretçiyi unsigned long türüne dönüştürmektir:
				unsigned long ptrVal = (unsigned long)ptr;
			Bununla birlikte, uintptr_t kullanımı daha önerilir, çünkü bu tip, platformdan bağımsız bir şekilde işaretçileri unsigned integer türüne dönüştürmek için tasarlanmıştır.
			Bu nedenle, uintptr_t, birçok farklı platformda aynı şekilde çalışacaktır.

			reinterpret_cast farklı işletim sistemlerinde nasıl senkronize bir şekilde çalışıyor?
				reinterpret_cast, C++ programlama dilinde kullanılan bir dönüşüm operatörüdür ve işletim sistemi bağımsız bir şekilde çalışır.
				İşletim sistemlerinin reinterpret_cast üzerinde doğrudan bir etkisi yoktur, çünkü reinterpret_cast, C++ derleyicinin bir parçasıdır ve derleme aşamasında gerçekleşir.
				Bu nedenle, reinterpret_cast'in çalışma şekli, C++ derleyicisine ve derleme sürecine bağlıdır.
				Bununla birlikte, reinterpret_cast'in sonuçları, farklı işletim sistemlerinde bellek modeline ve veri hizalamasına bağlı olarak değişebilir. İşletim sistemi, bellek düzenlemesini ve hizalamayı kontrol ettiği için, reinterpret_cast'in sonuçları sistemden sisteme farklılık gösterebilir. Özellikle farklı işletim sistemlerinde farklı veri hizalama kuralları ve bellek düzenlemeleri olabilir.
				Bu nedenle, reinterpret_cast'in senkronize bir şekilde çalışması yerine, işletim sistemi üzerinde çalışan C++ derleyicisinin ve derleme sürecinin uyumlu bir şekilde çalışması önemlidir.
				C++ standartları, bu tür farklılıkları yönetmek için çeşitli taşınabilirlik garantileri sağlar ve derleyiciler, işletim sistemine bağlı farklılıkları ele almak için uygun düzeltmeleri yapar.
				Sonuç olarak, reinterpret_cast, işletim sisteminden ziyade C++ derleyicisi ve standartlarına bağlıdır ve uyumlu bir şekilde çalışabilmesi için uygun derleme süreci ve taşınabilirlik garantileri gerektirir.
				
			2 farklı sistemde reinterpret_cast ile bilgiyi aktarabilir miyiz?
				reinterpret_cast, C++ programlama dilinde kullanılan bir dönüşüm operatörüdür ve farklı sistemler arasında bilgi aktarmak için uygun bir mekanizma değildir.
				reinterpret_cast, C++ derleyicisi tarafından derleme sürecinde kullanılan bir dönüşüm operatörüdür ve derleme zamanında tip güvenliğini sağlamak için kullanılır.

		static_cast ile reinterpret_cast farkı nedir?
			reinterpret_cast: Bu dönüşüm operatörü, bir türü başka bir türe dönüştürmek için kullanılır.
								Uyumlu olmayan türler arasında dönüşümleri destekler ve tip güvenliği sağlamaz.
								Bu, dönüşümün anlamlı olup olmadığını kontrol etmez ve genellikle bellek düzenlemesi veya hizalama gibi konulara dikkat etmez.
								Bu nedenle, reinterpret_cast kullanırken dikkatli olunmalı ve uyumsuz dönüşümlerden kaçınılmalıdır.

			static_cast: Bu dönüşüm operatörü, uyumlu türler arasında dönüşümleri gerçekleştirmek için kullanılır.
						Tip güvenliğini sağlar, yani dönüşümün mantıklı olduğunu kontrol eder.
						Örneğin, bir alt sınıfın bir üst sınıfa veya bir veri türünün diğer bir veri türüne dönüştürülmesi güvenli kabul edilir.
						Ayrıca, void işaretçi veya belirli işaretçi türleri arasında dönüşümleri de destekler.
						Özetle, reinterpret_cast genellikle uyumlu olmayan türler arasında dönüşümler yaparken kullanılır ve tip güvenliği sağlamaz.
						static_cast ise uyumlu türler arasında dönüşümleri gerçekleştirir ve tip güvenliği sağlar.
						İhtiyaçlarınıza göre hangi dönüşüm operatörünü kullanmanız gerektiğine karar verebilirsiniz.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	char f = 'A';
	int i = reinterpret_cast<int>(f);
			-> Bu tarz bir dönüşüm türü uygun değildir.

	char c = 'A';
	int i = static_cast<int>(c);
			-> Daha pratik ve kolaylık için static_cast kullanılır.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

*/
int	main()
{
	Data *data = new Data();
	data->x = 42;
	data->y = 42.12f;

	//unsigned long ptrVal = (unsigned long)data; // Bu kullanım yerine reinterpret_cast kullanmak daha efektiftir. Kod bloğu genişlediğinde tip dönüşümlerinin kontrolü daha kolay yapılır.  (örn ctrl + F ile reinterpret_cast'i aratmak)
	unsigned long ptrVal = reinterpret_cast<unsigned long>(data);
	std::cout << "Different Use: " << ptrVal << std::endl;

	//Data *pointer = (Data* )ptrVal; // Bu kullanım yerine reinterpret_cast kullanmak daha efektiftir. Kod bloğu genişlediğinde tip dönüşümlerinin kontrolü daha kolay yapılır. (örn ctrl + F ile reinterpret_cast'i aratmak)
	Data *pointer = reinterpret_cast<Data*>(ptrVal);
	std::cout << "Different Use: " << pointer->x << ", " << pointer->y << std::endl;
	//reinterpret_cast<Data*>(pointer)->x

	if (data == pointer)
		std::cout << ".." << std::endl;
	else
		std::cout << "--" << std::endl;

	// Serialize
	uintptr_t raw = Serializer::serialize( data );
	std::cout << "Serialized Value: " << raw << std::endl;

	// Deserialize
	Data *ptr = Serializer::deserialize( raw );
	std::cout << "Deserialize Value: {" << ptr->x << ", " << ptr->y << "}" << std::endl;

	// Verify that deserialized pointer is equal to original pointer
	if ( ptr == data )
		std::cout << "Deserialized pointer is equal to original pointer." << std::endl;
	else
		std::cout << "Deserialized pointer is NOT equal to original pointer." << std::endl;
	
	delete data;

	std::string b = "ahmet";
	unsigned long a = reinterpret_cast<unsigned long>(&b);
	std::cout << a;
	char *c = reinterpret_cast<char*>(a);
	std::cout << "\n" << c;

	char *d = reinterpret_cast<char*>(&b);
	std::cout << "\n" << d;

	return (0);
}
