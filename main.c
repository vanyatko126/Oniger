#include <stdio.h>
#include <math.h>

typedef enum
{
    INDIFINITE=0,    //def
    LINEAR=1,
    QUADRATIC=2
} functiontype; //красиво назвать кодстайл все по красоте сделать

typedef enum
{
    NOROOTS=0,
    ONEROOT=1,
    TWOROOTS=2,
    INFROOTS=-1
} roots;

typedef struct
{
    double a,b,c,x1,x2, x1_input, x2_input;
    roots cntroots, cntroots_input;
    functiontype type_equation, type_equation_input;  //новая struct для tester
} pick;

int compare(double num1, double num2);

void tester(pick *params);//название

void getcoaafs(pick *params);//название

void solver(pick *params);

void output(pick *params);

void quadr_solver(pick *params);

void linear_solver(pick *params);

int main()
{
    pick params={0,0,0,0,0,0,0,NOROOTS,NOROOTS,INDIFINITE,INDIFINITE};
   // struct ... = {&params, -1, 2, TWOROOTS, QUADRATIC};
    getcoaafs(&params);
    solver(&params);
    tester(&params);
    output(&params);
}

void getcoaafs(pick *params)
{
    printf("Input a,b and c\n");
    while (scanf("%lf %lf %lf",&params->a,&params->b,&params->c)!=3)
    {
        printf("Try one more time\n") ;
        while (getchar()!=EOF); //доделать
    }
    printf("Input x1 , x2, number of roots and type of quation\n");
    while (scanf("%lf %lf %d %d",&params->x1_input,&params->x2_input,
        &params->cntroots_input,&params->type_equation_input)!=4)
    {
        printf("Try one more time\n") ;
        while (getchar()!='\n');
    }
}

void solver(pick *params)
{
    // assert(isinf(a) || isinf(b) || isinf(c));
    double a=params->a;
    if(compare(a,0))
    {
        linear_solver(params);
    }
    else
    {
        quadr_solver(params);
    }
}

void output(pick *params)
{
    switch(params->type_equation)
    {
        case INDIFINITE:
            printf("Equation is indifinite\n");
            break;
        case LINEAR:
            printf("Equation is linear\n");
            break;
        case QUADRATIC:
            printf("Equation is quadratic\n");
            break;
        default:
            printf("Impossible to understand type of your equation\n");
    }

    switch(params->cntroots)
    {
        case NOROOTS:
            printf("Equation does not has roots\n");
            break;
        case INFROOTS:
            printf("Equation has infinity number of roots\n");
            break;
        case ONEROOT:
            printf("x1 = x2 = %lf\n",params->x1);
            break;
        case TWOROOTS:
            printf("x1 = %lf, x2 = %lf\n",params->x1,params->x2);
            break;
        default:
            printf("You have inputed something wrong");
    }
}
int compare(double num1, double num2)
{
    return fabs(num1 - num2)<0.000001;

}
void quadr_solver(pick *params)
{
    double a=params->a, b=params->b, c=params->c;
    double disk=b*b-4*a*c;
    if (compare(b,0))
    {
        if ((c > 0 && a > 0) || (c < 0 && a < 0))
        {
            params->cntroots=NOROOTS;
            params->type_equation=INDIFINITE;
        }
        else
        {
            params->x1=(-b + sqrt(disk))/(2 * a);
            params->x2=(-b - sqrt(disk))/(2 * a);
            params->cntroots=TWOROOTS;
            params->type_equation=QUADRATIC;
        }
    }
    else
    {
        if (disk < 0.0)
        {
            params->cntroots=NOROOTS;
            params->type_equation=INDIFINITE;

        }
        else
        {
            params->x1=(-b + sqrt(disk))/(2 * a);
            params->x2=(-b - sqrt(disk))/(2 * a);
            params->cntroots=TWOROOTS;
            params->type_equation=QUADRATIC;
            return;
        }
    }
}
void linear_solver(pick *params)
{
    double  b=params->b, c=params->c;
    if(compare(b,0))
    {
        if(compare(c,0))
        {
            params->cntroots=INFROOTS;
            params->type_equation=INDIFINITE;
        }
        else
            params->cntroots=NOROOTS;
            params->type_equation=INDIFINITE;
        }

    else
    {
        if(compare(c,0))
        {
            params->x1= 0;
            params->x2=0;
            params->cntroots=ONEROOT;
            params->type_equation=LINEAR;
        }
        else
        {
            params->x1=-c /b;
            params->x2=-c/b;
            params->cntroots=ONEROOT;
            params->type_equation=LINEAR;
        }
    }
}
void tester(pick *params)
{
    double x1_input = params->x1_input, x2_input = params->x2_input;
    double x1 = params->x1, x2 = params->x2;

    roots cntroots_input = params->cntroots_input;
    roots cntroots = params->cntroots;

    functiontype type_equation_input = params->type_equation_input;
    functiontype type_equation = params->type_equation;

    if (compare(type_equation_input,type_equation))
    {
        if(compare(cntroots_input,cntroots))
        {
            if ((compare(x1_input,x1) && compare(x2_input,x2))
                || (compare(x1_input,x2) && compare(x2_input,x1)) ) printf("Everyting is good\n");
            else printf("Roots are not the same\n");
        }
        else printf("Number of roots is not the same\n");
    }
    else printf("Type of equation is not the same\n");
}













