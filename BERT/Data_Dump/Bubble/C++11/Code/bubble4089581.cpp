#include <iostream>
using namespace std;

int main() {
  int n;
  int data[100] = {};

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> data[i];

  int c = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; 0 < j; --j) {
      if (data[j] < data[j-1]) {
        int tmp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = tmp;
        ++c;
      }
    }
  }

  cout << data[0];
  for (int i = 1; i <  n; ++i)
    cout << " " << data[i];
  cout << endl << c << endl;

  return EXIT_SUCCESS;
}

