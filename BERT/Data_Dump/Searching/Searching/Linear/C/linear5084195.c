#include<stdio.h>

int linearsearch(int);

int S[10000],n;

int main(){
    int q,T;
    int i,onazi,kei=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T);
        onazi=linearsearch(T);
        kei+=onazi;
    }
    printf("%d\n",kei);
    return 0;
}

int linearsearch(int x){
    int i=0;
    S[n]=x;
    while(S[i]!=x){
        i++;
        if(i==n)return 0;
    }
    return 1;
}

