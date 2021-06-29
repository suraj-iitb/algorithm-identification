#include <iostream>
using namespace std;


void isort(int A[], int N){
    
    for(int k=0;k<N;k++){
        cout << ( k ? " " : "" ) << A[k];
    }
    cout << endl;
    
    for(int i=1;i<=N-1;i++){
        int v = A[i];
        int j = i-1;
        while(j>= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(int k=0;k<N;k++){
            cout << ( k ? " " : "" ) << A[k];
        }
        cout << endl;
    }
}

int main(){
    int N,A[1000+10];
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    
    isort( A , N );
    
}
