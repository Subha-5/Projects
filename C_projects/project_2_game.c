// Project 2: Snake, Water, Gun

// Snake, Water, Gun or Rock, Paper, Scissors is a game most of us have played during school time. (I sometimes play it even now :) )

// Write a C program capable of playing this game with you.

// Your program should be able to print the result after you choose Snake/Water or Gun.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SnakeWaterGun(char you, char comp)
{
    // returns 1 if you win, -1 if you lose and 0 if draw

    // condition for draw
    // Cases covered :
    // ss
    // gg
    // ww

    if (you == comp)
    {
        return 0;
    }

    // Non-Draw conditions
    // Cases covered :
    // sg
    // gs
    // sw
    // ws
    // gw
    // wg

    if (you == 's' && comp == 'w')
    {
        return 1;
    }
    else if (you == 'w' && comp == 's')
    {
        return -1;
    }

    if (you == 's' && comp == 'g')
    {
        return -1;
    }
    else if (you == 'g' && comp == 's')
    {
        return 1;
    }

    if (you == 'w' && comp == 'g')
    {
        return 1;
    }
    else if (you == 'g' && comp == 'w')
    {
        return -1;
    }
}

int main()
{
    char you, comp;

    srand(time(0));
    int number = rand() % 100 + 1;

    if (number < 33)
    {
        comp = 's';
    }
    else if (number > 33 && number < 66)
    {
        comp = 'w';
    }
    else
    {
        comp = 'g';
    }

    printf("Enter 's' for snake, 'w' for water and 'g' for gun \n");
    scanf("%c", &you);

    int result = SnakeWaterGun(you, comp);

    printf("You chose %c and computer chose %c  .\n", you, comp);

    if (result == 0)
    {
        printf("Game DRAW ! \n");
    }
    else if (result == 1)
    {
        printf("You WIN ! \n");
    }
    else
    {
        printf("You LOSE ! \n");
    }

    return 0;
}