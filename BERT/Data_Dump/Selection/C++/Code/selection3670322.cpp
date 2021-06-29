#include<iostream>
using namespace std;

int main(){
    
    int N, A[100];
    
    cin >> N;
    for ( int i = 0; i < N; i++) cin >> A[i];
    
    int minj, a, count = 0;
    for ( int i = 0; i < N-1; i++){
        minj = i;
        for ( int j = i; j < N; j++){
            if ( A[j] < A[minj] ) minj = j;
        }
        if ( i != minj) count++;
        a = A[i];
        A[i] = A[minj];
        A[minj] = a;
        
    }
    for ( int i = 0; i < N; i++){
        if ( i == N-1) {
            cout << A[i] << endl;
            break;
        }    
        cout << A[i] << " " ;
    }
    cout << count <<endl;

}
