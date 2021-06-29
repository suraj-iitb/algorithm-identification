#include <iostream>
#include <vector>
using namespace	std;
int main(){

  vector <int> a;
  int n,b,i;

  cin>>n;
  for(i=0;i<n;i++){
    cin>>b;
    a.push_back(b);
  }

  for(i=0;i<n-1;i++) cout<<a[i]<<" ";
  cout<<a[n-1]<<endl;

  for(i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[i]<a[j]){
        a.insert(a.begin()+j,a[i]);
        a.erase(a.begin()+i+1);
      }
    }

    for(int j=0;j<n-1;j++) cout<<a[j]<<" ";
    cout<<a[n-1]<<endl;
  }

  return 0;

}
