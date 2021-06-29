#include <iostream>

int main()
{
  int N;
  int A[100];
  std::cin >> N;
  for (int i = 0; i < N; ++i)
  {
    std::cin >> A[i];
    std::cout << A[i];
    if (i < N - 1)
      std::cout << ' ';
  }
  std::cout << std::endl;

  for (int i = 1; i < N; ++i)
  {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v)
    {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = v;
    
    for (int i = 0; i < N; ++i)
    {
      std::cout << A[i];
      if (i < N - 1)
      {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}
/*
1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]
4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v
*/

