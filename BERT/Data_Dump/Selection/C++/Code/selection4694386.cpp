#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int n;
    cin >> n;
    vector<int> a(n);
    
  rep(i,n) {
   cin >> a[i];
  }
    
    int count = 0;
    
    for(int i = 0; i< n; i++) {
     int minj = i;
      for(int j = i; j < n; j++){
       if(a[j] < a[minj]){
        minj = j;
       }
    }
       if(a[i] != a[minj]) {
           swap(a[i],a[minj]);
            count++;
                           }
    }
    
    rep(i,n-1){
     cout << a[i] << ' ';
    }
    cout << a[n-1] << endl;
    cout << count<< endl;
    
       
}
