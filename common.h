#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4

#define max 4899

#define ValOk 0
#define ValBadInput 1
#define ValNoSuchWord 2

#define ClrGreen "\033[0;32m"
#define ClrYellow "\033[0;33m"
#define ClrRed "\033[0;31m"
#define ClrStop "\033[0m"

typedef char Result;
typedef char ValResult;

extern bool continuation;
extern int rounds;
extern bool corrects[5];
extern bool win;

#endif
