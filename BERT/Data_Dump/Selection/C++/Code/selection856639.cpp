#include <iostream>
#include <string>
using namespace std;
int main() {
    int n; cin >> n;
    int A[100];
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }

    int num = 0;
    for (int i=0; i<n-1; ++i) {
        int mini = i;
        for (int j=i+1; j<n; ++j) {
            if (A[mini] > A[j]) {
                mini = j;
            }
        }
        if (mini != i) {
            swap(A[i], A[mini]);
            num ++;
        }
    }

    for (int i=0; i<n; ++i) {
        if (i == 0)
            cout << A[i];
        else 
            cout << " " << A[i];
    }
    cout << "\n";
    cout << num << "\n";

    return 0;
}
