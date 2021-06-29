#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }

  for (int i = 1; i < n; i++) {
    int a = vec.at(i);
    int j = i;

    for (int k = 0; k < n-1; k++) {
      cout << vec.at(k) << " ";
    }
    cout << vec.at(n-1) << endl;

    while (j > 0 && vec.at(j) < vec.at(j-1)) {
      vec.at(j) = vec.at(j-1);
      vec.at(j-1) = a;
      j--;
    }
  }
  for (int k = 0; k < n-1; k++) {
    cout << vec.at(k) << " ";
  }
  cout << vec.at(n-1) << endl;
}

