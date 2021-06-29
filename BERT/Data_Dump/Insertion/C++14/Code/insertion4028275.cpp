#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> a( N );
  for( int i = 0; i < N; i++ ) cin >> a[i];
  
  for( int i = 0; i < N; i++ ){
    cout << a[i];
    if( i == N - 1 ) cout << endl;
    else cout << " ";
  }
  
  for( int j = 1; j < N; j++ ){
    int key = a[j];
    int i = j - 1;
    
    while( i >= 0 && a[i] > key ){
      a[i + 1] = a[i];
      i--;
    }
    a[i + 1] = key;
    
    for( int i = 0; i < N; i++ ){
      cout << a[i];
      if( i == N - 1 ) cout << endl;
      else cout << " ";
    }
    
  }
}

