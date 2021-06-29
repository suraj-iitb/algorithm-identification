#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;
int n,cnt;
int a[500010];
int L[300010],R[300010];

void merge(int l,int m,int r){
  int n1 = m-l;
  int n2 = r-m;
  for(int i = 0; i < n1; i++) L[i] = a[l+i];
  for(int i = 0; i < n2; i++) R[i] = a[m+i];
  L[n1] = R[n2] = INF;
  int i = 0,j = 0;
  for(int k = l; k < r; k++){
    if(L[i] <= R[j]) a[k] = L[i++];
    else {
      a[k] = R[j++];
    }
    cnt++;
  }
}

void mergesort(int l,int r){
  if(l+1 == r) return;
  int m = (l+r)/2;
  mergesort(l,m);
  mergesort(m,r);
  merge(l,m,r);
}

signed main(){

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  mergesort(0,n);

  for(int i = 0; i < n; i++){
    if(i == n-1) cout << a[i] << endl;
    else cout << a[i] << " ";
  }
  cout << cnt << endl;

  return 0;
}

