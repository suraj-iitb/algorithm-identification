#include <iostream>
using namespace std;
static const int MAX = 1000;

int main() {
    int A[MAX], N;
    int i;

    cin >> N;
    for (i = 0; i < N; i++ ) cin >> A[i];

    for (i = 0; i < N-1; i++ ) cout << A[i] << " ";
    cout << A[i] << endl;

    for (i = 1; i < N; i++ ) {
        int v = A[i];
        int j = i - 1;
        while ( j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        int k;
        for (k = 0; k < N-1; k++ ) cout << A[k] << " ";
        cout << A[k] << endl;

    }
    return 0;
}
