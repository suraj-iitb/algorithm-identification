#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A.at(i);
    }
    bool flag = 1;
    int count = 0;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = n-1; j >= i+1; j--) {
            if(A.at(j) < A.at(j-1)) {
                swap(A.at(j), A.at(j-1));
                flag = 1;
                count++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << A.at(i);
        if(i == n-1) cout << endl;
        else cout << " ";
    }
    cout << count << endl;
}
