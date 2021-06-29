#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define V vector<int>
using namespace std;
// using ll = long long;

void bubbleSort(V A, int n){
    int flag = 1;
    int ans = 0;
    for(int i = 0; flag; i++) {
        flag = 0;
        for(int j = n-1; j >= i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                ans++;
            }
        }
    }
    rep(i, 0, n){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl << ans << endl;
}

int main() {

    int n; cin >> n;
    V A(n);
    rep(i,0,n) cin >> A[i];
    
    bubbleSort(A, n);

}

