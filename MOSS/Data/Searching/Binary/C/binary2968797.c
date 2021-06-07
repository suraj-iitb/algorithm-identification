#include <stdio.h>
#define NOT_FOUND -1
#define MAX 100000

int binarySearch(int[],int);

int n;

int main(){
    int q,count = 0;
    int S[MAX],T[MAX];

    scanf("%d",&n);
    for(int i = 0;i < n;i++)scanf("%d",&S[i]);

    scanf("%d",&q);
    for(int i = 0;i < q;i++)scanf("%d",&T[i]);

    for(int i = 0;i < q;i++)if(binarySearch(S,T[i]) >= 0)count++;

    printf("%d\n",count);

    return 0;
}

int binarySearch(int A[n],int key){
    int left = 0,mid,right = n;

    while(left < right){
        mid = (left + right) / 2;
        if(A[mid] == key)return mid;
        else if(key < A[mid])right = mid;
        else left = mid + 1;
    }

    return NOT_FOUND;
}
