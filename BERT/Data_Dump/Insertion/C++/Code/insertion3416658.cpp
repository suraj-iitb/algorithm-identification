#include <iostream>
using namespace std;

int main(){
  int n;
  int a[1010];
  cin>>n;
  for (int i=0; i<n; ++i) cin>>a[i];
  
  for (int j=0; j<n; ++j){
  if (j) cout<<" ";
    cout<<a[j];
  }
  cout<<endl;
  for (int i=1; i<n; ++i){
    int j=i-1;
    int v=a[i];
    while (j>=0 && a[j]>v){
      a[j+1]=a[j];
      --j;
    }
    a[j+1]=v;
    for (j=0; j<n; ++j){
      if (j) cout<<" ";
      cout<<a[j];
    }
    cout<<endl;
  }
}