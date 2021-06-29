#include <stdio.h>

int S[100000],x;
int bi(int );

int main(){
    int i,a,b,sum;
    
    scanf("%d",&x);
    for(i=0;i<x;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&a);
    sum = 0;
    for(i=0;i<a;i++){
        scanf("%d",&b);
        if(bi(b)) sum++;
    }
    printf("%d\n",sum);
    
    return 0;
    
}

int  bi(int f){
    int l = 0;
    int r = x;
    int cen;
    while(l<r){
        cen = (l + r) / 2;
        if(f == S[cen]) return 1;
        if(f > S[cen]) l = cen+1;
        else if(f < S[cen]) r = cen;
    }
    return 0;
}

