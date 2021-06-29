#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <set>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;
template<class In>
void print_array(In begin, In end) {
  cout << (*begin);
  begin++;
  for (; begin != end; begin++)
  {
    cout << " " << (*begin);
  }
  cout << endl;
}
int main()
{
  ll N;
  cin >> N;
  vector<ll> as(N);
  for (auto i = 0; i < N; i++)
    cin >> as[i];

  ll num_swap = 0;
  bool issorted = false;
  while (!issorted) {
    issorted = true;
    for (auto i = N - 1; i > 0; i--)
    {
      if (as[i-1] > as[i]) {
        ll tmp = as[i];
        as[i] = as[i - 1];
        as[i - 1] = tmp;
        num_swap++;
        issorted = false;
      }
    }
  }
  print_array(as.begin(), as.end());

  cout << num_swap << endl;

  return 0;
}

