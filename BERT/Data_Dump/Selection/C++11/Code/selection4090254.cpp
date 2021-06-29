#include <iostream>
using namespace std;

int main() {
  int n, seq[100];
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> seq[i];

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int mini = i;

    for (int j = i; j < n; ++j)
      if (seq[j] < seq[mini])
        mini = j;

    if (mini != i) {
      int tmp = seq[i];
      seq[i] = seq[mini];
      seq[mini] = tmp;
      ++cnt;
    }
  }

  cout << seq[0];
  for (int i = 1; i < n; ++i)
    cout << " " << seq[i];
  cout << endl << cnt << endl;


  return EXIT_SUCCESS;
}
