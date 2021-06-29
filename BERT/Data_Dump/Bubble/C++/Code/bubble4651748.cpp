#include<iostream>
using namespace std;
int main() {
    int x, flag, cnt=0;
    cin >> x;
    int A[x];
    for ( int i = 0; i < x; i++ ){
        cin >> A[i];
    }
    flag = 1;
    while (flag){
        flag = 0;
        for ( int j = x-1; j > 0; j-- ){
            if ( A[j] < A[j-1] ){
                swap( A[j], A[j-1] );
                flag = 1;
                cnt += 1;
            }
        }
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
