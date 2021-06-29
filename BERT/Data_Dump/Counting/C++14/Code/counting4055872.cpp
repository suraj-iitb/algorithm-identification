#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

void CountingSort(vs32& A, vs32& B, int k)
{
  vs32 C(k + 1, 0);
  rep (i, A.size())
  {
    ++C[A[i]];
  }

  rep (i, k)
  {
    C[i + 1] += C[i];
  }

  for (int i = A.size() - 1; i >= 0; --i)
  {
    B[C[A[i]]] = A[i];
    --C[A[i]];
  }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vs32 A(n);
    vs32 B(n + 1);
    int k = 0;
    rep (i, n)
    {
      cin >> A[i];
      k = MAX(k, A[i]);
    }

    CountingSort(A, B, k);

    rep (i, n)
    {
      if (i > 0) cout << " ";
      cout << B[i + 1];
    }

    cout << "\n";
    return 0;
}

