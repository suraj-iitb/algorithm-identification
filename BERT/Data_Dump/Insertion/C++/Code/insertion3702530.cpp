#include <bits/stdc++.h>

using namespace std;

void insertionSort(int target[], int n) {
  for (int i = i; i < n; i++) {
    int v = target[i];
    int j = i - 1;
    while (j >= 0 && target[j] > v) {
      target[j + 1] = target[j];
      j--;
    }
    target[j + 1] = v;

    for (int k = 0; k < n; k++) {
      cout << target[k];

      if (k == n - 1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
};

int main() {
  int num;
  cin >> num;
  int R[num];
  for (int i = 0; i < num; i++) cin >> R[i];

  insertionSort(R, num);
  return 0;
}

