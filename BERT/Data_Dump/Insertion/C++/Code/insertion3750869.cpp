#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> T){
  int N = T.size();
  for ( int i = 0 ; i < N ; i++ ){
  	cout << T.at(i) ;
    if( i == N-1 ) 
      cout << endl;
    else
      cout << " ";
  }
  return;
}

int main() {
  int N;
  cin >> N ;
  
  vector<int> T(N);
  for ( int i = 0 ; i < N ; i++ ){
    cin >> T.at(i);
  }
  trace(T);
  
  for ( int i = 1 ; i < N ; i++ ){
    int v = T.at(i) ;
    int j = i - 1 ;
	while( j >= 0 && T.at(j) > v){
      	T.at(j+1) = T.at(j) ;
        j--;
      }
    T.at(j+1) = v;
    trace(T);
  }   
}
