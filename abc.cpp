#include <stdio.h>
#include <math.h>

int check(int a);

int main()
{
    int A, B, k, a[100];
    scanf("%d %d %d", &A, &B, &k);
    for(int i = 0; A + i <= B, i++)
    {
        int chislo = A + i;
        if (check(chislo)) a[i] == chislo;
        printf("%d", a[i]); 
    } 
}
int check(int a)
{
    int cnt = 0;
    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0) cnt += 1;
    }
    if (cnt == 1) return 1;
    else return 0;
}