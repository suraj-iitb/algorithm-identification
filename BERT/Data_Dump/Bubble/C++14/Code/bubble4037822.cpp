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
    for( int j = N - 1; j >= 1; j-- ){
      if( a[j - 1]> a[j] ){
	int t = a[j - 1];
	a[j - 1] = a[j];
	a[j] = t;
	cnt++;
      }
    }
  }

  for( int i = 0; i < N; i++ ){
    cout << a[i];
    if( i == N - 1 ) cout << endl;
    else cout << " ";
  }
  cout << cnt << endl;
}

