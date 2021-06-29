#include <stdio.h>


int binary_search(int A[], int right, int left, int key){
    while(left < right){
        int mid = (left + right) / 2;
        if(A[mid]==key) return mid;
        else if(A[mid] > key) right=mid;
        else left=mid+1;
    }

    return 0;
}

int main(){
    int n, q, i, j, cnt=0;
    scanf("%d", &n);
    int S[n];
    for(i = 0; i< n; i++) scanf("%d", &S[i]);

    scanf("%d", &q);
    int T[q];


    for(i = 0; i< q; i++){
        scanf("%d", &T[i]);
        if(binary_search(S, n, 0, T[i]) != 0){
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}

