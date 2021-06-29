#include <cstdio>
#include <algorithm>
using namespace std;

int insertionSort(int A[], int N) {
    int min;
    int flag;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        flag = 0;
        min = i;
        for (int j = i+1; j < N; j++) {
            if (A[min] > A[j]) {
                min = j;
                flag = 1;
            }
        }
        swap(A[min], A[i]);
        if (flag == 1) count++;
    }
    
    return count;
}

int main(void){
    // Your code here!
    int N;
    scanf("%d", &N);
    int A[100];
    
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    int count = insertionSort(A, N);
    
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i == N-1) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }
    printf("%d\n", count);
}

