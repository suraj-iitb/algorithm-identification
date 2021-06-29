#include <stdio.h>
#include <vector>
#include <utility>

int selection_sort(std::vector<int>& arr)
{
  using std::swap;
  int swap_num = 0;
  for (int i = 0; i < arr.size() - 1; i++) {
    int minv = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[minv] > arr[j]) {
        minv = j;
      }
    }
    if (i != minv) {
      swap(arr[i], arr[minv]);
      swap_num++;
    }
  }
  return swap_num;
}

int main()
{
  int N;
  std::vector<int> arr;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int temp;
    scanf("%d", &temp);
    arr.push_back(temp);
  }

  int n = selection_sort(arr);

  for (int i = 0; i < arr.size(); i++) {
    if (i == arr.size() - 1) {
      printf("%d\n", arr[i]);
    }
    else {
      printf("%d ", arr[i]);
    }
  }
  printf("%d\n", n);

  return 0;
}

