#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A.at(i);
    }
    for(int i = 1; i <= n; i++){
        sort(A.begin(), A.begin() + i);
        for(int j= 0; j< n-1;j++) cout << A.at(j)<< " ";
        cout << A.at(n-1) <<  endl;
    }
}
