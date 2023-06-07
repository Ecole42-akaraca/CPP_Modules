#include <iostream>

class Test{
private:
	const int b;

public:
	int a;
	const int c;

	const Test&test( void )const;
	//const Test&test( void );
};

std::ostream &operator<<( std::ostream & convert, Test const & i){
    convert << i;
    return (convert);
}

const Test &Test::test( void ) const{
	this->b = 5;
	this->a = 5;
	return (*this);
}


// const Test &Test::test( void ){
// 	this->b = 5;
// 	this->a = 5;
// 	return (*this);
// }


int main(){
	Test deneme;

	deneme.test();
	std::cout << deneme << std::endl;
	return (0);
}