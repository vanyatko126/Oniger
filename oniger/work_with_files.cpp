#include <stdio.h>
#include <stdlib.h>


#include "types.h"

void count_seek(txt *a)
{
    fseek(a->f, 0, SEEK_END);
    a->buff_len = ftell(a->f);
    fseek(a->f, 0, SEEK_SET);
}

void file_open(txt *a)
{
    a->f = fopen("Onegin.txt", "rb");
    count_seek(a);
    a->buff = (char*)calloc(a->buff_len + 1, sizeof(char));
    a->buff[a->buff_len]='\0';
    fread(a->buff, sizeof(char), a->buff_len, a->f);
    fclose(a->f);
}