#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    bool c = true;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A.at(i);
    }
    while(c) {
        c = false;
        for(int i = 0; i < n-1; i++) {
           if(A.at(i) > A.at(i+1)) {
               swap(A.at(i), A.at(i+1));
               c = true;
               ans++;
           }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << A.at(i);
        if(i != n-1) cout << " ";
    }
    cout << endl <<  ans << endl;
}
