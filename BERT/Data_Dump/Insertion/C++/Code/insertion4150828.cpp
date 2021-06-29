#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n, i++)
using namespace std;

void trace(int a[],int n){
  int i;
  for(int i = 0; i < n; i++){
    if(i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

void insertionsort(int a[], int n){
  int v,j;
  for(int i = 0; i < n; i++){
    v = a[i];
    j = i -1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    trace(a,n);
  }
}

int main(void){
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  insertionsort(a,n);
  return 0;
}

