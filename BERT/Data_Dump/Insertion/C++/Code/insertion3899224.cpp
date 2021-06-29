#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin>>N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin>>A[i];

    for (int i=0;i<N;i++) {
        int v = A[i];
        int j = i - 1;
        while (j>=0 && A[j]>v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        for (int i=0;i<N;i++) {
            cout << A[i];
            if (i<N-1) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
