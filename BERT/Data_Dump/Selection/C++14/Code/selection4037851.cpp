#include <bits/stdc++.h>
using namespace std;

int a[101];

int main(){
  int N; cin >> N;
  for( int i = 0; i < N; i++ ){
    cin >> a[i];
  }

  int cnt = 0;
  for( int i = 0; i < N - 1; i++ ){
    int minj = i;
    for( int j = i; j < N; j++ ){
      if( a[j] < a[minj] ){
	minj = j;
      }
    }
    if( minj != i ){
      int t = a[minj];
      a[minj] = a[i];
      a[i] = t;
      cnt++;
    }
  }

  for( int i = 0; i < N; i++ ){
    cout << a[i];
    if( i == N - 1 ) cout << endl;
    else cout << " ";
  }
  cout << cnt << endl;
}

