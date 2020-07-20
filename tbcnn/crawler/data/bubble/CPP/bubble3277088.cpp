#include <iostream>

using namespace std;

int main(){
  int n,a[100];
  cin>>n;
  for(int i=0; i<n; ++i){
    cin>>a[i];
  }

  int cnt=0;

  for(int i=1; i<n; ++i){
    for(int j=n-1; j>=i; --j){
      if(a[j] < a[j-1]){
	swap(a[j] , a[j-1]);
	++cnt;
      }
    }
  }

  for(int i=0; i<n; ++i){
    cout << a[i];
    if(i<n-1)
      cout<<" ";
  }
  cout << endl << cnt << endl;
  


  return 0;
}

