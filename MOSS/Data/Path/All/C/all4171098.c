#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

static const int MAX = 100;
static const long long INFTY = (1LL << 32);

int n;
long long D[MAX][MAX];

void floyd()
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      if (D[i][k] == INFTY)
      {
        continue;
      }
      for (int j = 0; j < n; j++)
      {
        if (D[k][j] == INFTY)
        {
          continue;
        }
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }
}

int main()
{
  int e, s, t, d;
  cin >> n >> e;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      D[i][j] = ((i == j) ? 0 : INFTY);
    }
  }
  for (int i = 0; i < e; i++)
  {
    cin >> s >> t >> d;
    D[s][t] = d;
  }

  floyd();

  bool negative = false;
  for (int i = 0; i < n; i++)
  {
    if (D[i][i] < 0)
    {
      negative = true;
    }
  }

  if (negative)
  {
    cout << "NEGATIVE CYCLE" << endl;
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (j)
        {
          cout << " ";
        }
        if (D[i][j] == INFTY)
        {
          cout << "INF";
        }
        else
        {
          cout << D[i][j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}
