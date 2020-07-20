#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,c=0;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=0;i<n;++i){
    for(int j=n-1;i<j;--j){
      if(a[j]<a[j-1]){swap(a[j-1],a[j]);++c;}
    }
  }
  for(int i=0;i<n;++i) cout<<a[i]<<((i==n-1)?"\n":" ");
  cout<<c<<endl;
  return 0;
}
