#include <iostream>

int main()
{
  int A[100];
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i)
  {
    std::cin >> A[i];
  }

  int sw = 0;
  for (int i = 0; i < N - 1; ++i)
  {
    int mini = i;
    for (int j = i + 1; j < N; ++j)
    {
      if (A[mini] > A[j]) mini = j;
    }
    if (i != mini)
    {
      std::swap(A[i], A[mini]);
      ++sw;
    }
  }

  for (int i = 0; i < N; ++i)
  {
    if (i > 0) std::cout << " ";
    std::cout << A[i];
  }
  std::cout << std::endl;
  std::cout << sw << std::endl;

  return 0;
}

