#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,count=0;
  cin>> n;
  int a[n];
  bool b=true;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  while(b){
    b=false;
    for(int i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
        swap(a[i],a[i-1]);
        b=true;
        count++;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout <<a[i];
    if(i!=n-1)cout<<' ';
  }
  cout<<endl<<count<<endl;
  return 0;
}
      
