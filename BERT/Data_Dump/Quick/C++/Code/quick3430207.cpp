#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

typedef struct {
  char suit;
  int num;
} elem;

int partition(vector<elem> &arr, int p, int r)
{
  int i = p, x = arr[r-1].num;
  for (int j = p; j < r; j++)
    if (arr[j].num <= x)
      swap(arr[i++], arr[j]);
  return i-1;
}

void quick_sort(vector<elem> &arr, int p, int r)
{
  if (p < r) {
    int q = partition(arr, p, r);
    quick_sort(arr, p, q);
    quick_sort(arr, q+1, r);
  }
}

bool eq(elem a, elem b)
{
  return a.suit == b.suit && a.num == b.num;
}

bool is_stable(vector<elem> &qsorted, vector<elem> &msorted)
{
  for (int i = 0; i < qsorted.size(); i++)
    if (!eq(qsorted[i], msorted[i]))
      return false;
  return true;
}


vector<elem> ls, rs;

void merge(vector<elem> &as, int left, int mid, int right)
{
  int l_size = mid - left;
  int r_size = right - mid;
  copy(as.begin()+left, as.begin()+left+l_size, ls.begin());
  copy(as.begin()+mid, as.begin()+mid+r_size, rs.begin());
  ls[l_size] = (elem){ 'Z', INF };
  rs[r_size] = (elem){ 'Z', INF };

  for (int i = left, li = 0, ri = 0; i < right; i++) {
    if (ls[li].num <= rs[ri].num)
      as[i] = ls[li++];
    else
      as[i] = rs[ri++];
  }
}

void merge_sort(vector<elem> &as, int left, int right)
{
  if (left+1 == right) return;
  int mid = left+(right-left)/2;
  merge_sort(as, left, mid);
  merge_sort(as, mid, right);
  merge(as, left, mid, right);
}


int main()
{
  int n; cin >> n;
  vector<elem> arr1 = vector<elem>(n);
  vector<elem> arr2 = vector<elem>(n);
  ls = vector<elem>(n/2+1);
  rs = vector<elem>(n/2+1);
  for (int i = 0; i < n; i++) {
    char suit; int num;
    cin >> suit >> num;
    arr1[i] = (elem){ suit, num };
  }
  copy(arr1.begin(), arr1.end(), arr2.begin());
  quick_sort(arr1, 0, n);
  merge_sort(arr2, 0, n);

  cout << (is_stable(arr1, arr2)?"Stable":"Not stable") << endl;
  for (int i = 0; i < n; i++)
    printf("%c %d\n", arr1[i].suit, arr1[i].num);
  return EXIT_SUCCESS;
}
