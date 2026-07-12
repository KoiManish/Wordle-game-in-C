#ifndef WORDS_H
#define WORDS_H

#include "common.h"

int readfile(char *filename);
char *randomword(int m);
ValResult validator(char *word);

bool isin(char c, char *str);
Result cc(char guess, int idx, char *word);
Result *cw(char *guess, char *word);

#endif
