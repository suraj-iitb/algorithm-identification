#include<stdio.h>
#include<iostream>
using namespace std;

int bubble(int A[], int n) {
    int flag = 1;
    int count = 0;
    while(flag) {
        flag = 0;
        for (int i = n - 1; i > 0; i--) {
            if (A[i] < A[i-1]) {
                swap(A[i], A[i-1]);
                count++;
                flag = 1;
            }
        }
    }
    return count;
}

int main() {
    int n, count;
    int A[100];
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    count = bubble(A, n);
    for (int i = 0; i < n; i++) {
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    cout << endl;
    printf("%d\n", count);
    
    return 0;
}
