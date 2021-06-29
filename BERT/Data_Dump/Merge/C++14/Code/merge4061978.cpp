#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;

int cnt = 0;

void merge( int* a, int left, int mid, int right ){
  int n1 = mid - left;
  int n2 = right - mid;
  int* L = new int[n1 + 1];
  int* R = new int[n2 + 1];
  for( int i = 0; i < n1; i++ ) L[i] = a[left + i];
  for( int i = 0; i < n2; i++ ) R[i] = a[mid + i];
  L[n1] = INF;
  R[n2] = INF;

  int i = 0, j = 0;
  for( int k = left; k < right; k++ ){
    if( L[i] <= R[j] ){
      a[k] = L[i++];
    }else{
      a[k] = R[j++];
    }
    cnt++;
  }
}

void mergeSort( int* a, int left, int right ){
  if( right - left > 1 ){
    int mid = ( right + left ) / 2;
    mergeSort( a, left, mid );
    mergeSort( a, mid, right );
    merge( a, left, mid, right );
  }
}

int main(){
  int n; cin >> n;
  int* s = new int[n];
  for( int i = 0; i < n; i++ ) cin >> s[i];

  mergeSort( s, 0, n );

  for( int i = 0; i < n; i++ ){
    cout << s[i];
    if( i == n - 1 ) cout << endl;
    else cout << " ";
  }

  cout << cnt << endl;
}

