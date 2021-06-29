#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>
#include <ctype.h>
#include <numeric>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

int dx4[4] = { 0, -1, 1, 0 };
int dy4[4] = { -1, 0, 0, 1 };
int dx8[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };
int dy8[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };

int selectionSort(vector<int>& a, int n) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (i != minj) ++count;
    swap(a[i], a[minj]);
  }
  return count;
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int res = selectionSort(arr, n);
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i == n - 1) break;
    cout << " ";
  }
  cout << endl << res << endl;
  return 0;
}

