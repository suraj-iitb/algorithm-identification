#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N) {
    int sw = 0, temp;

    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i+1; j < N; j++) {
            if (A[minj] > A[j]) {
                minj = j;
            }
        }

        if (i != minj) {
            sw++;
            temp = A[minj];
            A[minj] = A[i];
            A[i] = temp;
        }

    }

    return sw;   
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int sw = selectionSort(A, N);
    for (int i = 0; i < N-1; i++) {
        cout << A[i] << ' ';
    }
    cout << A[N-1] << endl;
    cout << sw << endl;

    return 0;
}

