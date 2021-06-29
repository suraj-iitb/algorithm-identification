#include<stdio.h>

int binarySearch(int A[], int n, int key){
    int l, r, m;

    l = 0;
    r = n; 
    
    while(l < r){
        m = (l + r) / 2;
        if(A[m] == key) return 1;
        else if(key < A[m]){
            r = m;
        }else{
            l = m + 1;
        }
    }

    return 0;
}

int main(){
    int n, A[100000 + 1], q, key;
    int i, res = 0;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d", &key);
        res += binarySearch(A, n, key);
    }

    printf("%d\n", res);

    return 0;
}

