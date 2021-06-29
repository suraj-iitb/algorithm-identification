#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    int num = 0;
    for (int i = 0; i < N; i++) {
        int jmin = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[jmin]) jmin = j;
        }
        if (i != jmin) {
            swap(A[i],A[jmin]);
            num++;
        }
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl << num << endl;
}

