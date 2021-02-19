#include <iostream >

using namespace std;

class Macierz {
    private:
        static const int w = 3;
        static const int k = 3;
        float matrix[w][k];
    public:
        Macierz() {
            float macierz[w][k];
            for(int i = 0; i < w; i++) {
                for(int j = 0; j < k; j++) {
                    macierz[i][j] = 0;
                    this->matrix[i][j] = macierz[i][j];
                }
            }
        }


        void wczytajDane() {
            for(int i = 0; i < w; i++) {
                for(int j = 0; j < k; j++) {
                    cout << "Element: [" <<  i+1 << "," << j+1 << "] = ";
                    cin >> matrix[i][j];
                    cout << endl;
            }
          }
        };

        void wypisz() {
            for(int i = 0; i < w; i++) {
                for(int j = 0; j < k; j++) {
                    cout << matrix[i][j] << "   ";
                }
                cout << endl;
            }
        }

        friend void dodajMacierze(Macierz& macierz1, Macierz& macierz2, Macierz& macierz3) {
            for(int i = 0; i < w; i++) {
                for(int j = 0; j < k; j++){
                    macierz3.matrix[i][j] = macierz2.matrix[i][j] + macierz1.matrix[i][j];
                }
        }
        }
        ;

};

int main() {

cout << "Macierz 1: \n";
    Macierz* M1 = new Macierz();
    M1->wypisz();
    M1->wczytajDane();

    cout << "Macierz 2: \n";
    Macierz* M2 = new Macierz();
    M2->wypisz();
    M2->wczytajDane();

    cout << "Macierz 1: \n";
    M1->wypisz();

    cout << "Macierz 2: \n";
    M2->wypisz();

    cout << "Suma macierzy: \n";
    Macierz* M3 = new Macierz();
    dodajMacierze(*M1, *M2, *M3);
    M3->wypisz();

    delete M1;
    delete M2;
    delete M3;

}