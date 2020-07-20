#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> V){
  int N = V.size();
  for ( int i = 0 ; i < N ; i++ ){
  	cout << V.at(i) ;
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
  
  vector<int> V(N);
  for ( int i = 0 ; i < N ; i++ ){
    cin >> V.at(i);
  }
  
  int count = 0;
  for ( int i = 0 ; i < N-1 ; i++ ){
    for ( int j = N-1 ; j > i ; j-- ){
      if (V.at(j) < V.at(j-1)){
        swap( V.at(j) , V.at(j-1) );
        count++;
      }
    }
  }  
  trace(V);
  cout << count << endl;  
}
