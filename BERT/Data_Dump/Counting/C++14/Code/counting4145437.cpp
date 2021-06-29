#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>

using vector = std::vector<int >;
using iterator = vector::iterator;

auto print_seq = [](auto begin, auto end){
                   while (begin != end){
                     std::cout << *begin;
                     ++begin;
                     if (begin == end) std::cout << std::endl;
                     else std::cout << " ";
                   }
                 };

vector countingSort(iterator begin, iterator end)
{
  auto itr = begin;
  std::array<int, 10001> counts;
  counts.fill(0);

  while (itr != end)
    {
      ++counts[*itr];
      ++itr;
    }

  for (int i=1; i<counts.size(); ++i)
    {
      counts[i] += counts[i-1];
    }

  vector ans(std::distance(begin ,end));
  itr = end-1;
  while (itr >= begin)
    {
      --counts[*itr];
      ans[counts[*itr]] = *itr;
      --itr;
    }

  return ans;
}


int main()
{
  int n;
  vector seq;

  std::cin >> n;
  for(int i=0; i<n; ++i)
    {
      int tmp;
      std::cin >> tmp;
      seq.push_back(tmp);
    }

  auto ans = countingSort(seq.begin(), seq.end());
  print_seq(ans.begin(), ans.end());
}

