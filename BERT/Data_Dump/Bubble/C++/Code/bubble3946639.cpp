#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < A.size(); i++) {
    cin >> A.at(i);
  }

  int flag = 1;
  int swapTimes = 0;
  int i = 0;
  while (flag) {
    flag = 0;
    for (int j = N - 1; j > i; j--) {
      if (A.at(j) < A.at(j - 1)){
        swap(A.at(j), A.at(j - 1));
        flag = 1;
        swapTimes++;
      }
    }
    i++;
  }

  for (int i = 0; i < A.size(); i++) {
    cout << A.at(i);
    if (i < A.size() - 1) {
      cout << " ";
    }
    else {
      cout << endl;
    }
  }

  cout << swapTimes << endl;

  return 0;
}
