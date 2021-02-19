#include <iostream>
#include <typeinfo>

using namespace std;

class Trojka
{
private:
    int intA, intB, intC;
    float floatA, floatB, floatC;
    char charA, charB, charC;
    string stringA, stringB, stringC;

public:
    // template <typename temp>
    Trojka(int int_a, int int_b, int int_c, float float_a, float float_b, float float_c, char char_a, char char_b, char char_c, string string_a, string string_b, string string_c) : intA(int_a), intB(int_b), intC(int_c), floatA(float_a), floatB(float_b), floatC(float_c), charA(char_a), charB(char_b), charC(char_c), stringA(string_a), stringB(string_b), stringC(string_c){};

    template <typename temp> //Kompilator na podstawie template'u generuje kod
    temp znajdzMinimum(temp a, temp b, temp c)
    {
        temp min;

        if (a <= b && a <= c) //Sprawdza czy a jest najmniejsze
        {
            min = a;
        }

        else if (b <= c) // Jeżeli a nie było namjniejsze, to sprawdza czy b jest najmniejsze
        {
            min = b;
        }

        else
        {
            min = c; // Jeżeli nie wydarzył się przypadek powyżej to z tego wynika że c jest najmniejsze
        }

        return min;
    };

    template <typename temp>
    temp znajdzMaximum(temp a, temp b, temp c)
    {
        temp max;

        if (a >= b && a >= c) // Schemat jak powyżej, tylko sprawdzamy która jest najwieksza
        {
            max = a;
        }

        else if (b >= c)
        {
            max = b;
        }

        else
        {
            max = c;
        }

        return max;
    }

    template <typename temp>
    temp znajdzSrodkowa(temp a, temp b, temp c)
    {
        temp average;

        if ((a > b && a < c) || (a > c && a < b)) // Sprawdza cz a znajduę się między b i c albo c i b
        {
            average = a;
        }

        else if ((b > a && b < c) || (b > c && b < a))
        {
            average = b;
        }

        else if ((c > a && c < b) || (c > b && c < a))
        {
            average = c;
        }

        else if (a == b || a == c)
        {
            average = a;
        }

        else if (b == c)
        {
            average = b;
        }

        return average;
    }

    void wypisz()
    {
        cout << "Typ\t"
             << "Minimum\t"
             << "Srednia\t"
             << "Maksimum\n";
        cout << "Int:\t" << znajdzMinimum<int>(intA, intB, intC) << "\t" // <typ> mówi kompilatorowi jakiego typu jest zmienna,
             << znajdzSrodkowa<int>(intA, intB, intC) << "\t"            // która będzie wykorzystywana do wygenerowania kodu z template'u
             << znajdzMaximum<int>(intA, intB, intC) << "\n";
        cout << "Double:\t" << znajdzMinimum<float>(floatA, floatB, floatC) << "\t"
             << znajdzSrodkowa<float>(floatA, floatB, floatC) << "\t"
             << znajdzMaximum<float>(floatA, floatB, floatC) << "\n";

        cout << "Char:\t" << znajdzMinimum<char>(charA, charB, charC) << "\t"
             << znajdzSrodkowa<char>(charA, charB, charC) << "\t"
             << znajdzMaximum<char>(charA, charB, charC) << "\n";

        cout << "String:\t" << znajdzMinimum<string>(stringA, stringB, stringC) << "\t"
             << znajdzSrodkowa<string>(stringA, stringB, stringC) << "\t"
             << znajdzMaximum<string>(stringA, stringB, stringC) << "\n\n";
    }
};

int main()
{
    Trojka P1(4, 5, 2, 2.4, 6.4, 3.14, 'a', 'z', 'x', "Sun", "Proxima", "Kepler");
    P1.wypisz();

    Trojka *P2 = new Trojka(1, 2, 3, 3.14, 2.323232, 2.42, 'z', 'x', 'y', "Ziemia", "Mars", "Jowisz");
    P2->wypisz();

    // cout << typeid(string) << endl;

    delete P2;

    return 0;
}