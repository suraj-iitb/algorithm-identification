#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;


int main(){
    int n; cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    rep(i, n){
        int key = A[i];
        int j = i - 1;
        while (j >= 0 and A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        rep(i, n){
            cout << A[i];
            if (i<n-1) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}
