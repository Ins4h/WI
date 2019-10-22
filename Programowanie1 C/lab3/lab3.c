#include <stdio.h>

int main()
{

    int numberList[100];                                          //Tablica z maksymalną wielkością 100 elementów
    int arrayLenght = sizeof(numberList) / sizeof(numberList[0]); //Długość tablicy
    float median;
    float sum = 0;
    float average;
    int menu;
    int rng = rand() % 100;

    printf("1.Array with random numbers\n\n");
    printf("2.Array with random numbers and random lenght\n\n");
    printf("3.Your Array\n\n");
    scanf("%d", &menu); //Wybór menu

    if (menu == 1) // Kod wykonywania podczas wyboru 1 z menu
    {
        printf("Array lenght: ");
        scanf("%d", &arrayLenght);                    // Pobieranie długości tablicy od użytkownika
        while (arrayLenght <= 0 || arrayLenght > 100) // Kod wykonywany w przypadku wpisania długości tablicy z poza przedziału
        {
            printf("\n\nArray lenght should be 1-100\n\n"); // Prośba o ponowne(poprawne) podanie długości tablicy
            printf("Array lenght: ");
            scanf("%d", &arrayLenght);
        }

        printf("\n\nElements: ");
        for (int i = 0; i < arrayLenght; i++)
        {
            numberList[i] = rand() % 100; //Generowanie pseudolosowych elementów tablicy
            printf("%d, ", numberList[i]);
        }
    }
    else if (menu == 2) // Wybór 2
    {
        arrayLenght = rng; // Przypisanie pseudolosowej liczby do długości tablicy
        for (int i = 0; i < arrayLenght; i++)
        {
            numberList[i] = rand() % 100; //Generowanie pseudolosowych elementów tablicy
            printf("%d, ", numberList[i]);
        }
    }
    else if (menu == 3) //Wybór 3
    {
        printf("Array Lenght: ");
        scanf("%d", &arrayLenght);                    //Pobieranie docelowej długości tablicy
        while (arrayLenght <= 0 || arrayLenght > 100) // Ten sam kod co w 1 przypadku
        {
            printf("\n\nArray lenght should be 1-100\n\n");
            printf("Array lenght: ");
            scanf("%d", &arrayLenght);
        }

        printf("Elements: ");

        for (int i = 0; i < arrayLenght; i++)
        {
            scanf("%d", &numberList[i]); //Pobieranie elementów tablicy od użytkownika
        }
    }

    for (int i = 0; i < arrayLenght; i++) //Wybieranie liczby z tablicy
    {
        for (int j = 0; j < arrayLenght; j++) //Wybieranie liczby z tablicy
        {
            if (numberList[i] < numberList[j]) //Porównywanie liczby i z liczbą j, wykonuje się dla każdej liczby j w pętli.
            {

                int a = numberList[i];
                numberList[i] = numberList[j]; //Zamiana miejscami liczby i z liczbą j
                numberList[j] = a;
            }
        }
    }
    printf("\n\nAscending: ");

    for (int i = 0; i < arrayLenght; i++)
    {
        printf("%d, ", numberList[i]); //Wyświetlanie wyników
    }

    // Analogicznie do przykładu wyżej, ze zmianą znaku porównania.

    for (int i = 0; i < arrayLenght; i++)
    {
        for (int j = 0; j < arrayLenght; j++)
        {
            if (numberList[i] > numberList[j])
            {

                int a = numberList[i];
                numberList[i] = numberList[j];
                numberList[j] = a;
            }
        }
    }
    printf("\n\nDescending: ");
    for (int i = 0; i < arrayLenght; i++)
    {
        printf("%d, ", numberList[i]);
    }

    printf("\n\nMin: %d", numberList[arrayLenght - 1]); // Wartość minimalna, ostatnia wartość z tablicy.

    printf("\n\nMax: %d", numberList[0]); // Wartość maxymalna, pierwsza wartość z tablicy.

    for (int i = 0; i < arrayLenght; i++)
    {
        sum += numberList[i]; // Dodawanie elementów w tablicy
    }
    average = sum / arrayLenght; // Średnia arytmetyczna

    printf("\n\nSum: %.2f", sum);
    printf("\n\nAverage: %.2f", average);

    if (arrayLenght % 2 == 0)
    {
        median = (numberList[arrayLenght / 2] + numberList[(arrayLenght / 2 - 1)]) / 2; // Mediana w przypadku gdy tablica parzysta
    }
    else
    {
        median = numberList[arrayLenght / 2]; //Mediana w przypadku gdy tablica nieparzysta
    }
    printf("\n\nMedian: %.1f", median);

    return 0;
}