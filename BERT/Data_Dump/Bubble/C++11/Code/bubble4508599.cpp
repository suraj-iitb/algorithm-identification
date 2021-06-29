// C++11
#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

int main() {
  int N;
  cin >> N;

  int x[N];
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
  }

  int count = 0;

  for (auto i = 0; i < N; i++) {
    for (auto j = N-1; j > i; j--) {
      if (x[j] < x[j-1]) {
        swap(x[j], x[j-1]);
        count++;
      }
    }
  }

  for (auto i = 0; i < N; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << x[i];
  }
  cout << endl;
  cout << count << endl;

  return 0;
}

