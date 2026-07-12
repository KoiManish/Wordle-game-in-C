#include <stdio.h>
#include <assert.h>

#include "common.h"
#include "words.h"
#include "game.h"

int main(int argc, char **argv)
{
    int n;
    char *p;

    (void)argc;
    (void)argv;

    corrects[0] = false;
    corrects[1] = false;
    corrects[2] = false;
    corrects[3] = false;
    corrects[4] = false;

    rounds = 0;
    win = false;

    seed();

    n = readfile("wordlist.txt");
    assert(!(n < 0));

    p = randomword(n);

    printf("Welcome to Wordle. Please enter a proper\n");
    printf("5 letter English word. Good luck!\n\n");

    continuation = true;

    while (continuation)
    {
        gameloop(p);
    }

    printf("The correct word was: '%s'\n", p);

    if (win)
        printf("Congratulations, you won the game.\n");
    else
        printf("You lost. Game over.\n");

    return 0;
}
