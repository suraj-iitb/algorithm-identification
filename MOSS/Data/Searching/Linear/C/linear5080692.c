#include <stdio.h>

#define N 10000
#define Q 500

int q,n,T[Q],S[N];

int linearSearch(int);

int main(){
    int x,k=0,i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
       scanf(" %d",&S[i]);
    } 
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }
    for(i=0;i<q;i++){
        if(linearSearch(T[i])!=-1){
            S[linearSearch(T[i])]=-1;
            k++;
        }
    }
    printf("%d\n",k);
    return 0;
}

int linearSearch(int x){
    int i;
    for(i=0;i<n;i++){
        if(x==S[i]) return i;
    }
    return -1;
}
