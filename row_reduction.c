#include <stdio.h>

#define N 3

void Gauss(double a[N][N],double b[N],double x[N]){
    int i, j, k;
    double alpha, bi;

    printf("\n** Extended Coefficient Matrix **\n"); 
    printf("Ab=\n");

    for(i=0; i<N; i++)
    { printf(" |");
        for (j=0; j<N; j++){
            printf("%8.3f ", a[i][j]);
        }
        printf(" || %8.3f |\n", b[i]);
    }
    for(k=0; k<N-1; k++){
        for(i=k+1; i<N; i++){
            alpha = a[i][k]/a[k][k];
            for(j=k; j<N; j++){
                a[i][j] -= alpha * a[k][j];
            }
            b[i] -= alpha * b[k];
        }
    }

    printf("\n** Forward Elimination **\n"); 
    printf("Ab=\n");

    for(i=0; i<N; i++){
        printf(" |");
        for (j=0; j<N; j++){
            printf("%8.3f ", a[i][j]);
        }
        printf(" || %8.3f |\n", b[i]);
    }

    for(i = N-1; i>=0; i--){
        bi=b[i];
        for (k = i+1; k < N; k++ ){
            bi-=a[i][k]*x[k];
        }
        x[ i ] = bi / a[ i ][ i ] ;
    }

    printf("\n** Solution **\n"); printf("x=\n");
    for (j=0; j<N; j++){
        printf(" | %8.3f | \n", x[j]);
    }
    printf("\n");

}

int main(void){

    double a_first[N][N] ={{5,6,-3},{2,2,1},{1,1,-1}};
    double b_first[N] = {-8,0,-3};
    double x_first[N] ={0.0,0.0,0.0};

    Gauss(a_first,b_first,x_first);

    double a_next[N][N] ={{1,1,-1},{2,2,1},{5,6,-3}};
    double b_next[N] = {-3,0,-8};
    double x_next[N] ={0.0,0.0,0.0};

    Gauss(a_next,b_next,x_next);

    return 0;
}

