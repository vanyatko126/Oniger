#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

void count_str(txt *a)
{
    int cnt = 0;
    for(int i = 0; i < a->buff_len; i++)
    {
        if(a->buff[i] == '\n')
            cnt += 1;
    }
    a->cnt_str = cnt;
}

void get_pointers(txt *a)
{
    int cnt = 1;
    a->buff_pointers = (char**)calloc(a->cnt_str, sizeof(char*));
    a->buff_pointers[0] = &a->buff[0];
    for (int i = 1; i < a->buff_len; i++)
    {
        if(a->buff[i-1] == '\0')
        {
            a->buff_pointers[cnt] = &a->buff[i];
            cnt+=1;
        }
    }
}

compare compare_str(char* first_str, char* second_str)
{
    int i = 0;
    // if(strlen(first_str) < strlen(second_str))
    //     return LONGER;
    // else if(strlen(first_str) > strlen(second_str))
    //     return SHORTER;
    // else
    {
        while(first_str[i])
        {
            if(first_str[i] > second_str[i] || !second_str[i])
                return LONGER;
            else if(first_str[i] < second_str[i])
                return SHORTER;
            else if(first_str[i] == second_str[i])
            {
                i++;
            }
        }
        if(second_str[i])
            return EQUAL;
        else
            return SHORTER;
    }
}

void output(txt *a)
{
    for(int i = 0; i < a->cnt_str; i++)
    {
        printf("%s\n", a->buff_pointers[i]);
    }
}