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

int selection_sort(int arr[], int arr_len)
{
  int swap_count = 0;

  for (int i = 0; i < arr_len; ++i)
  {
    int min_index = i;

    for (int j = i; j < arr_len; ++j)
    {
      // Update min_index
      if (arr[j] < arr[min_index])
      {
        min_index = j;
      }
    }

    // If arr[i] is not the minimum element,
    // then swap the two elements
    if (i != min_index)
    {
      swap(arr[i], arr[min_index]);
      ++swap_count;
    }
  }

  return swap_count;
}

int main()
{
  // Initialization
  int n;
  cin >> n;

  int num ,nums[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> num;
    nums[i] = num;
  }

  int swap_count = selection_sort(nums, n);

  output_array(nums, n);
  cout << swap_count << endl;

  return 0;
}
