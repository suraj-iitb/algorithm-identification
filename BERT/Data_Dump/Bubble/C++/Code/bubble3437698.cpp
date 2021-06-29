#include<iostream>
using namespace std;

int main(){
    int n, A[100], c = 0;
    cin >> n;
    for ( int i = 0; i < n; i++) cin >> A[i];

    bool flag = 1;
    for ( int i = 0; flag; i++ ){
        flag = 0;
        for( int j = n-1; j > i; j--){
            if ( A[j-1] > A[j] ){
                swap(A[j-1], A[j]);
                c++;
                flag = 1;
            }
        }
    }

    for ( int i = 0; i < n; i++){
        if ( i ) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << c << endl;

    return 0;
}
