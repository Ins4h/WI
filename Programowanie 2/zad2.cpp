#include <time.h>
#include <iostream>

using namespace std;

class Data
{
private:
    int rok;
    int miesiac;
    int dzien;
    string przypomnienie;

public:
    Data()
    {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);

        dzien = aTime->tm_mday;
        miesiac = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
        rok = aTime->tm_year + 1900; // Year is # years since 1900
    };

    Data(int r, int m, int d) : rok(r), miesiac(m), dzien(d){

                                                    };

    Data(Data &copy)
    {
        rok = copy.rok;
        miesiac = copy.miesiac;
        dzien = copy.dzien;
        przypomnienie = copy.przypomnienie;
        cout << "copy constructor" << endl;
    }

    ~Data()
    {
        cout << "Tu destruktor" << endl;
        przypomnienie = "";
    }

    void dodajDzien(int n)
    {

        if (n > 0 && n <= 31)
        {
            dzien = n;
        }
    }

    void zapiszWiadomosc(string tresc)
    {
        przypomnienie = tresc;
    }

    void wypisz()
    {
        cout << "\nDzien: " << dzien << "  miesiac: " << miesiac << "  rok: " << rok << "\n"
             << przypomnienie << endl;
    }
};

int main()
{
    Data przypomnienie;
    Data przypomnienie2(2020, 7, 20);
    przypomnienie.wypisz();
    przypomnienie2.wypisz();
    przypomnienie.zapiszWiadomosc("przypomnienie");
    przypomnienie2.zapiszWiadomosc("przypomnienie 2");
    przypomnienie.dodajDzien(30);
    przypomnienie2.dodajDzien(28);
    przypomnienie.wypisz();
    przypomnienie2.wypisz();

    Data przypomnienie3(przypomnienie2);
    przypomnienie3.wypisz();
}
