#include "MutantStack.hpp"

/*
	---> C++ Templated containers, iterators, algorithms / Şablonlu konteynerlar, yineliyiciler, algoritmalar <---
	--->  Mutated abomination / Mutasyona uğramış iğrençlik <---
	Subject Çeviri:
		Şimdi, daha ciddi şeylere geçme zamanı.

		Garip bir şey geliştirelim.
		std::stack kabı çok güzel.
		Ne yazık ki, yinelenemeyen tek STL Kapsayıcılarından(container) biridir.
		Bu çok kötü.

		Ama bunu neden kabul edelim? Özellikle eksik özellikleri oluşturmak için orijinal yığını kesme özgürlüğünü alabilirsek.
		Bu adaletsizliği onarmak için std::stack kapsayıcısını(container) yinelenebilir(iterator) yapmalısınız.

		Bir MutantStack sınıfı yazın.
		Bir std::stack açısından uygulanacaktır. (implemented in terms of a std::stack)
		Tüm üye işlevlerini ve ek bir özelliği sunacak: yineleyiciler(iterators).

		Elbette, her şeyin beklendiği gibi çalıştığından emin olmak için kendi testlerinizi yazıp teslim edeceksiniz.

		Main.cpp
---------------------------------------------------------------------------------------------------------------
			int main(){
				MutantStack<int>	mstack;

				mstack.push(5);
				mstack.push(17);

				std::cout << mstack.top() << std::endl;

				mstack.pop();

				std::cout << mstack.size() << std::endl;

				mstack.push(3);
				mstack.push(5);
				mstack.push(737);
				//[...]
				mstack.push(0);

				MutantStack<int>::iterator it = mstack.begin();
				MutantStack<int>::iterator ite = mstack.end();

				++it;
				--it;
				while (it != ite){
					std::cout << *it << std::endl;
					++it;
				}
				std::stack<int> s(mstack);
				return (0);
			}
---------------------------------------------------------------------------------------------------------------

		İlk kez MutantStack'inizle çalıştırırsanız ve ikinci kez MutantStack'i örneğin bir std::list ile değiştirirseniz, iki çıktı aynı olmalıdır.
		Elbette, başka bir kapsayıcıyı(container) test ederken, aşağıdaki kodu karşılık gelen üye işlevlerle güncelleyin (push(), push_back() haline gelebilir).
Not:
	Stack yapısında iteratorler olmadığından dolayı, bu yapıyı MutantStack class'ımıza kalıtım yaparak, bu sınıf ile artık stack ve iterator yapısını kullanabilmekteyiz.

Eva Rules:
As usual, there has to be the main function that contains enough tests to prove the program work as expected.
If there isn't, do not grade tihs exercise.
If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

	>	Her zaman olduğu gibi, programın beklendiği gibi çalıştığını kanıtlamak için yeterli testi içeren ana işlev olmalıdır.
	Eğer yoksa egzersizi derecelendirmeyin.
	Arayüz(interface) olmayan herhangi bir sınıf, geleneksel kanonik sınıf formunda değilse, bu alıştırmaya not vermeyin.

MutantStack class:
There is a MutantStack class that inherits from std::stack and offers all of its member functions.
It has an iterator. Also, it is possible to do at least the operations shown in the subject's examples using iterators.

	>	std::stack öğesinden miras alan ve tüm üye işlevlerini sunan bir MutantStack sınıfı vardır.
	Bir yineleyiciye(iterator) sahiptir. Ayrıca en azından konunun örneklerinde gösterilen işlemleri yineleyiciler kullanarak yapmak mümkündür.

Better tests:
There is a at least a main() function that has more tests than the ones from the subject.

	>	Konudaki testlerden daha fazla test içeren en azından bir main() işlevi vardır.

*/
int main( void ){
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}
