#include <iostream>

using namespace std;

int bubbleSort(int a[],int n){
  int flag=1;
  int cnt=0;
  while(flag){
    flag=0;
    for(int j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
        swap(a[j],a[j-1]);
        cnt++;
        flag=1;
      }
    }
  }
  return cnt;
}

int main(){
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  int ans=bubbleSort(a,n);
  for(int i=0;i<n;i++){
    if(i==n-1) cout << a[i] << endl;
    else cout << a[i] << " ";
  }
  cout << ans << endl;
}
