#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//? Pq q se usar a macro isto da erro, e so me ordena e print 2 numeros
//#define size(x) sizeof(x)/sizeof(x[0])

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return (x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{
    int NUMBERSFILE = 0, i = 0;
    int *numbers;
    int val;

    FILE *fp = NULL;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%d", &val) == 1)
    {
        NUMBERSFILE++;
        //printf("%d", NUMBERSFILE);
    }
    fclose(fp);

    numbers = (int *)malloc(sizeof(int) * NUMBERSFILE);

    //*onde esta '&numbers[i]' também dá com 'numbers + i'
    fp = fopen(argv[1], "r");
    while (fscanf(fp, "%d", &val) == 1)
    {
        numbers[i] = val;
        i++;
    }

    qsort(numbers, NUMBERSFILE, sizeof(numbers[0]), compareInts);

    for (int i = 0; i <  size(numbers); i++)
    {
        printf("%d\n", numbers[i]);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}
