#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++)  cin >> a[i];

  for(int i=0; i<n; i++){
    int j = i;
    while(j > 0){
      if(a[j-1] > a[j])  swap(a[j-1], a[j]);
      else  break;
      j--;
    }
    for(int j=0; j<n; j++)
      printf("%d%c", a[j], j<n-1 ? ' ' : '\n');
  }

  return 0;
}
