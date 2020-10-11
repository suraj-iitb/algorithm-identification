#include <stdio.h>

int ReadValue() {
    int n; 
    scanf("%d",&n);
    return n;
}
void ReadArray(int A[],int N) {
    int i; 
    for (i=0; i<N; i++) {
        scanf("%d",&A[i]);
    } 
}
void Display(int A[],int N) {
    int i;
    for (i=0; i<N; i++) {
        if (i>0) {
            printf(" ");
        }
        printf("%d",A[i]);
    }
    printf("\n"); 
}
void InsertionSort(int A[],int N) {
    int i;
    for (i=0; i<N; i++) {
        int v=A[i];
        int j=i-1;
        while (i>=0&&A[j]>v) {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        Display(A,N);
    }
}
int main() {
    int N=ReadValue();
    int A[N]; ReadArray(A,N);
    InsertionSort(A,N);
    return 0;
}

