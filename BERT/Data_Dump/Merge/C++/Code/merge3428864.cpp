#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
const int INF = 1<<30;

const int MAX = 500010;
int ls[MAX], rs[MAX];

void merge(vector<int> &arr, int left, int mid, int right)
{
  int n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  for (int i = 0; i < n1; i++)
    ls[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    rs[i] = arr[mid + i];
  ls[n1] = INF;
  rs[n2] = INF;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if (ls[i] <= rs[j]) {
      arr[k] = ls[i];
      i++;
    } else {
      arr[k] = rs[j];
      j++;
    }
  }
}

void merge_sort(vector<int> &arr, int left, int right)
{
  if (left+1 < right) {
    int mid = (left + right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid, right);
    merge(arr, left, mid, right);
  }
}

int main()
{
  int n; cin >> n;
  vector<int> arr = vector<int>(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  merge_sort(arr, 0, arr.size());

  for (int i = 0; i < n; i++)
    cout << arr[i] << (i==n-1?'\n':' ');
  cout << cnt << endl;

  return EXIT_SUCCESS;
}


