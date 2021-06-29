#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int selectionSort(vector<int> &a, int n) {
    int count=0;
    for(int i=0; i<n; ++i) {
        int minj=i;
        for(int j=i; j<n; ++j) {
            if(a[j] < a[minj]) minj = j;
        }
        int v = a[i];
        a[i] = a[minj];
        a[minj] = v;
        if(i!=minj) ++count;
        }
    return count;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int c = selectionSort(A, N);
    rep(i,N) if(i==N-1) cout << A[i] << endl; else cout << A[i] << " ";
    cout << c << endl; 
    return 0;
}
