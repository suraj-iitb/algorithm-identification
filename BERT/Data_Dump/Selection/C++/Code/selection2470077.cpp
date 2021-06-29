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
  int minj = 0;
  for (int i=0;i<n;i++){
      int minj = i;
      for (int j=i+1;j<n;j++){
          if (a[j] < a[minj]){
              minj = j;
          }
      }
      if (i!=minj) {
          swap(a[i],a[minj]);
          cnt++;
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
