#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for ( int i = 0; i < N; i++ ) cin >> A[i];
    
    for ( int j = 0; j < N; j++ ){
        cout << A[j];
        if ( j < N - 1) cout << " ";
        else cout << endl;
    }
    
    for ( int i = 1; i < N; i++){
        int v, j;
        v = A[i];
        j = i - 1;
        while ( j >= 0 and A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        
        for ( int j = 0; j < N; j++ ){
            cout << A[j];   
            if ( j < N - 1) cout << " ";
            else cout << endl;
        }
    }
   
    return 0;
}
