#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

void nout(vi a, int n){
  rep(i, n){
    cout << a[i];
    if(i<n-1){
      cout << " ";
    }
  }
  cout << endl;
}

void insetionsort(vi a, int n){
  for(int i=1; i<n; i++){
    int v=a[i], j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    nout(a, n);
  }
}

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i, n)cin >> a[i];

  nout(a, n);
  insetionsort(a, n);

  return 0;
}
