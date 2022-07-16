#include <stdio.h>
#include <math.h> 

#define N_0 2000
#define T 8
// 半減期 8 日でキセノン 131 に変化するヨウ素 131の半減期を解析解と
// オイラー法、ホイン法、ルンゲ・クッタ法で数値解析し数値解と誤差を導出するプログラム

int main (void){
    int j;
    double h,t,y0,y,y1,y2,y3,y4,k1,k2,k3,k4,e2,e3,e4;

    h = 0.2;
    y1 = 2000;y2 = 2000;y3 = 2000;y4 = 2000;

    e2 = fabs(y1 - y2);
    e3 = fabs(y1 - y3);
    e4 = fabs(y1 - y4);
    printf("%5f %10.5f %10.5f %10.5f %10.5f %12.3e %12.3e %12.3e\n",0.0,y1,y2,y3,y4,e2,e3,e4);

    for(j=1;j<=80;j++){
        t=h*(double)j;
    
        // analytic
        y1 = N_0*pow((0.5),(t/T));

        // Euler
        k1 = -log(2)*y2/8;
        y2 = k1*h+y2;

        // Horn
        k1 = -log(2)*y3/8;
        y = k1*h + y3;
        k2 = -log(2)*y/8;
        y3 = (k1+k2)/2.0 * h + y3; 
        
        // Runge-Kutta
        k1 = -log(2)*y4/8 ;
        y = k1*h/2.0 + y4 ; 
        k2 = -log(2)*y/8 ;
        y = k2*h/2.0 +y4 ; 
        k3 = -log(2)*y/8 ;
        y = k3*h + y4 ;
        k4 = -log(2)*y/8 ;
        y4 = (k1+2.0*k2+2.0*k3+k4)/6.0*h+y4 ;

        e2 = fabs(y1-y2);
        e3 = fabs(y1-y3);
        e4 = fabs(y1-y4);
        printf("%5f %10.5f %10.5f %10.5f %10.5f %12.3e %12.3e %12.3e\n",t,y1,y2,y3,y4,e2,e3,e4);
    }
    return 0;
}