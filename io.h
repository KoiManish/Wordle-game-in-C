#ifndef IO_H
#define IO_H

#include "common.h"

char *readline(void);
void prompt(char *correctword);
void print_results(Result *res, char *guess);

#endif
