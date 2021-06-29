#include<stdio.h>

int counter = 0;
void selectionSort(int* A, int N){
    for(int i=0; i<N; i++){
        bool flag = false;
        int min = i;
        for(int j=i; j<N; j++){
            if(A[j] < A[min]){
            min = j;
            flag = true;
            }
        }
        if(flag==true){
        int tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
        counter++;
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

    selectionSort(A, n);
    for(int i=0; i<n; i++){
        if(i!=n-1) printf("%d ", A[i]);
        if(i==n-1) printf("%d\n", A[i]);
    }
    printf("%d\n", counter);
    return 0;
}
