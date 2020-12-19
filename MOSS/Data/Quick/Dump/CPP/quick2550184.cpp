#include <bits/stdc++.h>
using namespace std;

struct card{
  char c;
  int num;
};

struct card a[100001];
struct card b[100001];

bool operator<(const card &s, const card &t){
  return s.num < t.num;
}

int partition(int p, int r){
  int x = a[r].num;
  int idx = p-1;
  for(int i = p; i < r; i++){
    if(a[i].num <= x){
      idx++;
      swap(a[idx], a[i]);
    }
  }
  swap(a[idx+1], a[r]);
  return idx+1;
}

void quicksort(int p, int r){
  if(p < r){
    int q = partition(p, r);
    quicksort(p, q-1);
    quicksort(q+1, r);
  }
}

int main(){

  int n, v;
  char ch;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> ch >> v;
    a[i].c = b[i].c = ch;
    a[i].num = b[i].num = v;
  }
  stable_sort(b, b+n);
  quicksort(0, n-1);

  int stable = 1;
  for(int i = 0; i < n; i++){
    if(a[i].c != b[i].c) stable = 0;
  }
  if(stable) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  for(int i = 0; i < n; i++){
    cout << a[i].c << " " << a[i].num << endl;
  }
  return 0;
}
