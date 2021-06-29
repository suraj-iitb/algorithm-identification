#include <stdio.h>
#include <vector>
#include <utility>

int bubble_sort(std::vector<int>& arr)
{
  using std::swap;
  int swap_num = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = arr.size() - 1; j > i; j--) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
        swap_num++;
      }
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

  int n = bubble_sort(arr);

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

