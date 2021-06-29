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

int main()
{
  int n;
  auto vec = std::vector<int>{};

  cin >> n;
  for (auto i = 0; i < n; i++)
  {
    int number;
    cin >> number;
    vec.push_back(number);
  }

  print_vector(vec);
  for (auto i = 1; i < n; i++)
  {
    auto v = vec.at(i);
    auto j = i - 1;
    for (; j >= 0 && vec.at(j) > v;)
    {
      vec[j + 1] = vec[j];
      j--;
    }

    vec[j + 1] = v;
    print_vector(vec);
  }

  return 0;
}

