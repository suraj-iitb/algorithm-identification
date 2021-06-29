#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
    if (i != n - 1) {
        cout << " ";
    }
  }
  cout << endl;
}

void insertionSort(int arr[], int n)
{
  for (int i = 1; i <= n; i++)
  {
    printArray(arr, n);
    int v = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > v)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = v;
  }
}

int main()
{
  int n;
  cin >> n;
  int nums[n];
  for (int i = 1; i <= n; i++)
  {
    cin >> nums[i - 1];
  }
  insertionSort(nums, n);
  return 0;
}

