#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
    }

    int flag = 1;
    int counter = 0;

    while(flag){
        flag = 0;
        for (int i = N - 1; i >= 1 ; i--){
            if (A[i] < A[i - 1]){
                int a = A[i];
                A[i] = A[i - 1];
                A[i - 1] = a;
                counter++;
                flag = 1;
            }
        }
    }

    rep(i, N){
        if (i == N - 1){
            cout << A[N - 1] << endl;
        } else {
            cout << A[i] << " ";
        }
    }

    cout << counter << endl;
    return 0;
}
