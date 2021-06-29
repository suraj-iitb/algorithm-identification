#include <iostream>
#include <array>
#include <algorithm>

auto read = [](auto &x){std::cin >>x;};
auto readSeq = [](auto *begin, auto *end){
                  std::for_each(begin, end, read);
                };
auto printSeq = [](auto *begin, auto *end){
                   std::for_each(begin, end-1, [](auto x){std::cout<<x<<" ";});
                   std::cout << *(end-1) <<  std::endl;
                 };

int bubbleSort(int *begin, int *end);

int main ()
{
  int n;
  const int max_n = 100;
  std::array<int, max_n> arr;

  read(n);
  readSeq(arr.begin(), arr.begin()+n);

  auto cnt = bubbleSort(arr.begin(), arr.begin()+n);


  printSeq(arr.begin(), arr.begin()+n);
  std::cout << cnt << std::endl;

  return 0;
}

int bubbleSort(int *begin, int *end)
{
  auto swap = [](auto &a, auto &b){
                auto tmp = a;
                a = b;
                b =tmp;
              };

  auto n = std::distance(begin, end);
  auto itr = begin;

  auto cnt = 0;

  for (int i=0; i<n; i++)
    {
      for (int j=n-1; j>i; j--)
        {
          if (itr[j-1] > itr[j])
            {
              swap(itr[j-1], itr[j]);
              cnt++;
            }
        }
    }

  return cnt;
}

