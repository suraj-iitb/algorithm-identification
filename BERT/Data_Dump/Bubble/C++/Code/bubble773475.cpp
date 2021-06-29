#include <iostream>
#include <algorithm>

using namespace std;

int a[100];
int n;

int bubble_sort(void){

  int cnt = 0;
  for( int i = 1 ; i < n ; i++ ){
    for( int j = n - 1 ; j >= i ; j-- ){
      if( a[j - 1] > a[j] ){
	cnt++;
	swap( a[j - 1] , a[j] );
      }
    }
  }
  return cnt;
}

int main(void){

  cin >> n;
  for( int i = 0 ; i < n ; i++ )
    cin >> a[i];

  int ans = bubble_sort();
  for( int i = 0 ; i < n ; i++ ){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << ans << endl;
  return 0;
}
