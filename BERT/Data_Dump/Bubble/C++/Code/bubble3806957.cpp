#include<stdio.h>

int counter=0;

bool bubbleSort(int* A , int N){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=N-1; i>0; i--){
            if(A[i]<A[i-1]){
                int tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
                flag = true;
                counter++;
            }
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    bubbleSort(A, n);
    for(int i=0; i<n; i++){
        if(i!=n-1) printf("%d ", A[i]);
        if(i==n-1) printf("%d\n", A[i]);
    }
    printf("%d\n", counter);

    return 0;
}
