
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i = 0; i < n; i++) cin >> a[i];  
    for(int i = 0; i < a.size(); i++) {
      cout << a[i];
      if(i != a.size()-1) cout << " ";
    }
      cout << endl;
  for(int i = 1; i < a.size(); i++){
    int v = a[i];
    int j = i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
   for(int i = 0; i<n; i++) {
       cout << a[i];
       if(i != n-1) cout <<" ";
   }
   cout << endl;
  }
}

