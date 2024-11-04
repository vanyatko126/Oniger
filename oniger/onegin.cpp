#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys\stat.h>
#include <string.h>



#include "tools.h"
#include "types.h"
#include "work_with_files.h"
#include "work_with_text.h"



int main()
{
    txt a = {};
    file_open(&a);
    count_str(&a);
    delete_n(&a);
    get_pointers(&a);
    buble_str(&a);
    output(&a);
    free(a.buff);
    return 0;
}



