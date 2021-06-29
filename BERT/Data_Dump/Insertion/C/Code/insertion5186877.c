#include <stdio.h>
void insertionSort(int A[], int n){
    for(int i =0; i<n; i++){
        int j = i-1;
        int x = A[i];
        while (A[j]>x && j>-1){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
        printf("%d",A[0]);
        for (int k=1;k<n;k++){
            printf(" %d",A[k]);
        }
        if (i<n){
            printf("\n");
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int B[n];
    for (int i=0;i<n;i++){
        scanf("%d",&B[i]);
    }
    insertionSort(B,n);
}

