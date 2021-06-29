#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> data) {
  int n = data.size();
  int cnt = 0;
  for (int i = 0; i < n; i++) { // i: 未ソート部分の先頭
    int minj = i;
    for (int j = i; j < n; j++) {
      if (data[minj] > data[j]) {
        minj = j;
      }
    }
    if (i != minj) {
      std::swap(data[i], data[minj]);
      cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << data[i] << (i == n-1 ? "\n" : " ");
  }
  cout << cnt << endl;
}

int main() {
  int n; cin >> n;
  vector<int> data(n);

  for (int i = 0; i < n; i++) {
    cin >> data[i];
  }

  selectionSort(data);

  return 0;
}
