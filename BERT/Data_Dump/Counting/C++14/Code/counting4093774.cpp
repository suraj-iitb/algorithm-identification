#include <bits/stdc++.h>
using namespace std;

int   a[2000010];
int ans[2000010];
int   c[10010];

int main(){
  int N; cin >> N;
  for( int i = 0; i < N; i++ ){
    cin >> a[i];
    c[a[i]]++;
  }

  for( int i = 1; i < 10010; i++ ){
    c[i] += c[i - 1];
  }

  for( int i = N - 1; i >= 0; i-- ){
    ans[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }

  for( int i = 0; i < N; i++ ){
    cout << ans[i];
    if( i == N - 1 ) cout << endl;
    else cout << " ";
  }
  
}

