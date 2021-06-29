#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    vector<int> A(N);
    for( int i=0; i<N; i++) cin >> A[i];
    
    int count = 0;
    for( int i=0; i<N; i++){
        int min = i;
        
        for( int j=i+1; j<N; j++){
            if( A[min] > A[j] ){
                min = j;
            }
        }
      
       if( min != i ){
         swap(A[min],A[i]);
         count++;
       }
    }
     
  for(int i=0;i<N;i++){
    cout << (i!=0?" ":"") << A[i];
  }
  cout << endl << count << endl;
    return 0;
}
