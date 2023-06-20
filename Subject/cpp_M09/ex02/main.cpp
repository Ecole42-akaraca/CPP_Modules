#include "PmergeMe.hpp"

/*
	---> C++ STL / Standard Template Library <---
	--->  PmergeMe / Program merge me <---
	Subject Çeviri:
		Bu kısıtlamalara sahip bir program oluşturmalısınız:
			-> Programın adı PmergeMe'dir.
			-> Programınız pozitif bir tamsayı dizisini bağımsız değişken olarak kullanabilmelidir.
			-> Programınız, pozitif tamsayı dizisini sıralamak için "birleştirme-ekleme(merge-insert)" sıralama algoritması kullanmalıdır.
			-> Programın yürütülmesi sırasında bir hata oluşursa, standart çıktıda bir hata mesajı görüntülenmelidir.

		!!! Bu alıştırmayı doğrulamak için kodunuzda en az iki farklı kap(container) kullanmalısınız.
		!!! Programınız en az 3000 farklı tamsayı işleyebilmelidir.

		??? Algoritmanızı her kapsayıcı(container) için uygulamanız ve böylece genel bir işlev kullanmaktan kaçınmanız şiddetle tavsiye edilir.
		(Yani, her bir konteynerin özelliklerini dikkate alarak, özel bir algoritma tasarlamalı ve her bir konteyner için bu özel algoritmayı kullanmalısınız.)

		Burada, standart çıktıda satır satır görüntülemeniz gereken bilgilerle ilgili bazı ek yönergeler verilmiştir:
			-> İlk satırda açık bir metin ve ardından sıralanmamış pozitif tamsayı dizisini görüntülemeniz gerekir.
			-> İkinci satırda, açık bir metni ve ardından sıralanmış pozitif tamsayı dizisini görüntülemeniz gerekir.
			-> Üçüncü satırda, pozitif tamsayı dizisini sıralamak için kullanılan ilk kabı(container) belirterek, algoritmanız tarafından kullanılan zamanı gösteren açık bir metin göstermelisiniz.
			-> Son satırda, pozitif tamsayı dizisini sıralamak için kullanılan ikinci kapsayıcıyı belirterek, algoritmanız tarafından kullanılan zamanı gösteren açık bir metin göstermelisiniz.

		!!! Sıralamanızı gerçekleştirmek için kullanılan zamanın gösterim biçiminde özgürsünüz ancak seçilen kesinlik, kullanılan iki kap(container) arasındaki farkı net bir şekilde görmenizi sağlamalıdır.

		İşte standart kullanıma bir örnek:
---------------------------------------------------------------------------------------------------------------
			$> ./PmergeMe 3 5 9 7 4
			Before: 3 5 9 7 4
			After: 3 4 5 7 9
			Time to process a range of 5 elements with std::[..] : 0.00031 us
			Time to process a range of 5 elements with std::[..] : 0.00014 us
			$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
			Before: 141 79 526 321 [...]
			After: 79 141 321 526 [...]
			Time to process a range of 3000 elements with std::[..] : 62.14389 us
			Time to process a range of 3000 elements with std::[..] : 69.27212 us
			$> ./PmergeMe "-1" "2"
			Error
			$>
---------------------------------------------------------------------------------------------------------------

		!!! Uyarı: Önceki alıştırmalarda kullandığınız kap(lar)(containers) burada yasaklanmıştır

		!!! Yinelemelerle ilgili hataların yönetimi sizin takdirinize bırakılmıştır.
Not:
	"Kap", "kapsayıcı" ve "container" terimleri genellikle aynı anlamı taşır ve genellikle bir şeyi içine almak veya taşımak için kullanılan bir nesneyi ifade etmek için kullanılır.
	Bu terimler genellikle nakliye veya depolama endüstrisinde kullanılırken, bilgisayar biliminde "container" terimi, bir yazılım ortamında bir uygulama veya hizmetin çalıştırıldığı izole edilmiş bir ortamı ifade etmek için de kullanılır.

	(./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`) çalışmıyor, brew ile shuf'un indirilmesi gerekiyor bunu yerine:
		-> (ARG=(`ruby -e "puts (1..1000000).to_a.shuffle[0..2999].join(' ')"`); ./PmergeMe $ARG) Kullanılacak komut. Ayrı argüman olarak ele alıyor. 1 ile 100000 arasından 3000 sayı döndürüyor.
		-> (ARG=(`ruby -e "puts (1..3000).to_a.shuffle.join(' ')"`); ./PmergeMe $ARG) Ayrı argüman olarak ele alıyor. 1 ile 3000 arasından 3000 adet sayıyı döndürüyor. Aralık ne kadar geniş olursa o kadar sayıyı döndürür.
		-> (ARG=$(jot -r -s " " 3000 1 100000); ./PmergeMe $ARG) Tek argüman olarak ele alıyor.

	Çalıştırmak için komut satırına: 'make random INPUT=3000'

	https://www.geeksforgeeks.org/merge-sort-vs-insertion-sort/

Eva Rules:

*/
int main(int argc, char **argv){

	try
	{
		argc--;
		argv++;
		PmergeMe::checkArg(argc, argv);
		PmergeMe::setContainers(argc, argv);
		PmergeMe::sortListContainer();
		PmergeMe::sortVectorContainer();
	}
	catch ( std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
