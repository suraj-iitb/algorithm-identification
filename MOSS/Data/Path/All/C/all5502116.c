#include <vector>
#include <sstream>
#include <iostream>

constexpr int V_MAX{100};
constexpr long long INF{10000000000};

std::string format(int v, const std::vector<std::vector<long long>> &d)
{
    std::stringstream ss;
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (j)
            {
                ss << " ";
            }
            if (d[i][j] == INF)
            {
                ss << "INF";
            }
            else
            {
                ss << d[i][j];
            }
        }
        ss << std::endl;
    }
    return ss.str();
}

std::string solve(int v, std::vector<std::vector<long long>> &d)
{
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (d[j][i] == INF)
            {
                continue;
            }
            for (int k = 0; k < v; ++k)
            {
                if (d[i][k] == INF)
                {
                    continue;
                }
                d[j][k] = std::min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    for (int i = 0; i < v; ++i)
    {
        if (d[i][i] < 0)
        {
            return "NEGATIVE CYCLE\n";
        }
    }

    return format(v, d);
}

int main()
{
    int v, e;
    std::cin >> v >> e;

    std::vector<std::vector<long long>> d(V_MAX, std::vector<long long>(V_MAX, INF));
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (i == j)
            {
                d[i][j] = 0;
            }
        }
    }

    long long s, t, u;
    for (int i = 0; i < e; ++i)
    {
        std::cin >> s >> t >> u;
        d[s][t] = u;
    }

    std::cout << solve(v, d);

    return 0;
}

