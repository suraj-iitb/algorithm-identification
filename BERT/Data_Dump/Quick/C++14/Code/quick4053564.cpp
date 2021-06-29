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

class Card
{
public:
  Card()
    : data(make_pair('\0', 0))
  {}
  Card(const Card& x)
    : data(x.data)
  {}

  pair<char, int> data;
  bool operator < (const Card& y) const
  {
    return this->data.second < y.data.second;
  }
  bool operator <= (const Card& y) const
  {
    return (*this < y) || (this->data.second == y.data.second);
  }
  bool operator == (const Card& y) const
  {
    return (this->data.first == y.data.first) && (this->data.second == y.data.second);
  }
  bool operator != (const Card& y) const
  {
    return !(*this == y);
  }
};

void mergeSort(vector<Card>&, int, int);
void merge(vector<Card>&, int, int, int);
int partition(vector<Card>&, int, int);
void quickSort(vector<Card>&, int, int);


void mergeSort(vector<Card>& A, int l, int r)
{
  if (l + 1 < r)
  {
    int m = (l + r) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);
  }
}

void merge(vector<Card>& A, int l, int m, int r)
{
  int n1 = m - l;
  int n2 = r - m;
  vector<Card> L(n1 + 1), R(n2 + 1);
  rep (i, n1) L[i] = A[l + i];
  rep (i, n2) R[i] = A[m + i];
  L[n1].data = make_pair('A', 1e9 + 1); R[n2].data = make_pair('A', 1e9 + 1);

  int i = 0, j = 0;
  for (int k = l; k < r; ++k)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i++];
    }
    else
    {
      A[k] = R[j++];
    }
  }
}

int partition(vector<Card>& A, int p, int r)
{
  Card x = A[r];
  int i = p - 1;

  for (int j  = p; j < r; ++j)
  {
    if (A[j] <= x)
    {
      ++i;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);

  return i + 1;
}

void quickSort(vector<Card>& A, int p, int r)
{
  if (p < r)
  {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Card> A;
    vector<Card> ref;
    A.resize(n);
    ref.resize(n);
    rep (i, n)
    {
      char c;
      int a;
      cin >> c >> a;
      A[i].data = make_pair(c, a);
      ref[i].data = make_pair(c, a);
    }

    quickSort(A, 0, n - 1);
    mergeSort(ref, 0, n);

    bool stable = true;
    rep (i, n)
    {
      if (A[i] != ref[i])
      {
	stable = false;
	break;
      }
    }
    cout << (stable ? "Stable\n" : "Not stable\n");

    rep (i, n)
    {
      cout << A[i].data.first << " " << A[i].data.second << "\n";
    }
    return 0;
}


