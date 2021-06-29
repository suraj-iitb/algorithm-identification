#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> data) {
  int n = data.size();
  int cnt = 0;
  for (int i = 0; i < n; i++) { // i: 未ソート部分の先頭
    for (int j = n-1; j > i; j--) {
      if (data[j] < data[j-1]) {
        std::swap(data[j], data[j-1]);
        cnt++;
      }
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

  bubbleSort(data);

  return 0;
}

