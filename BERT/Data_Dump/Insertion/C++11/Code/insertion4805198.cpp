#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_N = 100;

int N;
int A[MAX_N];

void insertionSort(int A[], int N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    insertionSort(A, N);

    return 0;
}

void insertionSort(int A[], int N)
{
    for (int k = 0; k < N - 1; k++) {
        cout << A[k] << " ";
    }

    cout << A[N - 1] << "\n";

    for (int i = 1; i < N; i++) {

        int v = A[i];
        for (int j = i - 1; j >= 0; j--) {
            A[j + 1] = A[j];
            if (A[j] <= v) {
                A[j + 1] = v;
                break;
            }
            if (j == 0) {
                A[0] = v;
            }
        }
        for (int k = 0; k < N - 1; k++) {
            cout << A[k] << " ";
        }

        cout << A[N - 1] << "\n";
    }

    return;
}
