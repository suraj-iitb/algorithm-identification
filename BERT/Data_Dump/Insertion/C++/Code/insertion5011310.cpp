#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,v,j,k;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  
  for(int i=0;i<n;i++){
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for(k=0;k<n;k++){
      cout << a[k];
      if(k!=n-1)cout << " ";
    }
    cout << endl;
  }
  
  return 0;
}
