#include<stdio.h>

int binarySearch(int, int[], int);

int main(){
    int n, q, S[100000], T[100000], i, j, left, right, mid, key, cnt=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    
    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%d",&T[j]);
    }
    
    for(j=0;j<q;j++){
        if(binarySearch(n, S, T[j]) == 1){
            cnt++;
        }
    }
    printf("%d\n",cnt);

    return 0;
}

int binarySearch(int n, int A[n], int key){
    int left = 0, right = n, mid;
    while(left < right){
        mid = (left + right) / 2;
        if(A[mid] == key){
            return 1;
        }
        else if(key < A[mid]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return 0;
}
