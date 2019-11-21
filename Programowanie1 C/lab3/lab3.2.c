#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateArray(int size)
{
    int *tablica = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        tablica[i] = rand() % 100;
    }
    return tablica;
}

int minmax(int *tablica, int size, int sortType)
{
    int x;
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            x = tablica[i];

        if (tablica[i] < x && sortType == 0)
            x = tablica[i];

        if (tablica[i] > x && sortType == 1)
            x = tablica[i];
    }
    return x;
}

void sortArray(int *tablica, int size, int sortType)
{

    for (int i = 0; i < size; i++) //Wybieranie liczby z tablicy
    {
        for (int j = 0; j < size; j++) //Wybieranie liczby z tablicy
        {
            if (tablica[i] < tablica[j] && sortType == 0) //Porównywanie liczby i z liczbą j, wykonuje się dla każdej liczby j w pętli.
            {

                int a = tablica[i];
                tablica[i] = tablica[j]; //Zamiana miejscami liczby i z liczbą j
                tablica[j] = a;
            }

            if (tablica[i] > tablica[j] && sortType == 1) //Porównywanie liczby i z liczbą j, wykonuje się dla każdej liczby j w pętli.
            {

                int a = tablica[i];
                tablica[i] = tablica[j]; //Zamiana miejscami liczby i z liczbą j
                tablica[j] = a;
            }
        }
    }
}

float average(int *tablica, int size)
{
    float sum = 0.00;
    for (int i = 0; i < size; i++)
    {
        sum = sum + tablica[i];
    }
    return (float)(sum / size);
}

void printArray(int *tablica, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
            printf("%d, ", tablica[i]);
        else
            printf("%d.", tablica[i]);
    }
}

void saveArray(int *tablica, int size)
{
    FILE *plik;

    plik = fopen("program.txt", "w");

    for (int i = 0; i < size; i++)
    {

        fprintf(plik, "%d,", tablica[i]);
    }
    fclose(plik);
}

int *loadArray(int *length)
{
    FILE *plik;

    *length = 0;
    plik = fopen("program.txt", "r");
    while (fscanf(plik, "%d,") != EOF)
    {
        ++*length;
    }
    printf("%d\n", *length);
    fclose(plik);

    int *tablica = malloc(*length * sizeof(int));
    plik = fopen("program.txt", "r");
    for (int i = 0; i < *length; i++)
    {
        fscanf(plik, "%d,", &tablica[i]);
    }
    fclose(plik);
    return tablica;
}

void menu(int typ, int clear)
{
    if (clear == 1)
    {
        system("cls");
        printf("Programowanie lab 3.2");
    }
    if (typ == 0)
    {
        printf("\n\n[1] Wygeneruj nowa tablice\n");
        printf("[2] Wczytaj tablice z pliku\n");
        printf("[0] Wyjdz z programu\n");
        printf("Wybierz: ");
    }
    else if (typ == 1)
    {
        printf("\n\nPodaj wielkosc tablicy: ");
    }
    else if (typ == 2)
    {
        printf("\n[1] Sortuj tablice rosnaco\n");
        printf("[2] Sortuj tablice malejaco\n");
        printf("[3] Zapisz tablice do pliku\n");
        printf("[0] Wroc do poczatku\n");
        printf("Wybierz: ");
    }
    else if (typ == 5)
    {
        printf("                 //Tablica Zapisana//\n\n");
    }
    else if (typ == 9)
        printf("\n\n");
}

int main()
{
    srand(time(NULL));
    int *array;
    int size = 0;
    int wybor;

    for (;;)
    {
        menu(0, 1);

        scanf("%d", &wybor);

        if (wybor == 1)
        {
            menu(1, 1);
            scanf("%d", &size);
            array = generateArray(size);
        }
        else if (wybor == 2)
        {
            printf("%d", size); // Dlaczego z tym działa, bez tego nie??????
            array = loadArray(&size);
        }
        else if (wybor == 0)
        {
            printf("\n\nZapraszamy ponownie!\n");
            exit(0);
        }

        while (wybor != 0) // pod-menu
        {
            if (wybor == 3)
                menu(5, 1);
            else
                menu(9, 1);

            printf("Array: ");

            printArray(array, size);

            printf("\nMin: %d", minmax(array, size, 0)); //0 - min, 1 - max
            printf("\nMax: %d", minmax(array, size, 1));
            printf("\nAverage: %.2f\n", average(array, size));

            menu(2, 0);

            scanf("%d", &wybor);
            switch (wybor)
            {
            case 1:
                sortArray(array, size, 0);
                break;
            case 2:
                sortArray(array, size, 1);
                break;
            case 3:
                saveArray(array, size);
                break;
            case 0:
                free(array);
                break;
            }
        }

        //end for
    }
}
