

//二分探索を用いた方程式の解法

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
    double ans = 2*pow(x,5)-8*pow(x,4)+20*pow(x,3)+50*pow(x,2)+150*x-400;
    return ans;
}

int main (void){
    double pr = 1000.0;
    double pl = -1000.0;
    double pc ;
    int i;
    while(i <= 100){
        pc = (pl+pr)/2;
        if(f(pc)<0){
            pl = pc; 
        }
        else{
            pr = pc;
        }
        printf("二分探索を%d回目\n",i);
        printf("x = %.16f y = %.16f\n",pc,f(pc));
        i += 1;
    }
    
    return 0;

}
