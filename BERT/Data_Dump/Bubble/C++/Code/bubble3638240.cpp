#include<iostream>
using namespace std;

int bubblesort(int A[], int N){
    int sw = 0; // counter
    
    for(int i = 0; i < N - 1; i++){
        for(int j = N-1; j > i; j--){
            if( A[j] < A[j - 1]){
                swap( A[j], A[j - 1]);
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int A[100], N, sw;
    
    cin >> N;
    for( int i = 0; i < N; i++) cin >> A[i];
    
    sw = bubblesort(A, N);
    
    for( int i = 0; i < N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    
    return 0;
}
