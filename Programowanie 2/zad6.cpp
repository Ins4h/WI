#include <iostream>
#include <math.h>

using namespace std;

class Wieloscian {
    protected:
    int dlugosc_podstawy;
    int szerokosc_podstawy;
    int wysokosc;

    public:
    void set(int d, int s, int w){
        dlugosc_podstawy = d;
        szerokosc_podstawy = s;
        wysokosc = w;
    }

};

        class Prostopadloscian :public Wieloscian {
            public:
          float objetosc() {
              float wynikObjetosc;
              wynikObjetosc = dlugosc_podstawy*szerokosc_podstawy*wysokosc;
              return wynikObjetosc;
          }

          float pole_powierzchni() {
            float wynikPole;
              wynikPole = 2*szerokosc_podstawy*wysokosc+2*dlugosc_podstawy*wysokosc+2*szerokosc_podstawy*dlugosc_podstawy;
              return wynikPole;
          }
        };


        class Ostroslup :public Wieloscian {
            public:
            float objetosc() {
                float wynikObjetosc;
                wynikObjetosc = szerokosc_podstawy*dlugosc_podstawy*wysokosc/3.;
                return wynikObjetosc;
            }

            float pole_powierzchni() {
                float wynikPole, wysokoscTrojkata1, wysokoscTrojkata2;
                wysokoscTrojkata1 = sqrt(((szerokosc_podstawy/2)^2)+(wysokosc^2));
                wysokoscTrojkata2 = sqrt(((dlugosc_podstawy/2)^2)+(wysokosc^2));
                wynikPole = (szerokosc_podstawy*dlugosc_podstawy)+(2*((szerokosc_podstawy*wysokoscTrojkata1)/2.0))+(2*((szerokosc_podstawy*wysokoscTrojkata2)/2.0));
                return wynikPole;
            };
        };


        int main() {
            Prostopadloscian *P1 = new Prostopadloscian;
            P1->set(3,2,5);
            Ostroslup O1;
            O1.set(2,2,2);

            cout << "Prostopadloscian:" << endl;
            cout << "Objetosc: " << P1->objetosc() << endl;
            cout << "Pole Powierzchni: " << P1->pole_powierzchni() << "\n" <<endl;
            cout << "Ostroslup: " << endl;
            cout << "Objetosc: " << O1.objetosc() << endl;
            cout << "Pole Powierzchni: " << O1.pole_powierzchni() << endl;
            delete P1;

        }