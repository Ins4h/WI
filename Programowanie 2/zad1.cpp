#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

class figura
{
public:
    int promienK;
    int wysokoscW;
    int wysokoscS;

    figura()
    {
        promienK = 15;
        wysokoscW = 25;
        wysokoscS = 4;
    }

    figura(int r, int h1, int h2) : promienK(r), wysokoscW(h1), wysokoscS(h2)
    {
        // promienK = r;
        // wysokoscW = h1;
        // wysokoscS = h2;
    };

    figura(figura &copy){
        promienK = copy.promienK;
        wysokoscW = copy.wysokoscW;
        wysokoscS = copy.wysokoscS;
        cout << "Konstruktor kopiujacy tutaj" << endl;
    }

    ~figura() {
        cout << "Tu destruktor" << endl;
    };

    float oblicz_powierzchnie()
    {
        float kulaP = (4 * M_PI * pow(promienK, 2)) / 2;
        float walecP = 2 * (M_PI * pow(promienK, 2)) + 2 * M_PI * promienK * wysokoscW;
        float stozekP = M_PI * pow(promienK, 2) + M_PI * promienK * sqrt(pow(wysokoscS, 2) + pow(promienK, 2));

        float figuraP = kulaP + walecP + stozekP;
        return (figuraP);
    };

    float oblicz_objetosc()
    {
        float kulaO = (4 / 3 * M_PI * pow(promienK, 3)) / 2;
        float walecO = M_PI * pow(promienK, 2) * wysokoscW;
        float stozekO = 1 / 3 * M_PI * pow(promienK, 2) * wysokoscS;
        float figuraO = kulaO + walecO + stozekO;
        return (figuraO);
    };
};

int main()
{
    figura z1;
    figura z2(15, 25, 4);
    figura z3(10, 11, 12);
    figura z4(21, 19, 17);
    figura z5(z3);
    cout << "Pole powierzchi figury wynosi: " << z1.oblicz_powierzchnie() << endl;
    cout << "Objetosc figury wynosi: " << z1.oblicz_objetosc() << endl;
    cout << "\nPole powierzchi figury wynosi: " << z2.oblicz_powierzchnie() << endl;
    cout << "Objetosc figury wynosi: " << z2.oblicz_objetosc() << endl;
    cout << "\nPole powierzchi figury wynosi: " << z3.oblicz_powierzchnie() << endl;
    cout << "Objetosc figury wynosi: " << z3.oblicz_objetosc() << endl;
    cout << "\nPole powierzchi figury wynosi: " << z4.oblicz_powierzchnie() << endl;
    cout << "Objetosc figury wynosi: " << z4.oblicz_objetosc() << endl;
    cout << "\nPole powierzchi figury wynosi: " << z5.oblicz_powierzchnie() << endl;
    cout << "Objetosc figury wynosi: " << z5.oblicz_objetosc() << endl;
    return 0;
};