#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &data) {
  int n = data.size();
  for (int i = 0; i < n; i++) {
    cout << data[i] << (i == n-1 ? "\n" : " ");
  }
  for (int i = 1; i < n; i++) {
    int tmp = data[i];
    int j = i-1;
    while (j >= 0 && data[j] > tmp) {
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = tmp;
    for (int i = 0; i < n; i++) {
      cout << data[i] << (i == n-1 ? "\n" : " ");
    }
  }
}

int main() {
  int n; cin >> n;

  vector<int> data(n);
  for (int i = 0; i < n; i++) {
    cin >> data[i];
  }

  insertionSort(data);

  return 0;
}

