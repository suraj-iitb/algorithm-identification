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

tuple<vector<int>, int> bubble_sort(vector<int> a, int n)
{
  auto flag = 1;
  auto count = 0;
  while (flag)
  {
    flag = 0;
    for (auto j = n - 1; j >= 1; j--)
    {
      if (a[j] < a[j - 1])
      {
        auto temp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = temp;
        flag = 1;
        count++;
      }
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

  auto result = bubble_sort(a, n);
  print_vector(std::get<0>(result));
  cout << std::get<1>(result) << endl;

  return 0;
}

