#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

vector<int> read_array()
{
    int n;
    scanf("%d\n", &n);

    vector<int> ary(n);
    REP(i, n) {
        scanf("%d", &ary[i]);
    }

    return ary;
}

void print_array(const vector<int>& ary)
{
    REP(i, ary.size()) {
        printf("%d%c", ary[i], i == ary.size()-1 ? '\n' : ' ');
    }
}

// 1 <= i <= n-1
void inssort_step(vector<int>& ary, int i)
{
    int value = ary[i];

    int j;
    for(j = i-1; j >= 0; --j) {
        if(ary[j] <= value) break;
        ary[j+1] = ary[j];
    }
    ary[j+1] = value;
}

int main()
{
    vector<int> ary = read_array();

    print_array(ary);
    FOR(i, 1, ary.size()) {
        inssort_step(ary, i);
        print_array(ary);
    }

    return 0;
}
