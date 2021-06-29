#include <iostream>
#include <algorithm>

const int maxv = 105;
const long long int inf = 107374182400;

long long int dp[maxv][maxv];

int main ()
{
  int V, E;
  std::cin >> V >> E;

  for (int i=0; i<maxv; ++i)
    for (int j=0; j<maxv; ++j)
      {
        if (i==j)
          dp[i][j] = 0;
        else
          dp[i][j] = inf;
      }

  int s, t, d;
  for (int i=0; i<E; ++i)
    {
      std::cin >> s >> t >> d;
      dp[s][t] = d;
    }

  for (int k=0; k<V; ++k)
    {
      for (int i=0; i<V; ++i)
        {
          for (int j=0; j<V; ++j)
            {
              if (dp[i][k] != inf && dp[k][j] != inf)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

  for (int i=0; i<V; ++i)
    {
      if (dp[i][i] < 0)
        {
          std::cout << "NEGATIVE CYCLE\n";
          return 0;
        }
    }

  for (int i=0; i<V; ++i)
    {
      for (int j=0; j<V; ++j)
        {
          if (dp[i][j] == inf)
            std::cout << "INF";
          else
            std::cout << dp[i][j];
          if (j<V-1) std::cout << ' ';
        }
      std::cout << std::endl;
    }

  return 0;
}

