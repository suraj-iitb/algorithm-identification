#include <bits/stdc++.h>
using namespace std;

int Bchange ( vector<int> &A , int &N ){
    int flag = 1 ;
    int cnt = 0 ;
    
    while ( flag ){
        flag = 0 ;
        for( int j=N-1 ; j>0 ; j--){
            if( A[j] < A[j-1] ){
                swap( A[j] , A[j-1] ) ;
                flag = 1 ;
                cnt ++ ;
            }
        }
    }
    
    return cnt ;
}

int main() {
    int N ;
    cin >> N ;
    
    vector<int> A(N) ;
    
    for( int i=0 ; i<N ; i++) cin >> A[i] ;
    
    int cnt = Bchange ( A , N ) ;
    
    for( int i=0 ; i<N ; i++){
        if( i!= N-1 ){
            cout << A[i] << " " ;
        }
        else{
            cout << A[i] << endl;
        }
    }
    
    cout << cnt << endl;
    
}

