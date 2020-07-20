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
    for (int j = n-1; j > i; j--) {
      if (arr[j] < arr[j-1]) {
        swap(arr[j], arr[j-1]);
        swap_cnt++;
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << (i==n-1?'\n':' ');
  cout << swap_cnt << endl;

  return EXIT_SUCCESS;
}


