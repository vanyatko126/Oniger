#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys\stat.h>

typedef struct {
    char* buff;
    int buff_len;
    int cnt_str;
    char** buff_pointers;
}txt;

void count_seek(txt *a, FILE * f);
void count_stat(txt *a);
void delete_n(txt *a);
void count_str(txt *a);


int main()
{
    txt a = {};
    FILE * f = fopen("Onegin.txt", "r");
    count_seek(&a, f);
    // count_stat(&a);

    a.buff = (char*)calloc(a.buff_len, sizeof(char));
    fread(a.buff, sizeof(char), a.buff_len, f);
    
    // printf("%d\n", a.buff_len);


    count_str(&a);

    delete_n(&a);


    // a.buff_pointers[0] = &a.buff[0];
    // int q = 0;
    // for (int i = 1; i < a.buff_len; i++)
    // {
    //     if (a.buff[i-1] == '\0')
    //     {
    //         q += 1;
    //         a.buff_pointers[q] = &a.buff[i];
    //     }
    // }


    printf("%d", a.cnt_str);

    // for(int i = 0; i < a.buff_len; i++)
    // {
    //     printf("%c", a.buff[i]);
    // }

    free(a.buff);
    fclose(f);
    return 0;
}

void count_seek(txt *a, FILE * f)
{
    fseek(f, 0, SEEK_END);
    a->buff_len = ftell(f);
    fseek(f, 0, SEEK_SET);
}

void count_stat(txt *a)
{
    struct stat st;
    stat("Onegin.txt", &st);
    a->buff_len = st.st_size; 
}

void delete_n(txt *a)
{
    for(int i = 0; i < a->buff_len; i++)
    {
        if(a->buff[i] == '\n') 
            a->buff[i] = '\0';
    }
}

void count_str(txt *a)
{
    int cnt = 1;
    for(int i = 0; i < a->buff_len; i++)
    {
        if(a->buff[i] == '\n')
            cnt += 1;
    }
    a->cnt_str = cnt;
}