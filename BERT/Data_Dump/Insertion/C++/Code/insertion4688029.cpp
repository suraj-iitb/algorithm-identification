#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int n;
 cin >> n;
 
 vector<int> a(n);
 rep(i,n) {
  cin >>a.at(i);
  }
  
  rep(i,n-1) {
  cout << a.at(i) << ' ';
  }
  cout << a.at(n-1) << endl;
  
  
  for(int i = 1; i < n; i++) {
  int v = a.at(i);
  int j = i - 1;
  while (j >= 0 && a.at(j) > v) {
   a.at(j+1) = a.at(j);
   j--;
   }
   a.at(j+1) = v;
   
   rep(i,n) {
    cout << a.at(i);
    if(i != n-1){
     cout << ' ';
     }
     else {
      cout << endl;
      }
      }
      
  }
  
 
 
}
