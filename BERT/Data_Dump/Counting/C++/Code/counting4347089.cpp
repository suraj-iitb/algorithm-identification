#include <iostream>
#include <cstdlib>

#define MAX 10000

using namespace std;

int main() {
    int n;
    long long C[100001], A[2000001], B[2000001];
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        C[A[i]]++;
    }
    for (int i = 1; i <= MAX; i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    for (int i = 1; i <=n; i++) {
        if (i != 1) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}
