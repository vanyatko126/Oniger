int isEqualTime(TicTac a, TicTac b)
{
    return ((a.h == b.h) && (a.min == b.min));
}

TicTac after(TicTac a, int min)
{
    a.h = (a.h + ((a.min + min) / 60)) % 12;
    a.min = (a.min + min)%60;
    return a;
}

void printTic(TicTac a)
{
    printf("%02d:%02d\n", a.h, a.min);
}

void backward(TicTac *me, TicTac a)
{
    int h1 = me->h; 
    int min1 = me->min;
    int count_min1 = h1 * 60 + min1;
    int count_amin = a.h * 60 + a.min;
    int sex = count_min1 - count_amin;
    if (sex > 0)
    {
        me->h = sex / 60;
        me->min = sex - ((sex/60) * 60);
    }
    if (sex == 0)
    {
        me->h = 0;
        me->min = 0;
    }
    if ((sex < 0) && (sex > (-60)))
    {
        me->h = 11;
        me->min = 60 + sex;
    }
    if (sex <= (-60))
    {
        me->h = 11 + (sex/60);
        me->min = 60 + (sex%60);
    }
        
}

void forward(TicTac *me, TicTac a)
{
    me->h = (me->h + a.h + ((me->min + a.min) / 60)) % 12;
    me->min = (me->min + a.min) % 60;
}
