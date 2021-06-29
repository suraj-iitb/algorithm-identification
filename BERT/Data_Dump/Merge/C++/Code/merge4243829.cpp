#include<bits/stdc++.h>
using namespace std ;

const int maxnum = 1000000001;
int cnt = 0 ;

// merge separated vectors
void merge( vector<int> &a, int left, int mid, int right ){
  int n1 = mid - left ;
  int n2 = right - mid ;
  vector<int> l1(n1+1) ;
  vector<int> l2(n2+1) ;
  for (int i = 0; i < n1; i++) {
    l1.at(i) = a.at(left+i) ;
  }
  for (int i = 0; i < n2; i++) {
    l2.at(i) = a.at(mid+ i) ;
  }
  l1.at(n1) = maxnum ;
  l2.at(n2) = maxnum ;

  int i = 0 ;
  int j = 0 ;
  for (int k = left; k < right; k++) {
    if ( l1.at(i) <= l2.at(j)) {
      a.at(k) = l1.at(i) ;
      i++ ;
    }else{
      a.at(k) = l2.at(j) ;
      j++ ;
    }
    cnt++ ;
  }
}

void merge_sort( vector<int> &a, int left, int right) {
  if ( left+1 < right ) {
    int mid = (left + right) / 2 ; //分割
    merge_sort( a, left, mid ) ; // 左側ソート
    merge_sort( a, mid, right ) ; // 右側ソート
    merge(a, left, mid, right ) ; // ソートしたやつを合併
  }
}

int main()
{
  int n ;
  cin >> n ;
  vector<int> s(n) ;
  for (int i = 0; i < n; i++) {
    cin >> s.at(i) ;
  }

  merge_sort(s, 0, n) ;

  for(int i = 0; i < n-1; i++) {
    cout << s.at(i) << " " ;
  }
  cout << s.at(n-1) << endl ;
  cout << cnt << endl ;
  return 0 ;
}
