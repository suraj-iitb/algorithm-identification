#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, count = 0;
  int a[100];

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = n - 1; i > 0; i--) {
      if (a[i] < a[i - 1]) {
        swap(a[i], a[i - 1]);
        flag = true;
        count++;
      }
    }
  }

  for (int i = 0; i < n; i++) cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  cout << count << endl;

  return 0;
}

