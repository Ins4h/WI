#include <stdio.h>

int main()
{

    float a;
    float b;
    float c;

    printf("Enter number");
    scanf("%f", &a);

    printf("Enter number");
    scanf("%f", &b);

    printf("Enter number");
    scanf("%f", &c);

    printf("Suma: %.2f\n", a + b + c);

    if (a <= b && b <= c)
    {
        printf("Ascending: %.2f, %.2f, %.2f\n", a, b, c);
        printf("Min: %.2f\nMax: %.2f", a, c);
    }
    else if (a <= c && c <= b)
    {
        printf("Ascending: %.2f, %.2f, %.2f\n", a, c, b);
        printf("Min: %.2f\nMax: %.2f", a, b);
    }
    else if (b <= a && a <= c)
    {
        printf("Ascending: %.2f, %.2f, %.2f\n", b, a, c);
        printf("Min: %.2f\nMax: %.2f", b, c);
    }
    else if (b <= c && c <= a)
    {
        printf("Ascending: %.2f, %.2f, %.2f\n", b, c, a);
        printf("Min: %.2f\nMax: %.2f", b, a);
    }
    else if (c <= a && a <= b)
    {
        printf("Ascending: %.2f, %.2f, %.2f\n", c, a, b);
        printf("Min: %.2f\nMax: %.2f", c, b);
    }
    else if (c <= b && b <= a)
    {
        printf("Ascending: %.2f, %.2f, %.2f\n", c, b, a);
        printf("Min: %.2f\nMax: %.2f", c, a);
    }

    return 0;
}