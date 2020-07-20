#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int N) {
    bool flag = 1;
    int count = 0;
    while(flag) {
        flag = 0;
        for(int i = N - 1; i > 0; i--) {
            if(A[i] < A[i - 1]) {
                swap(A[i], A[i - 1]);
                count++;
                flag = 1;
            }
        }
    }
    return count;
}

int main() {
    int A[100], N, count;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    count = bubbleSort(A, N);

    for(int i = 0; i < N; i++) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
