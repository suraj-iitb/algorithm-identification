// 2019-04-09
// Accepted
// 00:00 sec

#include <cstdio>
#include <algorithm>
using namespace std;

int bubbleSort(int A[], int n);
void Print(int A[], int n, int cnt);


int main() {
    int N;
    int A[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int cnt = bubbleSort(A, N);
    Print(A, N, cnt);
}


void Print(int A[], int n, int cnt) {
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
}

int bubbleSort(int A[], int n) {
    int cnt = 0, i = 0;
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                flag = 1;
                cnt++;
            }
        }
        i++;
    }

    return cnt;
}

