#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int values[n];

  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  for (int j = 0; j < n - 1; j++) {
    cout << values[j] << " ";
  }
  cout << values[n - 1] << endl;

  for (int i = 1; i < n; i++) {
    int value = values[i];
    int j = i - 1;
    while (j >= 0 && values[j] > value) {
      values[j + 1] = values[j];
      j--;
    }
    values[j + 1] = value;

    for (int j = 0; j < n - 1; j++) {
      cout << values[j] << " ";
    }
    cout << values[n - 1] << endl;
  }
}

