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
	stack::push() -> Stack'in üstüne sayı ekler.
	stack::swap() -> Stack 1 ve Stack 2 arasındaki verilerin takası gerçekleşir.

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
int main( void ){

	{
		std::cout << RED "---------------- Mandatory part ----------------" END << std::endl;
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

		mstack.push(3);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite){
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << RED "---------------- iterator example ----------------" END << std::endl;
		
		MutantStack<int>	Stack;

		Stack.push(10);
		Stack.push(20);
		Stack.push(30);

		MutantStack<int>::iterator it = Stack.begin();
		MutantStack<int>::iterator ite = Stack.end();

		std::cout << "Stack elements (bottom to top): ";
		while (it != ite){
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	{
		std::cout << RED "---------------- reverse_iterator example ----------------" END << std::endl;
		MutantStack<int> reStack;

		reStack.push(10);
		reStack.push(20);
		reStack.push(30);

		MutantStack<int>::reverse_iterator it = reStack.rbegin();
		MutantStack<int>::reverse_iterator ite = reStack.rend();
		
		std::cout << "Stack elements (top to bottom): ";
		while (it != ite) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	{
		std::cout << RED "---------------- stack empty method ----------------" END << std::endl;

		MutantStack<int> emptyStack;

		if (emptyStack.empty())
			std::cout << "Stack is empty" << std::endl;

		emptyStack.push(1);

		if (!emptyStack.empty())
			std::cout << "Stack is not empty" << std::endl;
	}

	{
		std::cout << RED "---------------- stack find size method ----------------" END << std::endl;

		MutantStack<int> sizeStack;

		sizeStack.push(5);

		std::cout << "Size: " << sizeStack.size() << std::endl;

		sizeStack.push(10);

		std::cout << "Size: " << sizeStack.size() << std::endl;
	}

	{
		std::cout << RED "---------------- stack top method ----------------" END << std::endl;

		MutantStack<int> topStack;

		topStack.push(10);
		topStack.push(20);

		std::cout << "Top element: " << topStack.top() << std::endl;

		topStack.push(30);

		std::cout << "Top element: " << topStack.top() << std::endl;

	}

	{
		std::cout << RED "---------------- stack pop method ----------------" END << std::endl;

		MutantStack<int> popStack;

		popStack.push(10);
		popStack.push(20);
		popStack.push(30);

		std::cout << "Top element: " << popStack.top() << std::endl;
		std::cout << "Size: " << popStack.size() << std::endl;

		popStack.pop();

		std::cout << "Top element: " << popStack.top() << std::endl;
		std::cout << "Size: " << popStack.size() << std::endl;

		popStack.pop();

		std::cout << "Top element: " << popStack.top() << std::endl;
		std::cout << "Size: " << popStack.size() << std::endl;
		
		popStack.pop();
		// std::cout << "Top element: " << popStack.top() << std::endl; // argüman kalmayınca bunu kullanırsak seg fault yiyoruz.
		std::cout << "Size: " << popStack.size() << std::endl;
	}

	{
		std::cout << RED "---------------- stack swap method ----------------" END << std::endl;

		MutantStack<int>	swapStack;

		swapStack.push(5); 
		swapStack.push(10); 
		swapStack.push(15);

		std::cout << "First stack size: " << swapStack.size() << std::endl;
		std::cout << "First stack top element: " << swapStack.top() << std::endl;

		MutantStack<int>	tmpStack;

		tmpStack.push(3);

		tmpStack.swap(swapStack);

		tmpStack.push(20);

		std::cout << "Second stack size: " << tmpStack.size() << std::endl;
		std::cout << "Second stack top element: " << tmpStack.top() << std::endl;

		std::cout << "First stack size: " << swapStack.size() << std::endl;
		std::cout << "First stack top element: " << swapStack.top() << std::endl;

	}

	{
		std::cout << RED "---------------- stack copy method ----------------" END << std::endl;

		MutantStack<int>	copyStack;

		copyStack.push(3);
		copyStack.push(6);
		copyStack.push(9);
		copyStack.push(12);

		std::cout << "First stack size: " << copyStack.size() << std::endl;
		std::cout << "First stack top element: " << copyStack.top() << std::endl;
		std::cout << "First stack bottom element: " << *copyStack.begin() << std::endl;

		MutantStack<int>	tmpStack(copyStack);

		std::cout << "Second stack size: " << tmpStack.size() << std::endl;
		std::cout << "Second stack top element: " << tmpStack.top() << std::endl;
		std::cout << "Second stack bottom element: " << *tmpStack.begin() << std::endl;

		tmpStack.pop();

		std::cout << "First stack size: " << copyStack.size() << std::endl;
		std::cout << "First stack top element: " << copyStack.top() << std::endl;

		std::cout << "Second stack size: " << tmpStack.size() << std::endl;
		std::cout << "Second stack top element: " << tmpStack.top() << std::endl;
	}

	{
		std::cout << RED "---------------- stack class difference type (double) ----------------" END << std::endl;

		MutantStack<double>	dStack;

		dStack.push(3.33);
		dStack.push(4.44);
		dStack.push(5);


		MutantStack<double>::iterator it = dStack.begin();
		MutantStack<double>::iterator ite = dStack.end();

		std::cout << "Stack elements (bottom to top): ";
		while (it != ite){
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	{
		std::cout << RED "---------------- stack class difference type (string) ----------------" END << std::endl;

		MutantStack<std::string>	sStack;

		sStack.push("Alice");	
		sStack.push("John");	
		sStack.push("Micheal");

		MutantStack<std::string>::iterator it = sStack.begin();
		MutantStack<std::string>::iterator ite = sStack.end();

		std::cout << "Stack elements (bottom to top): ";
		while (it != ite){
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	return (0);
}
