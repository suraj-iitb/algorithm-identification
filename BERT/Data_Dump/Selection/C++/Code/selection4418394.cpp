#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
    }

    int counter = 0;
    rep(i, N){
        int minj = i;
        for (int j = i + 1; j <= N - 1 ; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if (i != minj){
            swap(A[i], A[minj]);
            counter++;
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
}
