#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int n,a[100],ans=0,mini;
  cin >> n;
  for(int i=0; i<n; i++) {
      cin >> a[i];
  }
  for(int i=0; i<n; i++) {
      mini=i;
      for(int j=i; j<n; j++) {
          if(a[mini]>a[j]) {
              mini=j;
          }
      }
      if(mini!=i) {
          swap(a[i],a[mini]);
          ans++;
      }
  }
  for(int i=0; i<n-1; i++) {
      cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  cout << ans << endl;
}
