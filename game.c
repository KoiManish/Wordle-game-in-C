#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "common.h"
#include "game.h"
#include "io.h"
#include "words.h"

bool continuation;
int rounds;
bool corrects[5];
bool win;

void seed(void)
{
    int x;

    x = getpid();
    srand(x);
}

void gameloop(char *correct)
{
    char *input;
    Result *res;
    ValResult valres;
    int i, c;

    prompt(correct);

    input = readline();

    valres = validator(input);

    switch (valres)
    {
    case ValBadInput:
        printf("Bad input\n");
        return;

    case ValNoSuchWord:
        printf("No such word - only 5 letter English words are permitted.\n");
        rounds++;
        return;

    default:
        break;
    }

    res = cw(input, correct);

    for (i = c = 0; i < 5; i++)
    {
        if (corrects[i])
            c++;
    }

    print_results(res, input);

    if (c == 5)
    {
        win = true;
        continuation = false;
        return;
    }

    rounds++;

    if (rounds > 4)
    {
        win = false;
        continuation = false;
        return;
    }
}
