#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[105];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int f=1;
  int co=0;
  while(f){
    f=0;
    for(int i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
	swap(a[i],a[i-1]);
	co++;
	f=1;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << a[i];
    if(i+1!=n)cout << " ";
  }
  cout << endl;
  cout << co << endl;
  return 0;
}
