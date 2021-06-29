#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a[100];
  cin >> n;
  int k=0,count=0;
  for(int i=0; i<n; i++) cin >> a[i];
  while(1){
    for(int i=n-1; i>0+k; i--){
      if(a[i-1] > a[i]) {
        swap(a[i-1],a[i]);
        count++;
      }
    }
    k++;
    if(k==n) break;
  }
  for(int i=0; i<n; i++){
    if(i==0) cout << a[i];
    else cout << " " << a[i];
  }
  cout << endl;
  cout << count << endl;
  return 0;
}

