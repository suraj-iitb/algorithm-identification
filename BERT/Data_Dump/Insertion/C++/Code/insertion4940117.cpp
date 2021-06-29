#include <bits/stdc++.h>
using namespace std;
long long const INF = 1LL<<60;

void log(vector<int> a, int n){
  for(int j = 0; j < n; j++){
    if(j == n - 1) cout << a[j];
    else cout << a[j] << " ";
  }
  cout << endl;
}

void insertion_sort(vector<int> a, int n){
  for(int i = 1; i < n; i++){
    int v = a[i];
    int j = i - 1;
    
    while(j >=0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j + 1] = v;
    log(a, n);
  }
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  
  log(a, n);
  insertion_sort(a, n);
}
