#include<iostream>
using namespace std;

int main(){
    int n, A[1000];
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> A[i];
    
    for ( int i = 0; i < n; i++ ){
        int v = A[i];
        int j = i - 1;
        while ( j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for ( int l = 0; l < n; l++) {
            if (l) cout << " ";
            cout << A[l];
        }
        cout << endl;
    }
    
    return 0;
}
