#include "Point.hpp"

static Fixed	abs( Fixed num ){

	if (num < 0)
		return (num * -1);// We don't have *= operator.
	return (num);
}

/*
Koordinatlardan üçgenin alanını bulma determinant işelemi ile gerçekleştirilir.

|Ax	  Ay|
|	X	|
|Bx	  By|
|	X	|	=> (1/2)*( |(Ax*By + Bx*Cy + Cx*Ay) - ( Ay*Bx + By*Cx + Cy*Ax)| ) = Üçgenin Alanı
|Cx	  Cy|
|	X	|
|Ax	  Ay|
*/
static Fixed	area( const Point a, const Point b, const Point c){

	// return (abs(((a.getPointX()*b.getPointY() + b.getPointX()*c.getPointY() + c.getPointX()*a.getPointY()) - (a.getPointY()*b.getPointX() + b.getPointY()*c.getPointX() + c.getPointY()*a.getPointX())) / 2));
	return (abs(((a.getPointX() * (b.getPointY() - c.getPointY()))
		+ (b.getPointX() * (c.getPointY() - a.getPointY()))
		+ (c.getPointX() * (a.getPointY() - b.getPointY()))) / 2));
}

/*
	slope = i * rise / run

	- "i" is equal to 1 if a line is rising and to -1 if the line is decreasing.
	- "rise" is the length of the vertical side of the triangle.
	- "run" is the length of the horizontal side.

		   /
	      /|
	     / |
	    /  |
	   /   | rise
	  /    |
	 /_____|
	/	run
*/
bool	slope( Point const a, Point const b, Point const c, Point const point ){
	
	std::cout << "--------- Third Style (Slope) --------" << std::endl;

	Fixed aB = ((abs(a.getPointY() - b.getPointY())) / (abs(a.getPointX() - b.getPointX())));
	Fixed aC = ((abs(a.getPointY() - c.getPointY())) / (abs(a.getPointX() - c.getPointX())));
	Fixed bC = ((abs(b.getPointY() - c.getPointY())) / (abs(b.getPointX() - c.getPointX())));
	Fixed pA = ((abs(point.getPointY() - a.getPointY())) / (abs(point.getPointX() - a.getPointX())));
	Fixed pB = ((abs(point.getPointY() - b.getPointY())) / (abs(point.getPointX() - b.getPointX())));
	Fixed pC = ((abs(point.getPointY() - c.getPointY())) / (abs(point.getPointX() - c.getPointX())));

	std::cout << "aB: " << aB << std::endl;
	std::cout << "aC: " << aC << std::endl;
	std::cout << "bC: " << bC << std::endl;
	std::cout << "pA: " << pA << std::endl;
	std::cout << "pB: " << pB << std::endl;
	std::cout << "pC: " << pC << std::endl;

	if ((pA == aB || pA == aC || pA == bC) || (pB == aB || pB == aC || pB == bC) || (pC == aB || pC == aC || pC == bC))
		return (false);
	return (true);
}

/**
 * @brief 
 * 
Input: A = (0, 0), B = (4, 3), C = (4, 0), P(3, 1)
Output: Inside
Explanation:
              B(4,3)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(4,0)
Input: A = (0, 0), B = (4, 3), C = (4, 0), P(3, 1)
Output: Outside
Explanation:
              B(4,3)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(4,0)
Solution: 
Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3). And coordinates of the given point P be (x, y)
Calculate area of the given triangle, i.e., area of the triangle ABC in the above diagram.
Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1 - y2) ] / 2
Calculate area of the triangle PAB. We can use the same formula for this. Let this area be A1.
Calculate area of the triangle PBC. Let this area be A2.
Calculate area of the triangle PAC. Let this area be A3.
If P lie(position) inside the triangle, then A1 + A2 + A3 must be equal to A.
 * 
 * @param a 
 * @param b 
 * @param c 
 * @param point 
 * @link https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
 * @return true If point inside.
 * @return false If point outside.
 */
bool	bspArea( const Point a, const Point b, const Point c, const Point point ){

	std::cout << "--------- Second Style (Area) --------" << std::endl;
	
	Fixed	abcArea = area(a, b, c);
	Fixed	pabArea = area(point, a, b);
	Fixed	pbcArea = area(point, b, c);
	Fixed	pcaArea = area(point, c, a);

	std::cout << "pointX: " << point.getPointX() << std::endl;
	std::cout << "pointY: " << point.getPointY() << std::endl;
	std::cout << "abc: " << abcArea << std::endl;
	std::cout << "pab: " << pabArea << std::endl;
	std::cout << "pbc: " << pbcArea << std::endl;
	std::cout << "pca: " << pcaArea << std::endl;

	return ((pabArea + pbcArea + pcaArea) == abcArea);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ){

	std::cout << "--------- First Style (Location) --------" << std::endl;

	if ((point.getPointX() == a.getPointX()
		&& point.getPointY() == a.getPointY()))
	{
		std::cout << RED "Point on 'a' vertex!" END << std::endl;
		return (false);
	}
	else if ((point.getPointX() == b.getPointX()
		&& point.getPointY() == b.getPointY()))
	{
		std::cout << RED "Point on 'b' vertex!" END << std::endl;
		return (false);
	}
	else if ((point.getPointX() == c.getPointX()
		&& point.getPointY() == c.getPointY()))
	{
		std::cout << RED "Point on 'c' vertex!" END << std::endl;
		return (false);
	}

	Fixed	bx(b.getPointX() - a.getPointX());
	Fixed	by(b.getPointY() - a.getPointY());
	Fixed	cx(c.getPointX() - a.getPointX());
	Fixed	cy(c.getPointY() - a.getPointY());
	Fixed	x(point.getPointX() - a.getPointX());
	Fixed	y(point.getPointY() - a.getPointY());
	Fixed	d(bx * cy - cx * by);

	Fixed	WA = (x * (by - cy) + y * (cx - bx) + bx * cy - cx * by) / d;
	Fixed	WB = (x * cy - y * cx) / d;
	Fixed	WC = (y * bx - x * by) / d;

	std::cout << "bx: " << bx << std::endl;
	std::cout << "by: " << by << std::endl;
	std::cout << "cx: " << cx << std::endl;
	std::cout << "cy: " << cy << std::endl;
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "WA: " << WA << std::endl;
	std::cout << "WB: " << WB << std::endl;
	std::cout << "WC: " << WC << std::endl;

	if (!(WA.toFloat() >= 0.0 && WA.toFloat() <= 1.0))
		return (false);
	else if (!(WB.toFloat() >= 0.0 && WB.toFloat() <= 1.0))
		return (false);
	else if (!(WC.toFloat() >= 0.0 && WC.toFloat() <= 1.0))
		return (false);
	return (true);
}
