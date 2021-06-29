#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

int main() {
    int A[MAX], N;
    int key;
    cin >> N;
    for ( int i = 0; i < N; ++i ) cin >> A[i];

    for ( int i = 0; i < N; ++i ) {
        key = A[i];
        int j = i - 1;
        while ( j >= 0 && A[j] > key ) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        for ( int k = 0; k < N-1; ++k ) cout << A[k] << ' ';
        cout << A[N-1];
        //cout << '\b';
        cout << endl;
    }

    return 0;
}
