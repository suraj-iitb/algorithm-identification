#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, count = 0;
  int a[100];

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[minj]) minj = j;
    }

    if (i != minj) {
      swap(a[i], a[minj]);
      count++;
    }
  }

  for (int i = 0; i < n; i++) cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  cout << count << endl;
  return 0;
}

