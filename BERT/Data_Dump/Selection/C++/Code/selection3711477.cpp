#include <bits/stdc++.h>
using namespace std;

int selectionSort(int target[], int count) {
  int total = 0;
  for (int i = 0; i < count; i++) {
    int minj = i;
    for (int j = i; j < count; j++) {
      if (target[j] < target[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      total++;
      swap(target[i], target[minj]);
    }
  }
  return total;
};

int main() {
  int count;
  cin >> count;
  int result[count];
  for (size_t i = 0; i < count; i++) {
    cin >> result[i];
  }

  int total = selectionSort(result, count);
  for (size_t i = 0; i < count; i++) {
    cout << result[i];
    if (i == count - 1) cout << endl;
    if (i != count - 1) cout << " ";
  }
  cout << total << endl;
  return 0;
}
