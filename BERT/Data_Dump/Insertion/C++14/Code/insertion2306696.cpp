#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
using namespace std;

void show(vector<int> a){
  for(int i=0; i<a.size()-1; i++){
    cout << a[i] << " ";
  }
  cout << a[a.size()-1] << endl;
}

vector<int> isort(vector<int> a, int n){
  int v = 0;
  int j;
  show(a);
  for(int i=1; i<n; i++){
    v = a[i];
    j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    show(a);
  }
  return a;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  isort(a, n);

  return 0;
}
