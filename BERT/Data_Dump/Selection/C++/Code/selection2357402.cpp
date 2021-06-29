#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)



vector<int> read_array()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    REP(i, n) {
        scanf("%d", &v[i]);
    }

    return v;
}

int selection(vector<int>& v)
{
    int n_swap = 0;

    REP(i, v.size()) {
        int argmin = i;
        FOR(j, i+1, v.size()) {
            if(v[j] < v[argmin])
                argmin = j;
        }
        if(argmin != i) {
            swap(v[argmin], v[i]);
            ++n_swap;
        }
    }

    return n_swap;
}

int main()
{
    vector<int> v = read_array();

    int n_swap = selection(v);

    REP(i, v.size()) {
        printf("%d%c", v[i], i == v.size()-1 ? '\n' : ' ');
    }
    printf("%d\n", n_swap);

    return 0;

    return 0;
}
