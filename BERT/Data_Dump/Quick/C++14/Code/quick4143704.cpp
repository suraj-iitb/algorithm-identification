#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using vector = std::vector<std::pair<char, int> >;
using iterator = vector::iterator;

auto print_pair = [](auto x){std::cout << x.first << " " << x.second;};

auto print_vector = [](iterator begin, iterator end){
                      while (begin != end)
                        {
                          print_pair(*begin);
                          std::cout << std::endl;
                          begin++;
                        }
                    };


iterator partition(iterator begin, iterator end)
{
  auto pivot = *(end-1);
  auto swap = [](iterator a, iterator b){
                auto tmp = *a;
                *a = *b;
                *b = tmp;
              };

  auto left_end = begin - 1;
  for (auto itr = begin; itr<end; ++itr)
    {
      if ((*itr).second <= pivot.second)
        {
          ++left_end;
          swap(itr, left_end);
        }
    }

  return left_end;
}

int merge(iterator begin, iterator mid, iterator end)
{
  auto itr = begin;

  vector left, right;

  for (auto tmp=begin; tmp<mid; ++tmp) left.push_back(*tmp);
  for (auto tmp=mid; tmp<end; ++tmp) right.push_back(*tmp);
  left.push_back(std::make_pair('Z', 1000000001));
  right.push_back(std::make_pair('Z', 1000000001));

  auto itr_left = left.begin();
  auto itr_right = right.begin();

  int ncomp = 0;
  while (itr != end)
    {
      if ((*itr_left).second <= (*itr_right).second)
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



void quicksort(iterator begin, iterator end)
{
  if (begin+1 == end) return;
  auto mid = partition(begin, end);
  quicksort(begin, mid);
  quicksort(mid, end);
}

int main ()
{
  int n;
  vector vec;

  std::cin >> n;
  for (int i=0; i<n; ++i)
    {
      char tmpchar;
      int tmpint;
      std::cin >> tmpchar >> tmpint;
      vec.push_back(std::make_pair(tmpchar, tmpint));
    }

  vector vec_cp = vec;

  quicksort(vec.begin(), vec.end());
  mergeSort(vec_cp.begin(), vec_cp.end());
  if (vec == vec_cp) std::cout << "Stable\n";
  else std::cout << "Not stable\n";

  //std::cout << "quicksort\n";
  print_vector(vec.begin(), vec.end());

  //std::cout << "mergeSort\n";
  //print_vector(vec_cp.begin(), vec_cp.end());
}


