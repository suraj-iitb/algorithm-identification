#include <bits/stdc++.h>
using namespace std;

void insertionsort ( vector<int> A, int N ){
    
    for( int i=0 ; i<N ; i++){
         if( i != N-1 ){
             cout << A.at(i) << " " ;
         }
         else{
             cout << A.at(i) << endl;
         }
    }

 for( int i=1; i<N ; i++){
     
    int v= A.at(i) ;
    
    int j = i - 1 ;
    
     while( j>= 0 && A.at(j) > v ){
         // A[j+1]とA[j]を交換してjを一つ下げる
         A.at(j+1) = A.at(j) ;
         j-- ;
         A.at(j+1) = v ;
    }
     
     for( int i=0 ; i<N ; i++){
          if( i != N-1 ){
              cout << A.at(i) << " " ;
          }
          else{
              cout << A.at(i) << endl;
          }
     }
 }
    return;
}



int main() {
    int N ;
    cin >> N ;
    
    vector<int> A(N) ;
    
    for( int i=0 ; i<N ; i++) cin >> A.at(i) ;
    
    insertionsort( A , N ) ;
    
}

