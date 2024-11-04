#ifndef TYPES
#define TYPES
#include <stdio.h>

typedef enum
{
    LONGER = 1,
    EQUAL = 0,
    SHORTER = -1
}compare;

typedef struct {
    FILE * f;
    char* buff;
    int buff_len;
    int cnt_str;
    char** buff_pointers;
}txt;

#endif