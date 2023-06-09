#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm>
# include <stack>
# include "MutantStack.tpp"

template < typename T >
class MutantStack : public std::stack<T>{
private:

public:
	// typename iterator = typename std::stack<T>::container_type::iterator;

	// iterator begin(){
	// 	return (std::stack<T>::c.begin());
	// }

	// iterator end(){
	// 	return (std::stack<T>::c.end());
	// }

	MutantStack( void );
	~MutantStack( void );

};

#endif
