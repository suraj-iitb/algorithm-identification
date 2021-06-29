#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int N) {
    int sw = 0, temp;
    bool flag = true;

    while (flag) {
        flag = false;

        for (int i = 0; i < N-1; i++) {
            if (A[i] > A[i+1]) {
                flag = true;
                sw++;

                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
            }
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

    int sw = bubbleSort(A, N);
    for (int i = 0; i < N-1; i++) {
        cout << A[i] << ' ';
    }
    cout << A[N-1] << endl;
    cout << sw << endl;
    return 0;
}

