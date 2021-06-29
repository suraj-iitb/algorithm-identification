#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,flag,j,cnt=0;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  
  flag = 1;
  j = 0;//未ソート部分列の先頭インデックス
  while(flag){
    flag = 0;
    for(int k=n-1;k>j;k--){
      if(a[k-1]>a[k]){
        swap(a[k-1],a[k]);
        cnt++;
        flag = 1;
      }
    }
    j++;
  }
  
  for(int i=0;i<n-1;i++)
    cout << a.at(i) << " ";
  cout << a.at(n-1) << endl;
  cout << cnt << endl;
  
  return 0;
}
