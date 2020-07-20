#include <iostream>
#include <string>
using namespace std;
int main() {
    int n; cin >> n;
    int A[100];
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }

    int cnt = 0;
    for (int i=1; i<n; ++i) {
        for (int j=n-1; j>=1; --j) {
            if (A[j-1] > A[j]) {
                swap(A[j-1], A[j]);
                cnt ++;
            }
        }
    }

    for (int i=0; i<n; ++i) {
        if (i==0)
            cout << A[i];
        else
            cout << " " << A[i];
    }
    cout << "\n";
    cout << cnt << "\n";

    return 0;
}
