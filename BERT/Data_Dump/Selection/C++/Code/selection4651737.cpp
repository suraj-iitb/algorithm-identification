#include<iostream>
using namespace std;
int main() {
    int x, minj, cnt = 0;
    cin >> x;
    int A[x];
    for ( int i = 0; i < x; i++ ){
        cin >> A[i];
    }
    for ( int i = 0; i < x; i++ ){
        minj = i;
        for ( int j = i; j < x; j++ ){
            if ( A[j] < A[minj] ){
                minj = j;
            }
        }
        if ( A[i] != A[minj] ) cnt += 1;
        swap( A[i], A[minj] );
    }
    for ( int i = 0; i < x; i++ ){
        if ( i == x-1 ){
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }
    cout << cnt << endl;
    return 0;
}

