#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  for(int j=0;j<n;++j)cout<<a[j]<<((j==n-1)?"\n":" ");
  for(int i=1;i<n;++i){
    int key=a[i],j=i-1;
    for(;j>=0 && a[j]>key;--j){
      a[j+1]=a[j];
    }
    a[j+1]=key;
    for(int j=0;j<n;++j)cout<<a[j]<<((j==n-1)?"\n":" ");
  }
  return 0;
}
