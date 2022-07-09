

// バブルソート、シェルソート、クイックソートをCで実装したもの
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, p, q)  do { type t = p; p = q; q = t; } while (0)

void Sort( int a[], int n )
{
  int i,j,c;

  for (i = 0;i< n-1;i++){
    for(j = 0;j < n-1-i ;j++ ){
      if(a[j+1]<a[j]){
        c = a[j];
        a[j] = a[j+1];
        a[j+1] = c;
      }
    }
  }
}

void shell(int a[],int a_size)
{
    int i,j,k;
    int g;
    for(i = a_size/2 ; i > 0 ; i = i/2) {
        for(j = i ; j<a_size ; j++){
            for(k = j-i ; k >= 0 && a[k] > a[k+i] ; k = k-i){
                g = a[k];
                a[k] = a[k+i];
                a[k+i] = g;
            }
            
        }
    }
}

void quick(int a[], int left, int right)
{
	int pl = left;			
	int pr = right;				
	int z = a[(left+right+1)/2] ;	
	int i;
	
	
	while (pl<=pr) {
		while (a[pl] < z){
      pl++;
    }
		while (a[pr] > z) {
      pr--;
    }
		if (pl<=pr){
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	}
		
	
	if (right!=pr)  quick(a, left, pr); 
	
	if (pl!= left) quick(a, pl, right); 
}

int main(void)
{
    int i, nx,j;
    double trial;
    int *x,*y,*z;
    clock_t bubble_start,bubble_end,shell_start,shell_end,quick_start,quick_end;

    double bubble_sum =0.0,shell_sum = 0.0,quick_sum = 0.0;

    printf("要素数：");
    scanf("%d", &nx);
    printf("試行回数：");
    scanf("%lf", &trial);
    for(j = 1; j<=trial;j++){
      x = calloc(nx, sizeof(int));
          
      srand((unsigned int)time(NULL));

      printf("ソート準備\n");

      for(i=0; i < nx; i++){
              x[i]=rand()%100 + 1;
              /*printf("%d ", x[i]);*/
      }
      int d = x[0];

      y = calloc(nx, sizeof(int));

      for(i=0;i<nx;i++){
      y[i]=x[i];
    }
      printf("\n");

      z = calloc(nx, sizeof(int));

      for(i=0;i<nx;i++){
      z[i]=x[i];
    }
      printf("\n");

      puts("バブルソート");


      bubble_start = clock();
      Sort(x, nx);
      bubble_end = clock();
      puts("昇順にソートしました。");

      // for(i=0; i < nx; i++)
      //     printf("%d ", x[i]);

      free(x);
      printf("\n");

      puts("\nシェルソート");
    
      shell_start = clock();
      shell(y,nx);
      shell_end = clock();
      
      puts("昇順にソートしました。");  
      // for (i = 0; i < nx; i++)
      // printf("%d ", y[i]);

      free(y);  
      printf("\n");

      puts("\nクイックソート");
    
      quick_start = clock();
      quick(z, 0, nx - 1);
      quick_end = clock();
      
      puts("昇順にソートしました。");
      // for (i = 0; i < nx; i++)
      // printf("%d ", z[i]);

      free(z);

      printf("\nバブルソートは%f秒かかりました",(double)(bubble_end-bubble_start)/CLOCKS_PER_SEC);
      printf("\nシェルソートは%f秒かかりました",(double)(shell_end-shell_start)/CLOCKS_PER_SEC);
      printf("\nクイックソートは%f秒かかりました",(double)(quick_end-quick_start)/CLOCKS_PER_SEC);
      printf("\n");
      bubble_sum = bubble_sum + (double)(bubble_end-bubble_start)/CLOCKS_PER_SEC;
      shell_sum = shell_sum + (double)(shell_end-shell_start)/CLOCKS_PER_SEC;
      quick_sum = quick_sum + (double)(quick_end-quick_start)/CLOCKS_PER_SEC;
    }

    puts("-----平均-----");
    printf("\nバブルソートは平均%f秒かかりました",(double)(bubble_sum/trial));
    printf("\nシェルソートは平均%f秒かかりました",(double)(shell_sum/trial));
    printf("\nクイックソートは平均%f秒かかりました",(double)(quick_sum/trial));

    return 0;

}