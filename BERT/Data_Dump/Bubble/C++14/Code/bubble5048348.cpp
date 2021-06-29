#include <bits/stdc++.h>
using namespace std;

void output(vector<int>);

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count=0;
  bool flg=true;
  while(flg){
    flg=false;
    for(int j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
        swap(a[j],a[j-1]);
        count++;
        flg=true;
      }
    }
  }
  output(a);
  cout<<count<<endl;
  return 0;
}

void output(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i) {
      cout << ' ';
    }
    cout << v[i];
  }
  cout << endl;
}
