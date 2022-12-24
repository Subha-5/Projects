#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int number, guess, nguesses = 0;
    srand(time(0));
    number = rand() % 100 + 1; //generates random number between 1 to 100
    printf("The number is %d\n", number);
    return 0;
}