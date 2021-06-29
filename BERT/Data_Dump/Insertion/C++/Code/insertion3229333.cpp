#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int> &v, int size){
  int i,j,at;
  for( i=1; i<size; i++){
    at = v[i];
    j = i-1;
    while( j>=0 && at<v[j]){
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = at;
    //ここでは途中経過をアウトプット
    for( j=0; j<size; j++){
      cout << v[j];
      if(j != size-1) cout << ' ';
    }
    cout<<endl;
  }
}
 
int main(){
  int n; cin>>n;
  vector<int> a(n);
  int i;
  for( i=0; i<n; i++){
    cin>>a[i];
  }
  //ここでは途中経過をアウトプット
  for( i=0; i<n; i++){
    cout << a[i];
    if(i != n-1) cout << ' ';
  }
  cout<<endl;
  
  insertion_sort(a, n);
  return 0;
}

