#include <stdio.h>
#include<algorithm>

using namespace std;
static const int N = 100;

void print(int A[], int n) {
    for(int i = 0; i < n; i++) {
        if(i) printf(" ");
        printf("%d", A[i]);
    }
}

int bubbleSort(int A[], int n) {
    int i,j, num = 0;
    for(i = 0; i < n; i++) {
        for(j = n-1; j >= i+1; j--) {
            if(A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                num++;
            }

        }
    }
    return num;
}


int main() {
    int n, A[N+1];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int num = bubbleSort(A, n);
    print(A, n);
    printf("\n%d\n", num);
    return 0;
}
