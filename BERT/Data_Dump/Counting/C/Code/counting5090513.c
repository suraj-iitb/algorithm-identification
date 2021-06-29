#include<stdio.h>
#include<stdlib.h>
#define M 2000001
#define A 10000

int main(){
    unsigned short *W,*K;
    int G[A+1];
    int h,i,j;
    scanf("%d",&h);
    W=malloc(sizeof(short) * h+1);
    K=malloc(sizeof(short) * h+1);
    for(i=0;i<=A;i++) G[i]=0;
    for(i=0;i<h;i++){
        scanf("%hu",&W[i+1]);
        G[W[i+1]]++;
    }
    for(i=1;i<=A;i++) G[i]=G[i]+G[i-1];
    for(j=1;j<=h;j++){
        K[G[W[j]]]=W[j];
        G[W[j]]--;
    }
    for(i=1;i<=h;i++){
        if(i>1) printf(" ");
        printf("%d",K[i]);
    }
    printf("\n");
    return 0;
}
