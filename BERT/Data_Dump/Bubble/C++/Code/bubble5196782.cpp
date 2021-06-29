#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int>& A) {
    int N = A.size();
    int cnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j=N-1; j>0; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                flag = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A[i];
    
    int cnt = bubbleSort(A);
    for (int i=0; i<N; i++) {
        cout << A[i];
        if (i<N-1) cout << ' '; else cout << endl;
    }
    cout << cnt << endl;
    return 0;
}

