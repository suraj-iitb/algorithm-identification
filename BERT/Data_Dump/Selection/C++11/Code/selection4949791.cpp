#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> a, int N){
  int cnt = 0;
  for(int i = 0; i < N; i++){
    int minv = i;
    for(int j = i; j < N; j++){
      if(a[j] < a[minv]) minv = j;
    }
    if(i != minv){
      int tmp = a[i];
      a[i] = a[minv];
      a[minv] = tmp;
      cnt++;
    }
  }
  
  for(int i = 0; i < N; i++){
    if(i == N - 1) cout << a[i] << endl;
    else cout << a[i] << " ";
  }
  cout << cnt << endl;
}

int main() {
  int N; cin >> N;
  vector<int> a(N);
  
  for(int i = 0; i < N; i++) cin >> a[i];
  
  selectionSort(a, N);
}
