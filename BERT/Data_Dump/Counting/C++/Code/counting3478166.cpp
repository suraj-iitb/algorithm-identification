#include <iostream>
using namespace std;
#include <cstdio>

const int k = 10000;

void countingsort(int A[], int B[], int n){
    int C[k+1];
    for(int i=0; i<k+1; i++){
        C[i] = 0;
    }

    for(int i=0; i<n; i++){
        C[A[i]]++;
    }
    for(int i=1; i<k+1; i++){C[i] += C[i-1];}
    for(int i=n-1; i>=0; i--){
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    int A[n], B[n];
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    countingsort(A, B, n);

    for(i=0; i<n-1; i++){
        printf("%d ", B[i]);
    }
    printf("%d\n", B[i]);

    return 0;
}
