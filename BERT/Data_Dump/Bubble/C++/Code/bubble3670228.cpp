#include<iostream>
using namespace std;

int main(){
    
    int N;
    int A[100];
    
    cin >> N;
    for ( int i = 0; i < N; i++) cin >> A[i];
    
    int a, flag = 1, count = 0;
    while ( flag ){
        flag = 0;
        for ( int j = N-1; j > 0; j--){
            if ( A[j] < A[j-1] ){
                a = A[j];
                A[j] = A[j-1];
                A[j-1] = a;
                count++;
                flag = 1;
            }
        }
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

