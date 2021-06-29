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
#include<queue>
using namespace std;
int cnt = 0;
vector<int> bubble(vector<int> a){
  bool f = true;
  while( f ){
    f = false;
    for(int i=a.size()-1; i>0; i--){
      if( a[i] < a[i-1] ){
        swap(a[i], a[i-1]);
        f = true;
        cnt++;
      }
    }
  }
  return a;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  a = bubble(a);
  for(int i=0; i<n-1; i++) cout << a[i] << " ";
  cout << a[n-1] << endl;
  cout << cnt << endl;

  return 0;
}
