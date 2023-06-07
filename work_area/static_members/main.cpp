#include <iostream>
using namespace std;

class Gamer{
public:
	static int gamers;
	Gamer(){
		gamers++;
		cout << "Yeni oyuncu oluşturuldu" << endl;
	}
};

int Gamer::gamers = 0; // static değerler için kullanılıyor.

int main()
{
	Gamer gamer1;
	Gamer gamer2;

	cout << Gamer::gamers << endl;
	return (0);
}