#include<stdio.h>

int binarySearch(int *S, int key, int left, int right){
    while(left != right){
        int mid = (left + right) / 2;
        if(S[mid] == key){
            return 1;
        }
        else if(key > S[mid]){
            left = mid+1;
        }
        else if(key < S[mid]){
            right = mid;
        }
    }
    return 0;
}

int main(void){
    int n, q, key, count = 0;
    scanf("%d",&n);
    int S[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d",&key);
        if(binarySearch(S, key, 0, n)){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
