#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

void print(int N, vector<int> A){
    rep(i,N-1){
        cout << A[i] << " ";
    }
    cout << A[N-1];
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    rep(i,N){
        int v = A[i];
        int j = i -1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        print(N,A);
    }
    return 0;
}
