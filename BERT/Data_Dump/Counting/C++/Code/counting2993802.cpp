#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cstring>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using namespace std;

const int N_MAX = 3000000;
int a[N_MAX];
int b[N_MAX];
int c[N_MAX];

void countingsort(int* a, int n){
  int k = 10001;
  rep(i, 1, k) c[i] = c[i] + c[i-1];
  rep(i, n, -1){
    b[c[a[i]]-1] = a[i];
    c[a[i]]--;
  }
}

int main(){
  int n;
  cin >> n;
  memset(c, 0, N_MAX*sizeof(c[0]));
  
  rep(i, 0, n){
    cin >> a[i];
    c[a[i]]++;
  }
  countingsort(a, n);
  rep(i, 0, n){
    cout << b[i];
    if(i==n-1) cout << endl;
    else cout << " ";
  }
  return 0;
}

