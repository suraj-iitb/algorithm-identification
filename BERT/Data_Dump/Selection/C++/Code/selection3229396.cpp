#include<bits/stdc++.h>
using namespace std;
int selection_sort(vector<int> &v, int size){
  int i,j,swp,count_n;
  int min, min_n;
  bool is_swp;
  count_n = 0;
  for( i=0; i<size; i++){
    for( j=i; j<size; j++){
      if( j == i){
        min = v[j]; min_n = j; is_swp = false;
      }
      else if( min > v[j]){
        min = v[j]; min_n = j; is_swp = true;
      }
    }
    if( is_swp){
      swp = v[i]; v[i] = v[min_n]; v[min_n] = swp;
      count_n++;
    }
  }
  return count_n;
}
int main(){
  int n; cin>>n;
  vector<int> vec(n);
  for(int i=0; i<n; i++){
    cin>>vec[i];
  }
  int count;
  count = selection_sort(vec, n);
  for(int i=0; i<n; i++){
    cout << vec[i];
    if( i != n-1) cout<< ' ';
  }
  cout << endl;
  cout << count << endl;
  return 0;
}
