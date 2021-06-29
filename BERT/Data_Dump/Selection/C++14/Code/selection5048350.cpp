#include <bits/stdc++.h>
using namespace std;

void output(vector<int>);
void swap(int&, int&);

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count=0;
  for(int i=0;i<n-1;i++){
    int minj=i;
    for(int j=i+1;j<n;j++){
      if(a[j]<a[minj]){
        minj=j;
      }
    }
    if(a[i]==a[minj]){
      continue;
    }
    swap(a[i], a[minj]);
    count++;
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

void swap(int& a, int& b) {
  int temp = b;
  b = a;
  a = temp;
}
