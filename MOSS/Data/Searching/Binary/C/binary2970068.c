#include <stdio.h>
#define FOUND 1
#define NOT_FOUND 0
#define MAX 100000
#define max 50000

int n;
int binarySearch(int *,int);

int main(){

    int S[MAX],T[max],q,count,i;

    scanf("%d",&n);
    for( i = 0; i < n; i++) scanf("%d",&S[i]);
    scanf("%d",&q);
    for( i = 0; i < q; i++){
        scanf("%d",&T[i]);
        if(binarySearch(S,T[i]) == FOUND) count++;
    }

        printf("%d\n",count);
        return 0;
}

int binarySearch(int *A,int key){

    int Left = 0,Right = n,mid;

    while( Left < Right ){
        mid = ( Left + Right ) / 2;
        if(A[mid] == key) return FOUND;
        else if(key < A[mid]) Right = mid;
        else Left = mid + 1;
    }

    return NOT_FOUND;
}
