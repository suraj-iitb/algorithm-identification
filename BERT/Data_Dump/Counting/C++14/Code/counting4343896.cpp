#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const int INF = +100100100;
typedef pair<char,int> P;


const int VAL = 30000;

vector<int> countingSort(vector<int> &A, int k){
    vector<int> C(k+10,0), B(A.size()+10);
    rep(i,A.size()-1){
        ++C[A[i+1]];
    }
    rrep(i,k){
        C[i] += C[i-1];
    }
    for(int i = A.size()-1;i>=1;--i){
        B[C[A[i]]] = A[i];
        --C[A[i]];
    }
    return B;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n+1,0);
    rrep(i,n)cin >> A[i];
    vector<int> B = countingSort(A,VAL);
    rrep(i,n){
        if(i!=1)cout << " " << B[i];
        else cout << B[i];
    }
    
    cout << endl;
    return 0;
}
