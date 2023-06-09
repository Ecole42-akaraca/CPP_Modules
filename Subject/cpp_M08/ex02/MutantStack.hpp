#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm>
# include <stack>
# include <deque>
# include "Color.hpp"

/*
	Stack sınıfından kalıtım için template tanımlanırken:
			template <typename T, typename Container = std::deque<T>>
			class MutantStack : public std::stack<T, Container> {}
	
		kullanılır. Lakin şu şekilde de kullanılabilir:
			template <typename T>
			class MutantStack : public std::stack<T> {}

	Birinci kullanım neyi ifade eder:
		--> "template <typename T, typename Container = std::deque<T>>"
		MutantStack sınıfının şablon bir sınıf olduğunu belirtir.
		T ve Container şablon parametreleri, sınıfın türlerini belirtmek için kullanılır.
		T, MutantStack'in saklayacağı öğelerin türünü belirlerken,
			Container ise altta yatan veri yapısının türünü belirler.
		Varsayılan olarak Container türü std::deque<T> olarak belirlenmiştir.

		--> "class MutantStack : public std::stack<T, Container> {}"
		MutantStack sınıfının std::stack sınıfından kalıtım aldığını belirtir.
		std::stack sınıfı, T türündeki öğeleri Container türündeki bir veri yapısında saklayan bir yığın yapısı sağlar.
		std::stack sınıfın tüm üye işlevlerine ve özelliklerine erişebilir ve bunları kalıtım yoluyla miras alır.

		MutantStack<int> olarak kullanıldığında, int türündeki öğeleri std::deque<int> veri yapısında saklayan bir yığına sahip oluruz.

	İkinici kullanım neyi ifade eder:
		MutantStack sınıfının std::stack sınıfından kalıtım aldığını belirtirken Container parametresi belirtilmemektedir.
		Bu durumda, MutantStack sınıfı, std::stack sınıfından T türündeki öğeleri saklamak için varsayılan bir veri yapısı olan
			std::deque<T> kullanılır. Yani otomatik olarak kendisi belirler.

	Stack'te bir container ise ve içinde bu yapı bulunuyorsa neden itteratöre sahip değil?
		std::stack sınıfı, bir std::container sınıfıdır ve içerisinde bir Container veri yapısını kullanır.
		Ancak, std::stack sınıfı, özünde bir yığındır ve yığınlarda genellikle doğrudan erişim veya döngülerle tarama yapma ihtiyacı olmadığı düşünülerek, 
			STL'deki diğer veri yapılarına kıyasla bir yineleyici (iterator) arayüzü sunmaz.

	std::deque<T> nedir?
		Çift uçlu bir sıra (double-ended queue) veri yapısını temsil eden bir sınıftır. (queue -> kuyruk, sıra)
		"deque" kısaltması, "double-ended queue" ifadesinin baş harflerinden oluşur.

		std::deque<T>, dinamik boyutu olan bir veri yapısıdır ve bellekte ardışık olarak depolanan elemanları içerir.
		std::deque<T>, hem baş hem de son tarafından ekleme ve çıkarma işlemlerine O(1) zaman karmaşıklığı ile destek verir.
		Bu özelliği sayesinde, hem başa hem de sona hızlı bir şekilde erişilebilir ve değişiklik yapılabilir.

		Dinamik boyutu olan ve ekleme/çıkarma işlemlerinde yüksek performans sunan bir veri yapısıdır.

	O1 nedir?
		O(1) zaman karmaşıklığı, bir algoritmanın işlem süresinin girdi boyutundan bağımsız olarak sabit kalacağını ifade eder.
		Başka bir deyişle, algoritmanın çalışma süresi, girdi boyutunun büyüklüğünden etkilenmez.
		Herhangi bir öğeyi doğrudan erişmek veya bir işlem yapmak için sabit bir süre gerektirir.

	--> typedef typename std::stack<T>::container_type::iterator iterator;
		std::stack<T> sınıfının içinde bulunan container_type isimli bir türün iterator türünü temsil eden bir takma ad tanımlar.
		Stack şablon sınıfı container_type isimli bir iç türe sahiptir.

	typedef typename std::stack<T>::container_type::iterator iterator; ile nelere erişilebilir?
		-> iterator begin(): Konteynerin ilk elemanının bir iterator'unu döndürür.
		-> iterator end(): Konteynerin sonunu temsil eden bir iterator'unu döndürür.
		-> iterator rbegin(): Konteynerin sondan başlayarak ilk elemanına doğru iterasyon yapmak için bir ters iterator'unu döndürür.
		-> iterator rend(): Konteynerin sondan başlayarak sonunu temsil eden bir ters iterator'unu döndürür.

*/
template < typename T >
class MutantStack : public std::stack<T> {

public:

	MutantStack( void ) : std::stack<T>() {
		std::cout << "Default Constructor Called" << std::endl;
	};
	MutantStack( const MutantStack &ref ) : std::stack<T>(ref) {
		std::cout << "Copy Constructor Called" << std::endl;
		*this = ref;
	};
	~MutantStack( void ) {
		std::cout << "Destructor Called" << std::endl;
	};

	MutantStack &operator=( const MutantStack &ref ) {
		std::cout << "Copy Assignment Operator Called" << std::endl;
		// Kendi atama operatörünü çağırmak daha güvenli olduğundan dolayı çağırıyoruz.
		// Ekstra veriler ve özelliklerin atanmasını istiyorsak kullanıyoruz. örn "MyClass(void) : name(....)"'deki name'in atanması için vb.
		std::stack<T>::operator=(ref);

		// std::stack<T>::operator=(ref); yapısının bulunduğu classı etkileyip etkilemediğini bu şekilde öğrenebiliriz.
		// MutantStack asd;
		// (void )ref;
		// std::stack<T>::operator=(asd);
		// if (this->empty())
		// 	std::cout << RED << __LINE__ << END << std::endl;
		return (*this);
	};

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin( void ){
	 	return ( this->c.begin() );
	};

	iterator end( void ){
	 	return ( this->c.end() );
	};

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin( void ){
		return ( this->c.rbegin() );
	};

	reverse_iterator rend( void ){
		return ( this->c.rend() );
	};

};

/*
// Yukarıda bulunan yapı ile aynı mantıkta çalışır, sadece standart tanımlama yapılması yerine kullanıcı tarafından tanımlandırılmıştır.
template < typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

	MutantStack( void ) : std::stack<T, Container>() {};
	MutantStack( const MutantStack &ref ) : std::stack<T, Container>(ref) {
		*this = ref;
	};
	~MutantStack( void ) {
		std::cout << "Destructor Called" << std::endl;
	};

	MutantStack &operator=( const MutantStack &ref ) {
		std::stack<T, Container>::operator=(ref); // kendi atama operatörünü çağırmak daha güvenli olduğundan dolayı çağırıyoruz.
		return (*this);
	};

	typedef typename Container::iterator iterator;

	iterator begin( void ){
	 	return ( this->c.begin() );
	};

	iterator end( void ){
	 	return ( this->c.end() );
	};
};
*/

/*
// .hpp dosyasından kod bloğunun ayrıştırılıp sadece tanımlamaların kalınması isteniyorsa:
template < typename T >
class MutantStack : public std::stack<T> {

public:

	MutantStack( void );
	MutantStack( const MutantStack &ref );
	~MutantStack( void );

	MutantStack &operator=( const MutantStack &ref );

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin( void );

	iterator end( void );
};
# include "MutantStack.tpp"
*/

#endif
