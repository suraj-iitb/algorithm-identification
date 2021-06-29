#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<complex>
#include<map>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int ii = 0; ii < n; ii++){
    cout << a[ii];
    if(ii == n-1) cout << endl;
    else cout << " ";
  }

  for(int i = 1; i < n; i++){
    int temp = a[i];
    int j = i-1;
    while(j >= 0 && a[j] > temp){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = temp;
    for(int ii = 0; ii < n; ii++){
      cout << a[ii];
      if(ii == n-1) cout << endl;
      else cout << " ";
    }
  }

  return 0;
}

