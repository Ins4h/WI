#include <iostream>
using namespace std;

// Służy do stworzenia wskaźnika polimorficznego
class Czworokat
{
protected:
    int a, b, c, d;

public:
    Czworokat(){};
    Czworokat(int a2, int b2, int c2, int d2) : a(a2), b(b2), c(c2), d(d2){};
    int wypisz()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
    };

    virtual int pole() = 0; // Jest wymagana, aby wskaźnik polimorficzny wskazujący
                            // na obiekt dziecko mógł wykonać metodę pole()
                            // Dopisek virtual jest to informacja dla kompilatora,
                            // że ta metoda ma być zawsze przesłaniana przez potomka.
};

class Prostokat : public Czworokat
{
public:
    Prostokat(int a2, int b2)
    {
        a = a2;
        c = a2;
        b = b2;
        d = b2;
    };

    int wymiary(int w1, int w2)
    {
        a = w1;
        c = w1;
        b = w2;
        d = w2;
    };

    virtual int pole() // Przysłania metodę pole() rodzica
    {
        int pole = a * b;
        return pole;
    }
};

class Kwadrat : public Czworokat
{
public:
    Kwadrat(int a2)
    {
        a = a2;
        b = a2;
        c = a2;
        d = a2;
    };

    int wymiar(int w1)
    {
        a = w1;
        b = w1;
        c = w1;
        d = w1;
    }

    virtual int pole() // Przysłania metodę pole() rodzica
    {
        int pole = a * a;
        return pole;
    };
};

int main()
{
    int w, wp1, wp2;
    Prostokat *P = new Prostokat(2, 3);
    Kwadrat *K = new Kwadrat(3);
    Czworokat *wsk; // Tworzenie wskaźnika polimorficznego
    wsk = K;        // Przypisanie do wskaźnika polimorficznego wskaźnika na obiekt Kwadrat
    cout << "Podaj wymiar boku kwadratu: ";
    cin >> w;
    K->wymiar(w);
    wsk->wypisz();
    cout << "Pole kwadratu wynosi: " << wsk->pole() << endl;
    cout << endl;

    cout << "Podaj wymiar boku 1 prostokata: ";
    cin >> wp1;
    cout << endl;
    cout << "Podaj wymiar boku 2 prostokata: ";
    cin >> wp2;
    P->wymiary(wp1, wp2);
    P->wypisz();
    wsk = P; // Przypisanie do wskaźnika polimorficznego wskaźnika na obiekt Prostokąt
    cout << "Pole prostokata wynosi: " << wsk->pole() << endl;

    delete P;
    delete K;
}