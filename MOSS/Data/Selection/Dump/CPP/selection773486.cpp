#include <iostream>
#include <algorithm>
#define INF 999999

using namespace std;

int a[100];

int selection_sort(int n){

  int cnt = 0;
  bool f;
  for( int i = 0 ; i < n ; i++ ){
    int m = i; f = true;
    for( int j = i ; j < n ; j++ ){
      if( a[j] < a[m] ){
	m = j;
	f = false;
      }
    }
    if(f)continue;
    swap(a[i] , a[m]);
    cnt++;
  }
  return cnt;
}

int main(void){

  int n;
  cin >> n;
  for( int i = 0 ; i < n ; i++ )
    cin >> a[i];

  int ans =  selection_sort(n);

  for( int i = 0 ; i < n ; i++ ){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << ans << endl;
  return 0;
}
