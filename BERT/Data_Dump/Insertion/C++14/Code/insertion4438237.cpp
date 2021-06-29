#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (auto& item : A) {
    cin >> item;
  }

  auto display = [&]() { 
    const char* sep = "";
    for (auto& item : A) {
      cout << sep << item;
      sep = " ";
    }
    cout << endl;
  };

  display();
  for (int i = 1; i < N; ++i) {
    int tmp = A[i];
    int j = i;
    while (0 < j) {
      if (A[j - 1] < tmp) {
        break;
      }
      A[j] = A[j - 1];
      --j;
    }
    A[j] = tmp;
    display();
  }
  return 0;
}

