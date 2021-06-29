

#include <iostream>

using namespace std;



static int A[1000];
int main() {
    int n=0;
    cin >> n;
    //int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int k = 0; k < n - 1; k++) {
        cout << A[k] << " ";
    }
    cout << A[n - 1] << "\n";
    int v, j;
    for (int i = 1; i < n; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 and A[j] > v) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
        for (int k = 0; k < n-1; k++) {
            cout << A[k] << " ";
        }
        cout << A[n - 1] << "\n";
    }

}


