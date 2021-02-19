#include <iostream>

using namespace std;

class Pies
{
private:
    string imie;
    char plec;
    string rasa;
    int wiek;
    int waga;
    int wielkosc;

public:
    Pies(string name = "Pies", char gender = 'X', string breed = "brak", int age = 0, int weight = 0, int size = 0)
        : imie(name), plec(gender), rasa(breed), wiek(age), waga(weight), wielkosc(size) // lista inicjalizująca
    {
    }

    // imie
    void setImie(string name) // Metoda set, daje możliwość ustawienia/zmiany pól prywatnych
    {
        imie = name;
    }

    string getImie() // Metoda get, zwracająca informację jaką przechowuje dane pole
    {
        return imie;
    }

    // plec
    void setPlec(char gender)
    {
        plec = gender;
    }

    char getPlec()
    {
        return plec;
    }

    // rasa
    void setRasa(string breed)
    {
        rasa = breed;
    }

    string getRasa()
    {
        return rasa;
    }

    // wiek
    void setWiek(int age)
    {
        wiek = age;
    }

    int getWiek()
    {
        return wiek;
    }

    // waga
    void setWaga(int weight)
    {
        waga = weight;
    }

    int getWaga()
    {
        return waga;
    }

    // wielkość
    void setWielkosc(int size)
    {
        wielkosc = size;
    }

    int getWielkosc()
    {
        return wielkosc;
    }
};

int main()
{

    // Obiekt P1 z domyślnymi wartościami z konstruktora. Pobranie wartości pól dzięki metodzie get.

    Pies P1;
    cout << "Pies 1 - domyslny \n";
    cout << "Imie: " << P1.getImie() << "\n"
         << "Plec: " << P1.getPlec() << "\n"
         << "Rasa: " << P1.getRasa() << "\n"
         << "Wiek: " << P1.getWiek() << " lat \n"
         << "Waga: " << P1.getWaga() << " kg \n"
         << "Wielkosc: " << P1.getWielkosc() << " cm \n\n\n";

    // Obiekt P2 Za pomocą metod set, zostały zmienione wartości pól z domyślnych konstruktora

    Pies P2;
    P2.setImie("Szarik");
    P2.setPlec('M');
    P2.setRasa("Owczarek niemiecki");
    P2.setWiek(5);
    P2.setWaga(30);
    P2.setWielkosc(80);

    // Wypisanie za pomocą strumienia wyjściowego

    cout << "Pies 2 - Szarik \n";
    cout << "Imie: " << P2.getImie() << "\n"
         << "Plec: " << P2.getPlec() << "\n"
         << "Rasa: " << P2.getRasa() << "\n"
         << "Wiek: " << P2.getWiek() << " lat \n"
         << "Waga: " << P2.getWaga() << " kg \n"
         << "Wielkosc: " << P2.getWielkosc() << " cm \n\n\n";

    // Obiekt P3 stworzony dynamicznie

    Pies *P3 = new Pies();
    P3->setImie("Nymeria");
    P3->setPlec('F');
    P3->setRasa("Husky syberyjski");
    P3->setWiek(7);
    P3->setWaga(20);
    P3->setWielkosc(54);

    cout << "Pies 3 - Nymeria \n";
    cout << "Imie: " << P3->getImie() << "\n"
         << "Plec: " << P3->getPlec() << "\n"
         << "Rasa: " << P3->getRasa() << "\n"
         << "Wiek: " << P3->getWiek() << " lat \n"
         << "Waga: " << P3->getWaga() << " kg \n"
         << "Wielkosc: " << P3->getWielkosc() << " cm \n\n\n";

    delete P3;

    return 0;
}