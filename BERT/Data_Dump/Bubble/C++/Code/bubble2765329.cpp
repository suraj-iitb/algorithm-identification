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

int bubble_sort(int arr[], int arr_len)
{
  // Check if there are reversed elements
  bool rev_flag = true;
  int sort_count = 0;

  for (int i = 0; i < arr_len; ++i)
  {
    rev_flag = false;

    // Check un-ordered area sequentially
    for (int j = arr_len - 1; j > i; --j)
    {
      // If a reversed is found, then
      //  - flag ON
      //  - swap the elements
      //  - increment the counter
      if (arr[j - 1] > arr[j])
      {
        rev_flag = true;
        swap(arr[j - 1], arr[j]);
        ++sort_count;
      }
    }

    // If there is no reversed element, then leave the loop
    if (!rev_flag)
    {
      break;
    }
  }

  return sort_count;
}

int main()
{
  int n;
  cin >> n;

  int arr[100];
  int arr_elm;
  for (int i = 0; i < n; ++i)
  {
    cin >> arr_elm;
    arr[i] = arr_elm;
  }

  int count = bubble_sort(arr, n);
  output_array(arr, n);
  cout << count << endl;

  return 0;
}

