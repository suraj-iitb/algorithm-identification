#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

void print(int n,vector<int> a){
  cout << a[0];
  for(int i=1;i<n;i++) cout << " " << a[i];
  cout << endl;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=1;i<n;i++){
    print(n,a);
    int v = a[i];
    int j = i-1;
    while(j>=0&&a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
  }
  print(n,a);
  return 0;
}

