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
  output(a);
  for(int i=1;i<n;i++){
    int v=a[i];
    int j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    output(a);
  }
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
