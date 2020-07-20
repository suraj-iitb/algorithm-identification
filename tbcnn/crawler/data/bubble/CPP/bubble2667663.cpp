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

int bubble_sort(vector<int>& a) {
  bool flag = true;
  int count = 0;
  while (flag) {
    flag = false;
    for (int j = a.size() - 1; j >= 1; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        flag = true;
        count++;
      }
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  vector<int> a;
  while (n--) {
    int i;
    cin >> i;
    a.push_back(i);
  }
  int count = bubble_sort(a);
  trace(a);
  cout << count << endl;
}

