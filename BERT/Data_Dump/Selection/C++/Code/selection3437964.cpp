#include<iostream>
using namespace std;

int main(){
    int n, A[100], c = 0;
    cin >> n;
    for ( int i = 0; i < n; i++) cin >> A[i];

    for ( int i = 0; i < n-1; i++){
        int minj = i;
        for ( int j = i; j< n; j++){
            if ( A[j] < A[minj]) minj = j;
        }
        if ( i != minj){
            swap(A[i], A[minj]);
            c++;
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
