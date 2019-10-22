#include <stdio.h>

int main()
{

    int numberList[100], arrayLenght;

    printf("Array Lenght: ");
    scanf("%d", &arrayLenght); //Pobieranie docelowej długości tablicy
    printf("Elements: ");

    for (int i = 0; i < arrayLenght; i++) //Pobieranie danych od użytkownika
    {
        scanf("%d", &numberList[i]);
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
    printf("\nAscending:\n ");
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
    printf("\nDescending:\n ");
    for (int i = 0; i < arrayLenght; i++)
    {
        printf("%d, ", numberList[i]);
    }
}