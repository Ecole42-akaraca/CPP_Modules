#include "Point.hpp"

/**
 * @brief 
 * 
 * @link https://umitsen.wordpress.com/2013/04/07/nokta-ucgenin-icinde-mi-degil-mi-test-etme/
 * @link https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
 * @link https://www.math10.com/en/geometry/geogebra/geogebra.html
 * 
 * @return int 
 */
int	main()
{
	Point	a;// (0, 0)
	Point	b(3.0, 4.0);// (3, 4)
	Point	c(4.0, 0.0);// (4, 0);
	Point	p(2.54, 2.36);	// intersect.
	// Point	p(1.94, 2.58);	// intersect.
	// Point	p(3.75, 1.0);	// 3.75 inside/edge.
	// Point	p(2.44, 3.25);	// inside/edge.
	// Point	p(2.1, 0);		//inside/edge.
	// Point	p(3.76, 1.0);	// 3.76 outside.
	// Point	p(0.0, 0.0);	// (0, 0) a vertex.
	// Point	p(3.0, 4.0);	// (3, 4) b vertex.
	// Point	p(4.0, 0.0); 	// (3, 4) c vertex.

	std::cout << YELLOW "Coordinats: a(" << a.getPointX() << "," << a.getPointY() << ") - " \
		<< "b(" << b.getPointX() << "," << b.getPointY() << ") - " \
		<< "c(" << c.getPointX() << "," << c.getPointY() << ") - " \
		<< "p(" << p.getPointX() << "," << p.getPointY() << ")" END << std::endl;
	if (bsp(a, b, c, p) == true && bspArea(a, b, c, p) == true && slope(a, b, c, p) == true)
		std::cout << GREEN "The Point bsp(): \"INSIDE\" the triangle (TRUE)" END << std::endl;
	else
		std::cout << RED "The Point bsp(): \"OUTSIDE\" the triangle (FALSE)" END << std::endl;
	return (0);
}
