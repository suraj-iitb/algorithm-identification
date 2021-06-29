#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long int ll;
#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define repr(i, n, a) for (int i = (n)-1; i >= (a); i--)
#define each(it, v) for (auto(it) = (v).begin(); (it) != (v).end(); (it)++)
#define all(v) (v).begin(), (v).end()
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define co(x) cout << (x)
#define con(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
const int MAXN = 2e5 + 9;
const ll LINF = 1LL << 60;
const int INF = 1 << 30;
//////////////////////////////////////////////////////////////
int n, A[500000], ch = 0;

void Merge(int left, int mid, int right) {
  int n1 = mid - left, n2 = right - mid;
  vector<int> L(n1 + 1, INF), R(n2 + 1, INF);
  for (int i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = A[mid + i];
  for (int i = 0, j = 0, k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    ch++;
  }
}

void MergeSort(int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    MergeSort(left, mid);
    MergeSort(mid, right);
    Merge(left, mid, right);
  }
}
int main() {
  cin >> n;
  rep(i, 0, n) cin >> A[i];
  MergeSort(0, n);
  rep(i, 0, n) cout << A[i] << ((i != n - 1) ? " " : "\n");
  cout << ch << endl;
  return 0;
}
