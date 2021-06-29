#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 103;

int main()
{
  int n;
  vector<int> arr;

  cin >> n;
  arr = vector<int>(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
    cout << arr[i] << (i==n-1?'\n':' ');

  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;

    for (int k = 0; k < n; k++)
      cout << arr[k] << (k==n-1?'\n':' ');
  }

  return EXIT_SUCCESS;
}


