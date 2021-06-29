#include <iostream>
using namespace std;

int main() {
  int N, j, v;
  cin >> N;
  int s[N];

  for (size_t i = 0; i < N; i++) {
    cin >> s[i];
  }

  for (size_t i = 0; i < N; i++) {
    v = s[i];
    j = i-1;
    while (j >= 0 && s[j] > v) {
      s[j+1] = s[j];
      j -= 1;
    }
    s[j+1] = v;
    for (size_t i = 0; i < N; i++) {
      cout << s[i];
      if (i < N-1) {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
