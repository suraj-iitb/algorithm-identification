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

void insertionSort(int *begin, int *end);

int main ()
{
  int n;
  const int max_n = 100;
  std::array<int, max_n> arr;

  read(n);
  readSeq(arr.begin(), arr.begin()+n);

  insertionSort(arr.begin(), arr.begin()+n);


  printSeq(arr.begin(), arr.begin()+n);

  return 0;
}

void insertionSort(int *begin, int *end)
{
  auto n = std::distance(begin, end);
  auto itr = begin;

  for (int i=1; i<n; i++)
    {
      printSeq(begin, end);
      auto temp = itr[i];
      int j=i-1;

      while ((itr[j] > temp) && (j>=0))
        {
          itr[j+1] = itr[j];
          j--;
        }
      itr[j+1] = temp;
    }
}

