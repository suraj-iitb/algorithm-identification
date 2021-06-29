#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void output_array(vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
    cout << (i ? " " : "") << v[i];
  cout << "\n";
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];

  output_array(x);

  for (int i = 1; i < n; i++)
  {
    int v = x[i];
    int j;
    for (j = i - 1; j >= 0 && x[j] > v; j--)
    {
      x[j + 1] = x[j];
    }
    x[j + 1] = v;
    output_array(x);
  }

  return 0;
}

