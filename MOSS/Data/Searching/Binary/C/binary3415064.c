#include <stdio.h>

int binarysearch(int A[], int n, int key){
    int left = 0, right = n, mid = n/2;
    while(A[mid] != key){
        if(right == left + 1) return 0;
        if(A[mid] > key){
            right = mid;
            mid = (left + right) / 2;
        }else{
            left = mid;
            mid = (left + right) / 2;
        }
    }
    return 1;
}

int main(){
    int i, n, S[100000+1], q, key, sum = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &key);
        if(binarysearch(S, n, key)) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
