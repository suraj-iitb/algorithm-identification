#include "bits/stdc++.h"
using namespace std;

string join_vector(std::vector<int> data)
{
  ostringstream buf;
  auto delimiter = " ";
  for (auto i = data.begin(); i != data.end(); i++)
  {
    buf << *i;
    if (std::distance(i, data.end()) > 1)
    {
      buf << delimiter;
    }
  }

  return buf.str();
}

void print_vector(std::vector<int> data)
{
  cout << join_vector(data) << endl;
}

tuple<vector<int>, int> selection_sort(vector<int> a, int n)
{
  auto count = 0;
  for (auto i = 0; i < n; i++)
  {
    auto minj = i;
    for (auto j = i; j < n; j++)
    {
      if (a.at(minj) > a.at(j))
      {
        minj = j;
      }
    }

    if (minj != i)
    {
      swap(a[i], a[minj]);
      count++;
    }
  }

  return make_tuple(a, count);
}

int main()
{
  int n;
  auto a = std::vector<int>{};

  cin >> n;
  for (auto i = 0; i < n; i++)
  {
    int number;
    cin >> number;
    a.push_back(number);
  }

  auto result = selection_sort(a, n);
  print_vector(std::get<0>(result));
  cout << std::get<1>(result) << endl;

  return 0;
}

