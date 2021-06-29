#include <iostream>

using namespace std;

int main(){
  int n,a[100];

  cin>>n;

  for(int i=0; i<n; ++i){
    cin>>a[i];
  }

  int minv=0,cnt=0;
  for(int i=0; i<n-1; ++i){
    minv=i;
    
    for(int j=i; j<n; ++j){
      
      if(a[minv] > a[j]){
	minv = j;
      }
      
    }


    if(!( minv == i )){
      swap(a[minv],a[i]);
      ++cnt;
    }
    
      
  }

  for(int i=0; i<n; ++i){
    cout<<a[i];
    if(i<n-1)
      cout << " ";
  }
  cout << endl << cnt << endl;;


  return 0;
}

