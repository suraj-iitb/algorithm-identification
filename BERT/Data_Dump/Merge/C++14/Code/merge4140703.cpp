#include <iostream>
#include <vector>
#include <algorithm>

using vector = std::vector<int>;
using iterator = vector::iterator;

auto print_vector = [](iterator begin, iterator end){
                      while (begin != end)
                        {
                          if (begin+1 < end) std::cout << *begin << " ";
                          else std::cout << *begin << std::endl;
                          ++begin;
                        }
                    };

int merge(iterator begin, iterator mid, iterator end)
{
  auto itr = begin;

  vector left, right;

  for (auto tmp=begin; tmp<mid; ++tmp) left.push_back(*tmp);
  for (auto tmp=mid; tmp<end; ++tmp) right.push_back(*tmp);
  left.push_back(1000000001);
  right.push_back(1000000001);

  // std::cout << "Merging...\n";
  // print_vector(left.begin(), left.end());
  // print_vector(right.begin(), right.end());

  auto itr_left = left.begin();
  auto itr_right = right.begin();

  int ncomp = 0;
  while (itr != end)
    {
      if (*itr_left <= *itr_right)
        {
          *itr = *itr_left;
          ++itr_left;
        }
      else
        {
          *itr = *itr_right;
          ++itr_right;
        }
      ++itr;
      ++ncomp;
    }
  // std::cout << "...finish\n";
  // print_vector(begin, end);

  return ncomp;
}

int mergeSort(iterator begin, iterator end)
{
  if ((begin+1) == end)
    {
      return 0;
    }

  auto n = std::distance(begin, end);
  auto mid = begin + n/2;

  int nct;
  nct = mergeSort(begin, mid);
  nct += mergeSort(mid, end);
  nct += merge(begin, mid, end);

  return nct;
}


int main ()
{
  int n;
  std::cin >> n;
  vector seq;

  for (int i=0; i<n; i++)
    {
      int tmp;
      std::cin >> tmp;
      seq.push_back(tmp);
    }

  auto ncomp = mergeSort(seq.begin(), seq.end());

  print_vector(seq.begin(), seq.end());
  std::cout << ncomp << std::endl;
}

