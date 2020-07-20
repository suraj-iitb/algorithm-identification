#include<iostream>
using namespace std;
int main(){

  int N,n[100],a,b=0;
  
  cin >>N;

  for( int i=0 ; i < N ; i++ ){
    cin >>n[i];
  }

  for( int i=0 ; i < N ; i++ ){
    for( int j=N-1 ; j > i ; j-- ){
      if( n[j] < n[j-1] ){
	a=n[j];
	n[j]=n[j-1];
	n[j-1]=a;
	b++;
      }
    }
  }

  for( int i=0 ; i < N ; i++ ){
    if( i == N-1 ){
      cout <<n[i]<<endl;
    }else{
      cout <<n[i]<<" ";
    }
  }
  cout <<b<<endl;

  return 0;
}
