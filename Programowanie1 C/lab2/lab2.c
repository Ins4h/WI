#include <stdio.h>

int main()
{

    printf("1. Dodawanie\n"); //Wyświetlanie menu
    printf("2. Odejmowanie\n");
    printf("3. Mnozenie\n");
    printf("4. Dzielenie\n");
    printf("0. Wyjdz\n\n");

    int menu;
    float num1, num2;

    printf("Wybierz opcje z menu: ");
    scanf("%d", &menu); //Pobieranie wyboru opcji z menu od użytkownika

    if (menu != 0) //W razie wyboru opcji wyjdź, zapobiega wyświetlaniu się poniższych wyborów.
    {
        printf("Wybierz pierwsza liczbe: ");
        scanf("%f", &num1); //Pobieranie pierwszej liczby

        printf("\nWybierz druga liczbe: ");
        scanf("%f", &num2); //Pobieranie drugiej liczby
    }

    if (menu == 1)
    {
        printf("\nWyniki: %f", num1 + num2); //Wyświtlenie wyniku w przypadku wyboru opcji dodawania
    }
    else if (menu == 2)
    {
        printf("\nWyniki: %f", num1 - num2); // Opcja Odejmowania
    }
    else if (menu == 3)
    {
        printf("\nWyniki: %f", num1 * num2); // Opcja mnożenia
    }
    else if (menu == 4)
    {
        while (num2 == 0)
        {
            printf("\nDzielenie przez 0 jest niemozliwe!");
            printf("\nWybierz druga liczbe: "); //Prośba o ponowne podanie drugiej liczby
            scanf("%f", &num2);
        }

        printf("\nWyniki: %f", num1 / num2); // Opcja dzielenia
    }

    else if (menu == 0) // W przypadku wybrania opcji "Wyjdź", program się zamyka.
    {
        return 0;
    }

    return 0;
}
