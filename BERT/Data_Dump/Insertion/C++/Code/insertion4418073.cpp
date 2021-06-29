#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> A(n);
    rep(i, n){
        cin >> A[i];
    }

    for(int k = 0; k < n; k++){
            if (k == n - 1){
                cout << A[n-1] << endl;
            } else {
                cout << A[k] << " ";
            }
    }

    for (int i = 1; i < n; i++){
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
            A[j + 1] = v;
        }

        for(int k = 0; k < n; k++){
            if (k == n - 1){
                cout << A[n-1] << endl;
            } else {
                cout << A[k] << " ";
            }
        }
    }
}
