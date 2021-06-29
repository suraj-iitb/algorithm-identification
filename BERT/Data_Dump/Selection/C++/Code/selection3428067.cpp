#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  vector<int> arr;

  cin >> n;
  arr = vector<int>(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int swap_cnt = 0;
  for (int i = 0; i < n; i++) {
    int min_i = i;
    for (int j = i; j < n; j++) {
      if (arr[j] < arr[min_i])
        min_i = j;
    }
    if (i != min_i) {
      swap(arr[i], arr[min_i]);
      swap_cnt++;
    }
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << (i==n-1?'\n':' ');
  cout << swap_cnt << endl;

  return EXIT_SUCCESS;
}


