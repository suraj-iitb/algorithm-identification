#include <stdio.h>

void print_array(int A[], int N) {
    for (int i=0;i<N;i++) {
        printf("%d%c",A[i],i==N-1?'\n':' ');
    }
}

void insert_sort(int A[], int N) {
        print_array(A, N);
    for (int i=1;i<N;i++) {
        int j=i-1;
        int key=A[i];
        while (j>=0 && A[j]>key) {
           A[j+1]=A[j];
          j--;
        }
       A[j+1]=key;
    print_array(A, N);
    }
} 

int main() {
    int N, A[100+1];
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }
    insert_sort(A,N);
    return 0;
}

