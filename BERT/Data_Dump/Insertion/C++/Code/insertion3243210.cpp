#include <stdio.h>
#include <vector>

void output(std::vector<int>& arr)
{
  for (int i = 0; i < arr.size(); i++) {
    if (i == arr.size() - 1) {
      printf("%d\n", arr[i]);
    }
    else {
      printf("%d ", arr[i]);
    }
  }
}

void insertion_sort(std::vector<int>& arr)
{
  output(arr);
  for (int i = 1; i < arr.size(); i++) {
    int val = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > val) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = val;

    output(arr);
  }
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

  insertion_sort(arr);

  return 0;
}

