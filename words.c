#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "common.h"
#include "words.h"

static char words[max][5];

ValResult validator(char *word)
{
    int n, i;
    bool ret;

    bool strcmp_(char *str1, char *str2)
    {
        int s, i;

        s = 0;

        for (i = 0; i < 5; i++)
            if (str1[i] == str2[i])
                s++;

        return (s == 5) ? true : false;
    };

    n = strlen(word);

    if (n != 5)
        return ValBadInput;

    ret = false;

    for (i = 0; i < max; i++)
    {
        if (strcmp_(words[i], word))
        {
            ret = true;
            break;
        }
    }

    if (ret)
        return ValOk;
    else
        return ValNoSuchWord;
}

char *randomword(int m)
{
    int x;
    static char ret[8];

    x = rand() % m;

    ret[0] = words[x][0];
    ret[1] = words[x][1];
    ret[2] = words[x][2];
    ret[3] = words[x][3];
    ret[4] = words[x][4];
    ret[5] = 0;

    return ret;
}

bool isin(char c, char *str)
{
    bool ret;
    int i, size;

    ret = false;
    size = strlen(str);

    for (i = 0; i < size; i++)
    {
        if (str[i] == c)
        {
            ret = true;
            break;
        }
    }

    return ret;
}

Result cc(char guess, int idx, char *word)
{
    char correct;

    correct = word[idx];

    if (guess == correct)
    {
        corrects[idx] = true;
        return ResultGreen;
    }
    else if (isin(guess, word))
        return ResultYellow;

    return ResultRed;
}

Result *cw(char *guess, char *word)
{
    static Result res[5];
    int i;

    for (i = 0; i < 5; i++)
        res[i] = cc(guess[i], i, word);

    return res;
}

int readfile(char *filename)
{
    char buf[8];
    int i, size;
    FILE *fd;

    fd = fopen(filename, "r");

    if (!fd)
    {
        perror("fopen");
        return -1;
    }

    i = 0;
    memset(buf, 0, 8);

    while (fgets(buf, 7, fd))
    {
        size = strlen(buf);

        if (size < 1)
        {
            memset(buf, 0, 8);
            continue;
        }

        size--;
        buf[size] = 0;

        if (size != 5)
        {
            memset(buf, 0, 8);
            continue;
        }

        words[i][0] = buf[0];
        words[i][1] = buf[1];
        words[i][2] = buf[2];
        words[i][3] = buf[3];
        words[i][4] = buf[4];

        memset(buf, 0, 8);
        i++;

        if (i >= max)
            break;
    }

    fclose(fd);

    return i;
}
