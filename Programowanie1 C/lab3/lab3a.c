#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numberList[100];
    int arrayLenght = sizeof(numberList) / sizeof(numberList[0]); // Czyli 20
    int median;
    float sum = 0;
    float average;
    int menu;
    int rng = rand() % 100;

    printf("Elements: ");
    for (int i = 0; i < arrayLenght; i++)
    {
        numberList[i] = rand() % 100;
        printf("%d, ", numberList[i]);
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
    printf("\n\nMedian: %d", median);

    return 0;
}