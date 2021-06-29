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

  bool ordered = false;
  int i = N - 1;
  int sw = 0;
  while (i > 0 && !ordered)
  {
    ordered = true;
    for (int j = 0; j < i; ++j)
    {
      if (A[j] > A[j + 1])
      {
        std::swap(A[j], A[j + 1]);
        ordered = false;
        ++sw;
      }
    }
    --i;
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

