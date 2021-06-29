#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define V vector<int>
using namespace std;
using ll = long long;

void insertionSort(vector<int> A,int N){
    int j, i, v;
    rep(i, 1, N){
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        rep(k, 0, N-1) cout << A[k] << " ";
        cout << A[N-1] << endl;
    }
    return;
}

int main() {
    int n; cin >> n;
    V v(n);
    rep(i, 0, n) cin >> v[i];
    rep(i, 0, n-1) cout << v[i] << " ";
    cout << v[n-1] << endl;
    insertionSort(v, n);
}

