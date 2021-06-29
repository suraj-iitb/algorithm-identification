#include<vector>
#include<iostream>
#include <algorithm>
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
    rep(i,N) cin >> A.at(i);

    bool flag = true;
    int i = 0;
    int counter = 0;
    while(flag){
        flag = false;
        for(int j = N - 1; j >= i + 1;j--){
            if(A.at(j - 1) > A.at(j)){
                swap(A.at(j), A.at(j - 1));
                flag = true;
                counter++;
            }
        }
        i++;
    }
    output(A, N);
    cout << counter << endl;
}
