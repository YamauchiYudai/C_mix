#include<stdio.h>
#include<math.h>

// 二分法プログラム

int main(void){
    double a,b,c,e,f;
    int i;
    a = 2.0;b = 1.0;
    e = 5.0*pow(10.0,-6.0);
    i = 0;

    while((a-b) > e){
        c = (a+b)/2.0;
        
        f = exp(-c)-c*c;
        if(f>0){
            b = c;
        }
        else if(f<0){
            a = c;
        }
        else
        {
            break;
        }
        i++;
        printf("%d %.8f\n",i, c);
    }
    
    return 0;
}