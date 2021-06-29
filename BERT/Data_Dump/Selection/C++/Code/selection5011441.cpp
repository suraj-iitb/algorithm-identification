#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,i,count=0,minj;
  cin >> n;
  int a[n];
  
  for(i=0; i<n; i++){
    cin >> a[i];
  }
  for(i=0; i<n; i++){
    minj = i;
    for(int j=i; j<n; j++){
      if(a[j]<a[minj]) minj = j;
    }
    if(i!=minj){
      swap(a[i],a[minj]);
      count++;
    }
  }
  
  for(i=0; i<n; i++){
    cout << a[i];
    if(i!=n-1)cout << " ";
  }
  cout << endl << count << endl;
  return 0;
  
}
