#include <iostream>
using namespace std;
int main () {

  int N,A[100],a,c;

  cin >>N;
  
  for( int i=0 ; i < N ; i++ ){
    cin >>A[i];
  }
  
  for( int l=0 ; l < N ; l++ ){
    if( l == N-1){
      cout <<A[l]<<endl;
    }else{
      cout <<A[l]<<" ";
    }
  }
  
for( int j=0 ; j < N-1 ; j++ ){
    c=j;
    while( c >= 0 ){
      if( A[c] > A[c+1] ){
	a=A[c+1];
	A[c+1]=A[c];
	A[c]=a;
      }
      c--;
    }
    for( int k=0 ; k < N ; k++){
      if( k == N-1 ){
	cout <<A[k]<<endl;
      }else{
	cout <<A[k]<<" ";
      }
    }
  }

  return 0;

}
