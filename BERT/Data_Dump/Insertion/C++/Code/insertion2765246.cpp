#include <iostream>
using namespace std;

void output_array(int arr[], int arr_len)
{
  cout << arr[0];
  for (int i = 1; i < arr_len; ++i)
  {
    cout << ' ' << arr[i];
  }
  cout << endl;
}

void insertion_sort(int arr[], int arr_len)
{
  int i = 0;
  int j = 0;
  int cur_value = 0;

  output_array(arr, arr_len);

  for (i = 1; i < arr_len; ++i)
  {
    cur_value = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > cur_value)
    {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = cur_value;
    output_array(arr, arr_len);
  }
}

int main()
{
  int n = 0;
  cin >> n;

  // Initialization of nums array
  int nums[n];
  int cur_num;
  for (int i = 0; i < n; ++i)
  {
    cin >> cur_num;
    nums[i] = cur_num;
  }

  insertion_sort(nums, n);

  return 0;
}
