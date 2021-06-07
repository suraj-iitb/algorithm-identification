#include <stdio.h>

int linearSearch(int *,int,int);

int main(){
    int S[10000],T[500];
    int n,q,i,count=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)    scanf("%d",&S[i]);

    scanf("%d",&q);

    for(i=0;i<q;i++) {
        scanf("%d",&T[i]);
        if(linearSearch(S,n,T[i])==1) count++;
    }

    printf("%d\n",count);

    return 0;
}

int linearSearch(int *S,int n,int key){
    int i;
    for(i=0;i<n;i++){
    if(S[i]==key) return 1;
    }
    return 0;
}

