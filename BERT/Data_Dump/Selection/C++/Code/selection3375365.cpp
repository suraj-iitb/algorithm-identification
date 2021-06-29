#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i< n; i++) {
        cin >> A.at(i);
    }
    for(int i = 0; i < n; i++) {
        int note = i;
        for(int j = i; j < n; j++) {
            if(A.at(j) < A.at(note)) 
                note = j;
        }
        if(i != note) {
            swap(A.at(i), A.at(note));
            ans++;
          
        }
    }
    for(int i = 0; i < n; i++) {
        cout << A.at(i);
        if(i != n-1)cout << " ";
    }
    cout << endl << ans << endl;
}
