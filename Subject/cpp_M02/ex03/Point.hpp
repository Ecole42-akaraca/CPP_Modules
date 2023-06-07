#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
		// Anything else useful etc. -> double sample;
	public:
		Point( void );
		Point( const float x, const float y);
		Point( const Point &rhs );
		~Point( void );
		Point &operator=( const Point &rhs );

		Fixed	getPointX( void ) const;
		Fixed	getPointY( void ) const;

};

bool	slope( const Point a, const Point b, const Point c, const Point point );
bool	bspArea( const Point a, const Point b, const Point c, const Point point );
bool	bsp( const Point a, const Point b, const Point c, const Point point );

#endif
