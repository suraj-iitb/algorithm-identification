#include <iostream>
#include <vector>

void vector_output(std::vector<int> src)
{
  size_t N = src.size();
  for(size_t i = 0; i < N-1; ++i)
  {
    std::cout << src[i] << " ";
  }
  std::cout << src[N-1] << std::endl;
}

int main()
{
  // 要素数の取得
  int N;
  std::cin >> N;

  // 要素の取得
  std::vector<int> A(N);
  for(int idx = 0; idx < N; ++idx)
  {
    std::cin >> A[idx];
  }

  //挿入ソート
  for(int i = 1; i < N; ++i)
  {
    // 出力
    vector_output(A);
    // ソーティング
    int v = A[i];
    int j = i - 1;
    while((j>=0)&&(A[j]>v))
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }

  // 出力
  vector_output(A);
  return 0;
}

