#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,count=0,i;
  cin >> n;
  int a[n];
  bool flag;
  for(i=0; i<n; i++){
    cin >> a[i];
  }
  flag = 1;
  i = 0;
  while(flag){
    flag = 0;
    for(int j=n-1; j>=i+1; j--){
      if(a[j]<a[j-1]){
        swap(a[j],a[j-1]);
        flag = 1;
        count++;
      }
    }
    i++;
  }
  
  for(int i=0; i<n; i++){
    cout << a[i];
    if(i!=n-1)cout << " ";
  }
  cout << endl << count << endl;
  
}
