#include <iostream>
using namespace std;


int main() {
    int n;
    int t, sw = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int j = 0; j < n-1; j++) {
        int minj = j;
        for (int k = j; k < n; k++) {
            if (A[k] < A[minj]) minj = k;
        }
        if(j != minj){
            t = A[j];
            A[j] = A[minj];
            A[minj] = t;
            sw++;
        }
    }
    for (int k = 0; k < n; ++k) {
        if (k) cout << " ";
        cout << A[k];
    }
    cout << "\n";
    cout << sw << "\n";
    return 0;
}

