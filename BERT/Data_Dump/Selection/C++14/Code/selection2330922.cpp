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
vector<int> select(vector<int> a){
  for(int i=0; i<a.size(); i++){
    int minj = i;
    for(int j=i; j<a.size(); j++){
      if( a[j] < a[minj] ){
        minj = j;
      }
    }
    if( i != minj ) cnt++;
    swap(a[i], a[minj]);
  }
  return a;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  a = select(a);
  for(int i=0; i<n-1; i++) cout << a[i] << " ";
  cout << a[n-1] << endl;
  cout << cnt << endl;

  return 0;
}
