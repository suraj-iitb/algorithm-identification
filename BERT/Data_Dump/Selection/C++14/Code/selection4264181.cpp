#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define V vector<int>
#define ll long long
using namespace std;

void selectionSort(V A, int N){
    int ans = 0;

    rep(i, 0, N){
        int minj = i;
        rep(j, i, N){
            if(A[j] < A[minj]){
                minj = j;
            }
        }

        swap(A[i], A[minj]);
        if(i != minj) ans++;
    }

    rep(i, 0, N){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl << ans << endl;
}

int main() {

    int n; cin >> n;
    V A(n);
    rep(i,0,n) cin >> A[i];
    
    selectionSort(A, n);

}

