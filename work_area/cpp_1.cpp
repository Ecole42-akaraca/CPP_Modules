//g++ cpp_1.cpp && ./a.out
#include <iostream>
using namespace std; // Eğerki bu tanımla kullanımaz ise, alt yapılarda std yapısını kullanabilmek için std:: yapısının kullanılması gerekiyor. // Birden fazla namespace tanımlaması yapılabilir.
#include <fstream> //dosya işlemleri için bu kütüphane dahil edilir.

// Kullanılan heredoc(<<), argümanın yönlendirme işlemini gerçekleştiriyor. 
// statement(satır, ifade) yapılarının bittiğini tanımlamak için (;) kullanılır.
// tek bir satırda birden fazla değişken tanımlama için; int a,b,c; şeklinde kullanım yapılabilir, değer atamalı tanımlamak için; int a=10,b=5,c=3; şeklinde yapılabilir.

// int f(int x)
// {
// 	return (x * 2);
// }

int main()
{
// //---------------------------------------------------------------------------------------------------------------------------------
// 	int i;
// 	int a[2];

// 	a[0] = 30;
// 	a[1] = 25;
// 	float x = 100.111;
// 	cout<< x << endl;
// 	x = floor(x);
// 	cout<< (char)x << endl;

// 	i = 100;
// 	cout<<i; //integer değişkenleri yazdırmak için.
// 	cout<<i << endl; // << endl yapısı \n değerini atıyor, Değişken içerisinde \n yoksa veya integer bir değişken ise \n değerini atamak için kullanılır.
// 	std::cout << "haLO\n"; //using namespace std; tanımlaması yoksa(std::cout), varsa(cout) şeklinde kullanılır.
// 	cout<<"YEP\n";

// 	cout<<"i değeri:" << i << endl; // değişkenleri aynı çıktı parametresinde kullanabilmek için artarda çıktı yönlendirmesi yapılabilir.
// 	cout<<"a değeri" << a[0] << " boşluk " << a[1] << "ikinci boşluk" << endl;
// 	cout << "-------------------------------------------------------------------\n";
// //---------------------------------------------------------------------------------------------------------------------------------
// 	int l;
// 	cin >> l; //klavyeden değer okumak için kullanılıyor. //string veya int tipine göre değişiyor.
// 	cout << l << endl;
// 	cout << "-------------------------------------------------------------------\n";
// //---------------------------------------------------------------------------------------------------------------------------------
// 	// void *girdi; //hex tipinde alıyor argümanı
// 	// cin >> girdi;
// 	// cout << girdi << endl;
// //---------------------------------------------------------------------------------------------------------------------------------
// 	int case_val;

// 	case_val = 20;
// 	switch (case_val)
// 	{
// 	case 21:
// 		cout << "Değer 21" << endl;
// 		break;
// 	case 19:
// 		cout << "Değer 19" << endl;
// 	default:
// 		cout << "Diğer değerler " << case_val << endl;
// 	}
// 	cout << "-------------------------------------------------------------------\n";

// //---------------------------------------------------------------------------------------------------------------------------------
// 	for(int s = 1;s < 3; s++)
// 		cout<< "S değeri: " << s << endl;
// 	cout << "-------------------------------------------------------------------\n";

// //---------------------------------------------------------------------------------------------------------------------------------
// 	int m = 5;
// 	do {
// 		cout << "m değeri: " << m << endl;
// 		m++;
// 	} while (m > 3 && m < 8); // Bu yapıda önce işlemi yapıyor sonra kontrol ediyor.
// 	cout << "-------------------------------------------------------------------\n";

// //---------------------------------------------------------------------------------------------------------------------------------
// 	int p = 4;
// 	while ( p < 10)
// 	{
// 		if (p == 8) // p değeri 8 olduğunda bu kısmı atlayıyor, altta kalan değerlere giriş yapmıyor.
// 		{
// 			p++; // değer arttırlmaz ise sonsuz döngüye giriyor.
// 			continue;
// 		}		
// 		cout << "p değeri: " << p << endl;
// 		p++;
// 	}
// 	cout << "-------------------------------------------------------------------\n";
// //---------------------------------------------------------------------------------------------------------------------------------
// 	cout << "f fonk değeri: " << f(2) << endl;
// 	cout << "-------------------------------------------------------------------\n";
// //---------------------------------------------------------------------------------------------------------------------------------
// 	// random number generator
// 	int T;
// 	srand(time(NULL));
// 	T = rand() % 10 + 1;
// 	cout << "Random number: " << T << endl;
// 	cout << "-------------------------------------------------------------------\n";
// //---------------------------------------------------------------------------------------------------------------------------------
// 	int k[4] = {7,9,12,0};
// 	cout << k[0] << k[1] << k[2] << endl;
// 	cin >> k[3];
// 	cout << "girilen değer: " << k[3] << endl;
// 	cout << "-------------------------------------------------------------------\n";
// //---------------------------------------------------------------------------------------------------------------------------------
// 	int R[2][2] = {{4,7},{11,22}};
// 	cout <<"birinci arg: "<<  R[0][1] <<"\nikinci arg: " << R[1][1] << endl;
// 	cout << "-------------------------------------------------------------------\n";
//---------------------------------------------------------------------------------------------------------------------------------
// 	string l; //struct yapısı misali //string fonksiyonlarını kullanmak için bu yapıyı kullanmalıyız. // string kütüphanesi olarak geçmektedir.
// 	//char *str = "hi"; //sabit char dizisi olduğundan dolayı hata döndürmektedir, C'de sabit char dizisi olarak kabul edilmemektedir. (const char)
// 	char *str = (char *)"hi"; // hatayı önlemek için tipini değiştirip döndürmek gerekiyor.
// 	l = str;
// 	cout << l.size() << endl;
// 	l.append(" MERHABA");
// 	cout << l << endl;
// 	cout << l.substr(2,3) << endl;

// //---------------------------------------------------------------------------------------------------------------------------------
// 	bool q = true;
// 	if (q == true)
// 		cout << "q is true" << endl;
// 	else
// 		cout << "nopers" << endl;

// //---------------------------------------------------------------------------------------------------------------------------------
	// //yazma
	// ofstream dosya;
	// dosya.open("./deneme.txt"); //path verilebilir
	// if (dosya.is_open())
	// {
	// 	dosya << "MERHABA YARINYA\n" << endl;
	// 	dosya.close();
	// }
	// //okuma
	// string satir;
	// ifstream dosya_two ("./deneme.txt");
	// if (dosya_two.is_open())
	// {
	// 	while (getline(dosya_two,satir))
	// 	{
	// 		cout << satir << '\n';
	// 	}
	// 	dosya_two.close();
	// }
// //---------------------------------------------------------------------------------------------------------------------------------
	return (0);
}
