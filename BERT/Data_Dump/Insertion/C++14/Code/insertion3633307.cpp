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

  vector<ll> arr(N);
  for (auto i = 0; i < N; i++) cin >> arr[i];

  for (auto i = 0; i < N; i++) {
    ll v = arr[i];
    auto j = i - 1;
    for (; j >= 0 && v < arr[j]; j--)
    {
      arr[j + 1] = arr[j];
    }
    arr[j+1] = v;

    // print
    print_array(arr.begin(), arr.end());
  }

  return 0;
}

