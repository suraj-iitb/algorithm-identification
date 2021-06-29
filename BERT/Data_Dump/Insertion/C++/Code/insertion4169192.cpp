#include <iostream>
using namespace std;
static const int MAX = 1000;

void print_ary(int ary[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (i > 0)
      cout << " ";
    cout << ary[i];
  }
  cout << endl;
}

void insertion_sort(int ary[], int n)
{
  int v, i, j;
  for (i = 1; i < n; i++)
  {
    v = ary[i];
    j = i - 1;

    while (j >= 0 && ary[j] > v)
    {
      ary[j + 1] = ary[j];
      j--;
    }

    ary[j + 1] = v;

    print_ary(ary, n);
  }
}

int main(void)
{
  int i, n, a[MAX];

  cin >> n;
  for (i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  print_ary(a, n);
  insertion_sort(a, n);

  return 0;
}

