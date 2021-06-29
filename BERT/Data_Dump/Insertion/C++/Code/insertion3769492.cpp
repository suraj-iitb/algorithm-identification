#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    std::vector<int> A(n);
    int a;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
        cout << A[0];
        for (int i = 1; i < n; i++) {
            cout << ' ' << A[i];
        }
        cout << endl;
    
    for (int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        cout << A[0];
        for (int i = 1; i < n; i++) {
            cout << ' ' << A[i];
        }
        cout << endl;
    }
}
