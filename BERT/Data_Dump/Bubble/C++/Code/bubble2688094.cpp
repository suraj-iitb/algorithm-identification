#include <cstdio>
#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    int count = 0;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = n - 1; 0 < i; i--) {
            if (a[i] < a[i-1]) {
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                count++;
                flag = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i == n-1) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }
    printf("%d\n", count);
}

int main(void){
    // Your code here!
    int N;
    scanf("%d", &N);
    int A[100];
    
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    bubbleSort(A, N);
    
}

