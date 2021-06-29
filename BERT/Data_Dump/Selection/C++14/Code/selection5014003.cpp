#include<bits/stdc++.h>

using namespace std;

// 選択ソート
void selectionSort(vector<long long> &A, int N) {
    int min_j;
    int count = 0;

    for (int i = 0; i < N; i++) {
        min_j = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[min_j]) {
                min_j = j;
            }
        }

        if (i != min_j) {
            count++;
        }
        swap(A[i], A[min_j]);
    }

    for (int i = 0; i < N; i++) {
        if (i == N-1) {
            cout << A[i];
            continue;
        }
        cout << A[i] << " ";
    }
    cout << endl;

    cout << count << endl;
}

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    selectionSort(A, N);
    return 0;
}
