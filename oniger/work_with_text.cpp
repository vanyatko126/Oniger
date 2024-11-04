#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "tools.h"

void delete_n(txt *a)
{
    for(int i = 0; i < a->buff_len; i++)
    {
        if(a->buff[i] == '\n') 
            a->buff[i] = '\0';
    }
}
void buble_str(txt *a)
{
    for(int i = 0; i < a->cnt_str - 1; i++)
    {
        for(int j = 0; j < a->cnt_str - 1 - i; j++)
        {
            if(compare_str(a->buff_pointers[j], a->buff_pointers[j+1]) == LONGER)
            {
                char * x = a->buff_pointers[j + 1];
                a->buff_pointers[j+1] = a->buff_pointers[j];
                a->buff_pointers[j] = x;
            }
        }
    } 
}