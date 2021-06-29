#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n, i++)
using namespace std;

int selectionsort(int a[],int n){
  int count = 0;
  for(int i = 0; i < n; i++){
    int minj = i;
    for(int j = i; j < n; j++){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    int v = a[i];
    a[i] = a[minj];
    a[minj] = v;
    if(minj != i) count++;
  }
  return count;
}

int main(void){
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int count = selectionsort(a,n);
  selectionsort(a,n);
  for(int i = 0; i < n; i++){
    if(i != n-1){
      cout << a[i] << " ";
    }
    else cout << a[i] << endl;
  }
  cout << count << endl;
  return 0;
}

