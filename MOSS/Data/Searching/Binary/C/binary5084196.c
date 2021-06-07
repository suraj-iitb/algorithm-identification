#include<stdio.h>

int bainarysearch(int);

int S[100000];
int n;

int main(){
    int x,kei=0,onazi,q;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);;
    for(i=0;i<q;i++){
        scanf("%d",&x);
        onazi=bainarysearch(x);
        kei+=onazi;
    }
    printf("%d\n",kei);
    return 0;
}

int bainarysearch(int x){
    int left=0,right=n,mid;
    while(left<right){
        mid=(left+right)/2;
        if(S[mid]==x)return 1;
        else if(S[mid]<x)left=mid+1;
        else if(x<S[mid])right=mid;
    }
    return 0;
}
