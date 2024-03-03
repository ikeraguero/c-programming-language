/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

int main() {
    float celsius, fahr;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

        printf("%6s %12s \n", "Celsius", "Fahreinheit");
        printf("------------------------- \n");

    celsius = lower;
    while(celsius <= upper) {
        fahr = (celsius * 9.0 / 5.0) + 32.0;
        printf("%6.0f %9.1f \n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}