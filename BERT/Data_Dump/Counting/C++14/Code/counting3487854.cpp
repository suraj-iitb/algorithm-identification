#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
const int MAX = 10010;
int n; 
int A[2001000];
int B[2001000];
int C[MAX] = {0};

void countingSort() {
    for (int i = 1; i <= n; i++) ++C[A[i]];
    for (int i = 1; i < MAX; ++i) C[i] += C[i-1];
    for (int i = n; i > 0; --i) B[C[A[i]]] = A[i], --C[A[i]];
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    countingSort();
    for (int i = 1; i <= n ; i++) {
        if (i > 1) cout << " ";
        cout << B[i];
    }
    cout << endl;
}

