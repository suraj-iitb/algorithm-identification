#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  vector<int>a(n);
  for(int i = 0;i<n;i++) cin >> a[i];
  for(int i = 0;i<n-1;i++) cout << a[i]<<' ';
  cout << a[n-1];
  cout << endl;
  for(int i = 1;i<n;i++){
   int temp = a[i];
   int j = i - 1;
   while(j>=0&&a[j]>temp){
     a[j+1] = a[j];
     j --;
   }
   a[j+1] = temp;
    for(int k = 0;k<n-1;k++) cout << a[k]<<' ';
    cout << a[n-1];
    cout <<endl;
  }
  
  return 0;
}
