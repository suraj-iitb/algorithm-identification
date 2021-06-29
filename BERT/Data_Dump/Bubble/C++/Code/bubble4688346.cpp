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
  
  int count = 0;
  bool v = true;
   while(v == true) {
    v = false;
     for(int i = n - 1; i >0; i--){
     int b = 0;
      if(a.at(i) < a.at(i-1)) {
      b = a.at(i);
      a.at(i) = a.at(i-1);
      a.at(i-1) = b;
      count++;
      v = true;
       }
       }
     }
 if(n != 1){    
 rep(i,n-1) {
  cout << a.at(i) << ' ';
  }
  cout << a.at(n-1) << endl;
  cout << count << endl;;
  }
  else {
   cout << a.at(0) << endl << 0 << endl;;
   }
}
