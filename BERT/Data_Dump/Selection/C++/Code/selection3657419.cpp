#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i=0;i<n;i++){
    cin >> a[i];
  }
  int count = 0;
  for (int i=0;i<n;i++) {
    int minj = i;
    for (int j=i;j<n;j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      int tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      count += 1;
    }
  }
  cout << a[0];
  for (int i=1;i<n;i++){
    cout << ' ' << a[i];
  }
  cout << endl << count << endl;
}
