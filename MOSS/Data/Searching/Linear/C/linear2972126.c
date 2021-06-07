#include <stdio.h>
#define MAX 10000
#define NOT_FOUND -1

int linearSearch(int[],int);

int n;

int main(){
    int q,count = 0;
    int S[MAX],T[MAX];

    scanf("%d",&n);
    for(int i = 0;i < n;i++)scanf("%d",&S[i]);

    scanf("%d",&q);
    for(int i = 0;i < q;i++)scanf("%d",&T[i]);

    for(int i = 0;i < q;i++)if(linearSearch(S,T[i]) >= 0)count++;

    printf("%d\n",count);

    return 0;
}

int linearSearch(int A[n],int key){
    int i = 0;
    A[n] = key;
    while(A[i] != key){
        i++;
    }
    if(i == n)return NOT_FOUND;
    return i;
}
