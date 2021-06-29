#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int values[], int n) {
  bool flag = true;
  int switch_count = 0;
  while(flag) {
    flag = false;
    for (int j = n - 1; j > 0; j--) {
      if (values[j] < values[j - 1]) {
        int values_j = values[j];
        values[j] = values[j - 1];
        values[j - 1] = values_j;
        flag = true;
        switch_count++;
      }
    }
  }
  return switch_count;
}

int main() {
  int n;
  cin >> n;
  int values[n];

  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  int switch_count = bubbleSort(values, n);

  for (int j = 0; j < n - 1; j++) {
    cout << values[j] << " ";
  }
  cout << values[n - 1] << endl;
  cout << switch_count << endl;

}

