#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int l, i = 0, a[n];
  while (cin>>l){
    a[i] = l;
    i ++;
    if(i>=n){
      break;
    }
  }
 
  for (int k = 0; k<n; k++){
    if (k) cout<<' ';
    cout << a[k];
  }
  cout << endl;
   
  for (int i = 1; i<n; i++){
    int v = a[i];
    int j = i - 1;
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for (int k = 0; k<n; k++){
      if (k) cout<<' ';
      cout << a[k];
    }
    cout << endl;
  }
  return 0;
}
