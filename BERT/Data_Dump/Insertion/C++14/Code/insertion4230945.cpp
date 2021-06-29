#include <bits/stdc++.h>
using namespace std;

void insert_sort(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
      int key = a[i];
      int j = i - 1;
      while (j >= 0 && a[j] > key) {
          a[j+1] = a[j];
          j--;
      }
      a[j+1] = key;
      for (int j = 0; j < a.size(); j++) {
        cout << a[j];
        if (j != a.size() - 1) cout << " ";
      }
      cout << endl;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
      cin >> a.at(i);
  }
  insert_sort(a);
}
