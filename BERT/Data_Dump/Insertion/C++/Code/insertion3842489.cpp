#include<iostream>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

void output(vector<int> B, int s) {
    rep(i, s - 1) cout << B.at(i) << " ";
    cout << B.at(s - 1) << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);
    output(A, N);
    for(int i = 1; i <= N - 1; i++){
        int v = A.at(i);
        int j = i - 1;
        
        while(j >= 0 && A.at(j) > v){
            A.at(j + 1) = A.at(j);
            j--;
        }
        A.at(j + 1) = v;
        output(A, N);
    }
}
