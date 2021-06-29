#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define RES REP(k, n){cout << A[k]; k != n-1 ? cout << " " : cout << endl;}
using namespace std;
typedef vector<int> vi;

void insertionSort(vi &A, size_t n){
    RES
    FOR(i, 1, n) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;}
        A[j+1] = v;
        RES}
}

int main(){
    int n; cin >> n;
    vi A(n);
    REP(i, n) cin >> A[i];
    insertionSort(A, n);
}
