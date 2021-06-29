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

int selectionSort(vector<int> &A){
  int N = A.size();
  int cnt = 0;
  for ( int i = 0 ; i < N ; i++ ){
  	int minj = i;
    for ( int j = i ; j < N ; j++){
    	if( A.at(j) < A.at(minj) ){
          	minj = j ;
        }
    }
    if ( minj != i ){
      swap( A.at(minj) , A.at(i) );
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int N;
  cin >> N ;
  
  vector<int> V(N);
  for ( int i = 0 ; i < N ; i++ ){
    cin >> V.at(i);
  }

  int cnt = selectionSort(V);
  trace(V);
  cout << cnt << endl;
}
