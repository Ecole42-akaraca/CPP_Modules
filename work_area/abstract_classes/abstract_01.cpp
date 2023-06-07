#include <iostream>

using namespace std;

// Soyut bir Hayvan sınıfı tanımlayalım
class Hayvan {
   public:
    // Saf sanal fonksiyonlar
    virtual void beslenir() = 0;
    virtual void hareketEder() = 0;
};

// Kedi sınıfı, Hayvan sınıfından türetilir
class Kedi : public Hayvan {
   public:
    void beslenir() {
        cout << "Kedi, balık ve süt gibi yiyeceklerle beslenir." << endl;
    }
    void hareketEder() {
        cout << "Kedi, dört ayak üzerinde yürür." << endl;
    }
};

// Köpek sınıfı, Hayvan sınıfından türetilir
class Köpek : public Hayvan {
   public:
    void beslenir() {
        cout << "Köpek, et gibi yiyeceklerle beslenir." << endl;
    }
    void hareketEder() {
        cout << "Köpek, dört ayak üzerinde koşar." << endl;
    }
};

int main() {
    // Hayvan sınıfından türetilen nesneler oluşturulamaz
    // Hayvan hayvan; // Hata: Soyut sınıfın nesnesi oluşturulamaz

    // Kedi ve Köpek sınıfından türetilen nesneler oluşturulabilir
    Kedi kedi;
    Köpek köpek;

    // Kedi ve Köpek nesnelerinin beslenir() ve hareketEder() fonksiyonları çağrılabilir
    kedi.beslenir();
    kedi.hareketEder();
    köpek.beslenir();
    köpek.hareketEder();

    return 0;
}