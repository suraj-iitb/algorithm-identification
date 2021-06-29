#include <iostream>

void dump(int* A, int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (i > 0) std::cout << " ";
    std::cout << A[i];
  }
  std::cout << std::endl;
}

int main()
{
  int A[110];
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i)
  {
    std::cin >> A[i];
  }

  dump(A, N);

  for (int i = 1; i < N; ++i)
  {
    int val = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > val)
    {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = val;
    dump(A, N);
  }

  return 0;
}

