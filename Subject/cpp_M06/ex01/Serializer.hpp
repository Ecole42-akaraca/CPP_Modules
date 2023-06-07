#ifndef SERIALIZER_HPP
 #define SERIALIZER_HPP

#include <iostream>
//#include <cstdint> kütüphanesinde uintptr_t için C++98 kullanıma uygun değildir. <stdint.h> kullanılmalıdır.
#include <stdint.h>

struct Data{
	int		x;
	float	y;
};

class Serializer{
	public:
		static uintptr_t serialize( Data* ptr );
		static Data* deserialize( uintptr_t raw );

};

#endif
