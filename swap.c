#include<stdio.h>

typedef struct ex 
{   int n;
    char c; 
} ex_t;

void swap_st( ex_t *x, ex_t *y )
{
    ex_t z = *x;
    *x = *y;
    *y = z;
}

int main( void ) 
{   ex_t a, b;

    printf("Please enter a : namber and character\n");
    scanf("%d%s",&a.n,&a.c);
    printf("Please enter b : namber and character\n");
    scanf("%d%s",&b.n,&b.c);

    swap_st(&a,&b);

    printf("a=% d and %c\n",a.n,a.c);
    printf("b= %d and %c\n",b.n,b.c);

    return 0;
}