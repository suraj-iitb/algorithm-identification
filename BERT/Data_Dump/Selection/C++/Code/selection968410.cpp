#include<iostream>
#include<algorithm>
using namespace std;
int main(){

  int N,a[100],b=0,mini;
  
  cin >>N;
  
  for( int i=0 ; i < N ; i++ ){
    cin >>a[i];
  }
  
  for( int i=0 ; i < N-1 ; i++ ){
    mini=i;
    for( int j=i ; j < N ; j++ ){
      if( a[j] < a[mini] ){
	mini=j;
      }
    }
    if( i != mini ){
      swap(a[i],a[mini]);
      b++;
    }  
  }
  
  for( int i=0 ; i < N ; i++ ){
    if( i == N-1 ){
      cout <<a[i]<<endl;
    }else{
      cout <<a[i]<<" ";
    }
  }
  
  cout <<b<<endl;
  
  return 0 ;
  
}
