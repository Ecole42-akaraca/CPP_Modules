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
	Stack baştan eklemeli bir yapıya sahiptir.
	stack::empty() -> Stack'in boş olup olmadığını kontrol eder.
	stack::top() -> En son eklenen elemanını gösterir.
	stack::pop() -> En son eklenen elemanını siler.
	stack::size() -> Stack'teki eleman sayısını döndürür.

	typename türü belli olmadığını belirtir.
	örn: std::vector<T>'nin hata almasının nedeni tipinin belli olmamasından dolayıdır, bunun için tipinin belirsiz olduğunu tanımlamak için başına typename eklenir, ve kendin belirle demek isteriz.



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
// int main( void ){
// 	MutantStack<int>	mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);

// 	mstack.push(3);
// 	std::cout << "--" <<mstack.top() << std::endl;
// 	MutantStack<int> fuck(mstack);
// 	std::cout << "... " << fuck.top() << std::endl;


// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;
// 	while (it != ite){
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);


// 	return (0);
// }

void	MutanStackSelfTest( void )
{
	std::cout << "********* MutantStack Area *********"\
		<< std::flush << std::endl;

	MutantStack<int>	mstack;

	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl;
	mstack.push(5);
	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl;
	mstack.push(17);
	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl << std::endl;

	std::cout << "mstack.top(): " << mstack.top()\
		<< std::flush << std::endl << std::endl;

	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl;
	mstack.pop(); // Removes the top element.
	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl << std::endl;

	// std::cout << mstack.size() << std::flush << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// [...]
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	std::cout << std::flush << std::endl;
	std::cout << "it: " << *it << std::flush << std::endl;
	++it;
	std::cout << "++it: " << *it << std::flush << std::endl;
	--it;
	std::cout << "--it: " << *it << std::flush << std::endl << std::endl;

	std::cout << "it = mstack.begin(): " << *mstack.begin()\
		<< std::flush << std::endl;
	std::cout << "ite = mstack.end(): " << *mstack.end()\
		<< std::flush << std::endl;
	std::cout << "while...  NOT: mstack.size(): " << mstack.size()\
		<< std::flush << std::endl;
	int	i = 0;
	while (it != ite)
	{
		std::cout << "i[" << i++ << "]: " << std::flush;
		std::cout << *it << std::flush << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);
	std::cout << std::flush << std::endl;
	std::cout << "s.size(): " << s.size() << std::flush << std::endl;
	std::cout << "s.top(): " << s.top() << std::flush << std::endl;
	// std::cout << "s.begin(): " << s.begin() << std::flush << std::endl;
	// std::cout << "s.end(): " << s.end() << std::flush << std::endl;

	std::cout << "____________ List Area ____________"\
		<< std::flush << std::endl;

	std::list<int>	mList;

	mList.push_back(5);
	mList.push_back(17);

	std::cout << mList.back() << std::flush << std::endl;

	mList.pop_back();

	std::cout << mList.size() << std::flush << std::endl;

	mList.push_back(3);
	mList.push_back(5);
	mList.push_back(737);
	// [...]
	mList.push_back(0);

	std::list<int>::iterator	listIt = mList.begin();
	std::cout << "listIt: " << *listIt << std::flush << std::endl;
	std::list<int>::iterator	listIte = mList.end();
	std::cout << "listIte: " << *listIte << std::flush << std::endl << std::endl;

	std::cout << "listIt: " << *listIt << std::flush << std::endl;
	++listIt;
	std::cout << "listIt: " << *listIt << std::flush << std::endl;
	--listIt;
	std::cout << "listIt: " << *listIt << std::flush << std::endl << std::endl;
	int	j = 0;
	while (listIt != listIte)
	{
		std::cout << "j[" << j++ << "]: " << std::flush;
		std::cout << *listIt << std::flush << std::endl;
		++listIt;
	}
	// std::list<int>::iterator	listBack = mList.back();
	// std::list<int>::iterator	listBack = mList.front();
	// j = 0;
	// while (listIt != listIte)
	// {
	// 	std::cout << "j[" << j++ << "]: " << std::flush;
	// 	std::cout << *listIt << std::flush << std::endl;
	// 	++listIt;
	// }
	std::list<int>	l(mList);
	std::cout << std::flush << std::endl;
	std::cout << "l.size(): " << l.size() << std::flush << std::endl;
	std::cout << "l.back(): " << l.back() << std::flush << std::endl;
	std::cout << "l.front(): " << l.front() << std::flush << std::endl;
	std::cout << "l.begin(): " << *l.begin() << std::flush << std::endl;
	std::cout << "l.end(): " << *l.end() << std::flush << std::endl;
}

void	MutantStackMendatoryTest( void )
{
	std::cout << "********* MutantStack Area *********"\
		<< std::flush << std::endl;

	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::flush << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::flush << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// [...]
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::flush << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	std::cout << "____________ List Area ____________"\
		<< std::flush << std::endl;

	std::list<int>	mList;

	mList.push_back(5);
	mList.push_back(17);

	std::cout << mList.back() << std::flush << std::endl;

	mList.pop_back();

	std::cout << mList.size() << std::flush << std::endl;

	mList.push_back(3);
	mList.push_back(5);
	mList.push_back(737);
	// [...]
	mList.push_back(0);

	std::list<int>::iterator	listIt = mList.begin();
	std::list<int>::iterator	listIte = mList.end();

	++listIt;
	--listIt;
	while (listIt != listIte)
	{
		std::cout << *listIt << std::flush << std::endl;
		++listIt;
	}
	std::list<int>	l(mList);
}

int	main()
{
	std::cout << BLUE "--------- Mendatory Test Area! -----------" END\
		<< std::flush << std::endl;
	MutantStackMendatoryTest();
	std::cout << BLUE "------------------------------------------" END\
		<< std::flush << std::endl;
	std::cout << BLUE "------------- Self Test Area! ------------" END\
		<< std::flush << std::endl;
	MutanStackSelfTest();
	std::cout << BLUE "------------------------------------------" END\
		<< std::flush << std::endl;
	return (0);
}