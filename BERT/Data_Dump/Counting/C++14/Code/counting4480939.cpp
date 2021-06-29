#include <iostream>
using namespace std;

#define N 2000001
#define V 10001

int main() {
    int n;
    cin >> n;

    int A[N], B[N];
    int C[V];

    for (int i = 0; i < V; i++) {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        C[A[i]]++;
    }


    for (int i = 1; i < V; i++) {
        C[i] += C[i-1];
    }

    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}
