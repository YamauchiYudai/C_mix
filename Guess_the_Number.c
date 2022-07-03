// Guess_the_Number.c
// Author: Yamauchi Yudai, 2019

//数当てゲーム

#include <time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE 10

int main(void){
    int no;
    int ans;
    int i;
    int stage;
    int num[MAX_STAGE];

    srand(time(NULL));
    ans = rand() % 1000;

    printf("当てろ\n\n");
    stage = 0;
    do{
        printf("残り%d回 いくつだ? =",MAX_STAGE - stage);
        scanf("%d",&no);
        num[stage++] = no;

        if(no > ans)
            printf("\nもっと小さい\n");
        if(no < ans)
            printf("\nもっと大きい\n");
    }while(no != ans && stage < MAX_STAGE);

    if(no!=ans)
        printf("残念　正解は%d\n",ans);

    else
    {
        printf("正解めう\n");
        printf("%d回で正解しためう\n",stage);
    }
    puts("");

    return 0;
}