#include<bits/stdc++.h>
using namespace std;

struct card{ char a; int b; };
int n;
card a[200010],b[200010];

int partition(int p,int r){
  for(int i = p; i < r; i++){
    if(a[i].b <= a[r].b) swap(a[p++],a[i]);
  }
  swap(a[p],a[r]);
  return p;
}

void quicksort(int p,int r){
  if(p >= r) return;
  int q = partition(p,r);
  quicksort(p,q-1);
  quicksort(q+1,r);
}

const int INF = 1e9+10;
card L[300010],R[300010];

void merge(int l,int m,int r){
  int n1 = m-l;
  int n2 = r-m;
  for(int i = 0; i < n1; i++) L[i] = b[l+i];
  for(int i = 0; i < n2; i++) R[i] = b[m+i];
  L[n1] = R[n2] = {'D',INF};
  int i = 0,j = 0;
  for(int k = l; k < r; k++){
    if(L[i].b <= R[j].b) b[k] = L[i++];
    else {
      b[k] = R[j++];
    }
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
  for(int i = 0; i < n; i++){
    cin >> a[i].a >> a[i].b;
    b[i].a = a[i].a;
    b[i].b = a[i].b;
  }

  quicksort(0,n-1);
  mergesort(0,n);

  int f = 1;
  for(int i = 0; i < n; i++){
    if(a[i].a != b[i].a || a[i].b != b[i].b) f = 0;
  }

  cout << (f ? "Stable" : "Not stable") << endl;
  for(int i = 0; i < n; i++){
    cout << a[i].a << " " << a[i].b << endl;
  }



  return 0;
}

