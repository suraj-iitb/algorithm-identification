#include<bits/stdc++.h>
using namespace std;
int bubble_sort(vector<int> &v, int size){
  int j,swp, count_swap;
  bool is_swap;
  count_swap = 0;
  is_swap = true;
  while ( is_swap){
    is_swap = false;
    for( j=size-1; j>=1; j--){
      if( v[j] < v[j-1]){
        swp = v[j]; v[j] = v[j-1]; v[j-1] =swp;
        is_swap = true;
        count_swap++;
      }
    }
  }
  return count_swap;
}    
     
int main(){
  int n; cin>>n;
  vector<int> vec(n);
  int count;
  for( int i=0; i<n; i++){
    cin >> vec[i];
  }
  count = bubble_sort(vec, n);
  for( int i=0; i<n; i++){
    cout << vec[i];
    if( i != n-1) cout << ' ';
  }
  cout << endl;
  cout << count << endl;
  return 0;
}
