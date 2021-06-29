#include <stdio.h>

#define N 10000
#define Q 500

int search(int*,int,int);

int main(){
    int i,n,q;
    int cnt=0;
    int S[N],T[Q];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }

    for(i=0;i<q;i++){
        cnt += search(S,T[i],n);
    }

    printf("%d\n",cnt);
    return 0;
}

int search(int *temp,int key,int n){
    int i;

    for(i=0;i<n;i++){
        if(temp[i] == key) return 1;
    } 
    return 0;
}

