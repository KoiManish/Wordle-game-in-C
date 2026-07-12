#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "common.h"
#include "io.h"

void prompt(char *correctword)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        switch (corrects[i])
        {
        case false:
            printf("-");
            break;
        case true:
            printf("%c", correctword[i]);
            break;
        }
    }

    printf("\n\n%d> ", (5 - rounds));
    fflush(stdout);
}

void print_results(Result *res, char *guess)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        switch (res[i])
        {
        case ResultGreen:
            printf("%s%c%s", ClrGreen, guess[i], ClrStop);
            break;

        case ResultYellow:
            printf("%s%c%s", ClrYellow, guess[i], ClrStop);
            break;

        case ResultRed:
            printf("%s%c%s", ClrRed, guess[i], ClrStop);
            break;

        default:
            printf("Unknown: %d\n", res[i]);
            break;
        }
    }

    printf("\n");
}

char *readline(void)
{
    static char buf[8];
    int size;

    memset(buf, 0, 8);

    fgets(buf, 7, stdin);

    size = strlen(buf);
    assert(size > 0);

    size--;
    buf[size] = 0;

    return buf;
}
