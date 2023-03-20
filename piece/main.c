#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int piece = rand() % 2;

    if (piece)
        printf("Pile !\n");
    else
        printf("Face !\n");

    return 0;
}