 #include <cstdio>
#include <algorithm>
using namespace std;
static const int Size = 100;


void Print(int A[], int N, int cnt);
int selectionSort(int A[], int N);


int main() {
    int N;
    int A[Size];
    scanf("%d", &N);
    for (int i = 0 ; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int sw;
    sw = selectionSort(A, N);

    Print(A, N, sw);

}


int selectionSort(int A[], int N) {
    int cnt = 0;
    int minj;
    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }

    return cnt;
}

void Print(int A[], int N, int cnt) {
    for (int i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
}


