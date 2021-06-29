#include<stdio.h>

void showArray(int[], int);
void insertionSort(int[], int);


int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    showArray(A, n);

    insertionSort(A, n);

    return 0;
}

void showArray(int A[], int n){
    for(int i=0; i<n; i++){
        printf("%d", A[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
}

void insertionSort(int A[], int n){
    int v, j;
    for(int i=1; i<n; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        showArray(A, n);
    }
}

