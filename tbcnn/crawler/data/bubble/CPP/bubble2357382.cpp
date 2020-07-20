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

int bubble(vector<int>& v)
{
    int n_swap = 0;

    for(int jmax = v.size()-1; jmax >= 1; --jmax) {
        for(int j = 1; j <= jmax; ++j) {
            if(v[j-1] > v[j]){
                swap(v[j-1], v[j]);
                ++n_swap;
            }
        }
    }

    return n_swap;
}

int main()
{
    vector<int> v = read_array();

    int n_swap = bubble(v);

    REP(i, v.size()) {
        printf("%d%c", v[i], i == v.size()-1 ? '\n' : ' ');
    }
    printf("%d\n", n_swap);

    return 0;
}
