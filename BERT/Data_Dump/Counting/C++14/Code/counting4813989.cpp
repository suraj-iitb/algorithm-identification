#include <iostream>

using namespace std;

const int MAXNUM = 2000001;
const int MAXK = 10000;

int main()
{
    unsigned short* A, * B;
    int C[MAXK + 1];
    int n, i, j;

    cin >> n;

    A = (unsigned short*)malloc(sizeof(short) * n + 1);
    B = (unsigned short*)malloc(sizeof(short) * n + 1);

    for (int i = 0; i <= MAXK; i++) C[i] = 0;

    for (int j = 0; j < n; j++) {
        cin >> A[j+1];
        C[A[j+1]]++;
    }

    for (int i = 1; i <= MAXK; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = 1; j <= n; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
}
