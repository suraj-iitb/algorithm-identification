#include <iostream>

using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  int change_cnt = 0;
  bool flg = true;
  while(flg) {
    flg = false;
    for(int j = n-1; 0 < j; j--) {
      if(a[j] < a[j-1]) {
        int tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;

        change_cnt++;
        flg = true;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    cout << a[i];
    if(i != n-1) cout << " ";
  }
  cout << endl << change_cnt << endl;
  return 0;
}

