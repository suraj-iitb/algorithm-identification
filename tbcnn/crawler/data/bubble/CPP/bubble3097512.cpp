#include <iostream>
using namespace std;

int main() {
  int i;
  cin >> i;
  int n[i];
  for (int x=0; x<i; x++) {
    cin >> n[x];
  }
  int tmp, k=0; // kは交換回数
  bool m=true;
  while (true) {
    for (int x=0; x<i-1; x++) {
      if (n[x]>n[x+1]) {
        tmp = n[x];
        n[x] = n[x+1];
        n[x+1] = tmp;
        k++;
        m=false;
      }
    }
    if (m) {
      break;
    } else {
      m = true;
    }
  }
  //処理完了
  for (int x=0; x<i; x++) {
    if (x!=0) {
      cout << ' ';
    }
    cout << n[x];
  }
  cout << endl << k << endl;
  return 0;
}

