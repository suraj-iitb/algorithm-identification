#include<iostream>
#include<algorithm>

static const int N = 10000;
using namespace std;
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i =0;i<n;i++){
      cin >> a[i];
  }
  int cnt=0;
  
  for (int i=0;i<n;i++){
      for (int j=n-1;j>=i+1;j--){
          if (a[j] < a[j-1]){
              swap(a[j],a[j-1]);
              cnt++;
          }
      }
   }
  
  for (int i=0;i<n;i++) {
    if(i == n - 1) {
            cout << a[i] << endl;
    } else {
            cout << a[i] << " ";
    }
    }
  cout << cnt << endl;
  return 0;
}
