#include <bits/stdc++.h>
using namespace std;

void print(vector<int> A) {
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i] << ((i+1==(int)A.size())?"\n":" ");
    }
}

int selectingsort(vector<int> &A, int N) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int mn = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[mn]) mn = j;
        }
        swap(A[i], A[mn]);
        if (A[i] != A[mn]) ret++;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = selectingsort(A, N);
    print(A);
    cout << ans << endl;
    return 0;
}
