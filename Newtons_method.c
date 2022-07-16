#include<stdio.h>
#include<math.h>

int main(void){
    double  a,b,c,f,x,x0,h,df1,f1,d0,d1;
    int i;

    a = 0.0;
    b = 5.0;

    x0 = 2.5;

    h = 0.1;
    d0 = 2.5;

    for (i = 1;i<=10;i++){
        c = (a+b)/2.0;
        f = atan(c-1.0)+0.2*c;
        if(f>0){
            b = c;
        }
        else if(f<0){
            a = c;
        }

        x = x0 - (atan(x0-1.0)+0.2*x0)/(1.0/(1.0+(x0-1.0)*(x0-1.0))+0.2);
        x0 = x;

        f1 = (atan(d0-1.0)+0.2*d0);
        df1 = (atan(d0+h-1.0)+0.2*(d0+h)-(atan(d0-1.0)+0.2*d0))/h;

        d1 = (d0 - f1/df1);
        d0 = d1;

        printf("%2d %20.15f %20.15f %20.15f \n", i, c,x,d1);

    }

    return 0;
}