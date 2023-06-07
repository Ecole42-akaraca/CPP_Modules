#include <iostream>
using namespace std;

class Math{
public:
	static void cube(int x){
		cout << x * x *x << endl;
	}
};

int main()
{
	Math::cube(3);
	return (0);
}