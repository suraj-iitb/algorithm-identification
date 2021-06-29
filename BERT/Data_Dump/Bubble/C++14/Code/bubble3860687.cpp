#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> &A) {
    bool flag = true;
    int cnt = 0;
    while (flag) {
        flag = false;
        for (int j = A.size() - 1; j >= 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    int ret = bubbleSort(A);
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << ret << endl;

    return 0;
}

