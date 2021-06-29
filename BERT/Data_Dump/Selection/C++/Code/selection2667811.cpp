#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void trace(const vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << ((i != a.size() - 1)? " " : "");
  }
  cout << endl;
}

int selection_sort(vector<int>& a, int n) {
  int times = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (minj != i) times++;
    swap(a[i], a[minj]);
  }
  return times;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i]; 
  }
  int times = selection_sort(a, n);
  trace(a);
  cout << times << endl;
}

