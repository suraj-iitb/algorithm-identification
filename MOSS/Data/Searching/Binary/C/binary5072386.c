#include<stdio.h>

int A[1000000],h;

int haku(int kota){
    int l=0;
    int r=h;
    int m;
    while(l<r){
        m=(l+r)/2;
        if(kota==A[m])return 1;
        if(kota>A[m])l=m+1;
        else if(kota<A[m])r=m;
    }
    return 0;
}

int main(){
    int j,q,l,man=0;
    scanf("%d",&h);
    for(j=0;j<h;j++){
        scanf("%d",&A[j]);
    }
    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%d",&l);
        if(haku(l))man++;
    }
    printf("%d\n",man);
    return 0;
}

