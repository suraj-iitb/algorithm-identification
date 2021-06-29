#include <stdio.h>
#define NotFound 0
#define Found 1

int binarySearch(int n,int A[1000000],int key){
    int left = 0;
    int right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if(A[mid] == key)
            return Found;
        else if(key < A[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return NotFound;
}

int main(){
    int i,j,n,q,S[1000000],T[1000000],C=0; 

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d", &T[i]);
    }

    for(j=0;j<q;j++){
        if(binarySearch(n,S,T[j])==Found)C++;
        else continue;
    }
    printf("%d\n",C);

    return 0;
}
