#include <bits/stdc++.h>
using namespace std;

void InSort(){
    int n;
  cin >> n;
  vector<int>a(n);
  for(int i = 0; i < n; i++) cin >> a[i];  
    for(int i = 0; i < a.size(); i++) {
      cout << a[i];
      if(i != a.size()-1) cout << " ";
    }
      cout << endl;
  for(int i = 1; i < a.size(); i++){
    int v = a[i];
    int j = i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
   for(int i = 0; i<n; i++) {
       cout << a[i];
       if(i != n-1) cout <<" ";
   }
   cout << endl;
  }
}

void Out(int n, vector<int> a){
  for(int i = 0; i<n; i++) {
    cout << a[i];
    if(i != n-1) cout <<" ";
  }
  cout << endl;
}


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int cnt = 0;
  bool flag = 1;
  while(flag){
    flag = 0;
    for(int i = 1; i < n; i++){
      if(a[i]<a[i-1]) {
        swap(a[i],a[i-1]);
        flag = 1;
        cnt++;
      }
    }
  }
  Out(n,a);
  cout << cnt << endl;
}

