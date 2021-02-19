#include <iostream>
#include <stdio.h>

using namespace std;

class Ulamek {

        int licznik;
        int mianownik;

    public:

        Ulamek()
        {};

        Ulamek(int l, int m) : licznik(l), mianownik(m)
        {};

        int get_licznik() {
            return licznik;
        };

        int get_mianownik(){
            return mianownik;
        }

        int set_licznik(){
            cout << "Podaj wartosc licznika: " << endl;
            while(!(cin >> licznik)){
                cin.clear();
                cin.ignore();
                cout << "Podaj liczbe: " <<endl;
            } return licznik;
        }

        int set_mianownik(){
            cout << "Podaj wartosc mianownika: " <<endl;
            while(!(cin >> mianownik)){
                cout << "Podaj liczbe: " <<endl;
                cin.clear();
                cin.ignore();
            }
            if (mianownik == 0) {
                cout << "Podaj prawidlowa wartosc mianownika: " <<endl;
                set_mianownik();
            } else return mianownik;
            }

        int wypisz() {
            cout << get_licznik() << "/" << get_mianownik() << endl;
        }

        Ulamek operator+ (Ulamek &obj) {
            Ulamek wynik;
            if(mianownik == obj.mianownik) {
                wynik.mianownik = mianownik;
                wynik.licznik = licznik + obj.licznik;
            } else {
            wynik.mianownik = mianownik * obj.mianownik;
            wynik.licznik = (wynik.mianownik/mianownik*licznik) + (wynik.mianownik/obj.mianownik*obj.licznik);
            }
            return wynik;
        }


        Ulamek operator- (Ulamek &obj) {
            Ulamek wynik;
             if(mianownik == obj.mianownik) {
                wynik.mianownik = mianownik;
                wynik.licznik = licznik - obj.licznik;
            } else {
            wynik.mianownik = mianownik * obj.mianownik;
            wynik.licznik = (wynik.mianownik/mianownik*licznik) - (wynik.mianownik/obj.mianownik*obj.licznik);
            }
            return wynik;
        }


        Ulamek operator* (Ulamek &obj) {
            Ulamek wynik;
            wynik.mianownik = mianownik * obj.mianownik;
            wynik.licznik = licznik * obj.licznik;
            return wynik;
        }

        Ulamek operator/ (Ulamek &obj) {
            Ulamek wynik;
            wynik.mianownik = mianownik * obj.licznik;
            wynik.licznik = licznik * obj.mianownik;
            return wynik;
        }
};

int main() {

    Ulamek u1;
    Ulamek u2;
    Ulamek wynikDodawania;
    Ulamek wynikOdejmowania;
    Ulamek wynikMnozenia;
    Ulamek wynikDzielenia;

    cout << "Ulamek 1: " << endl;
    u1.set_licznik();
    u1.set_mianownik();
    u1.wypisz();

    cout << "Ulamek 2: " << endl;
    u2.set_licznik();
    u2.set_mianownik();

    cout << "Ulamek 1: ";
    u1.wypisz();

    cout << "Ulamek 2: ";
    u2.wypisz();

    wynikDodawania = u1 + u2;
    cout << "Wynik dodawania: ";
    wynikDodawania.wypisz();

    wynikOdejmowania = u1 - u2;
    cout << "Wynik odejmowania: ";
    wynikOdejmowania.wypisz();

    wynikMnozenia = u1 * u2;
    cout << "Wynik mnozenia: ";
    wynikMnozenia.wypisz();

    wynikDzielenia = u1 / u2;
    cout << "Wynik dzielenia: ";
    wynikDzielenia.wypisz();
    return 0;
};