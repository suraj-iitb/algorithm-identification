#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1)/ (y))
#define MOD 1000000007ULL

u32 n;
u32 *A;

inline void print_array()
{
    string str;
    rep (i, n)
    {
        str += to_string(A[i]) + ' ';
    }
    str.erase(str.end() - 1);
    str += '\n';
    cout << str;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    A = new u32[n];

    rep (i, n)
    {
        cin >> A[i];
    }

    u32 v;

    print_array();
    for (int i = 1; i < n; ++i)
    {
        v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
        print_array();
    }

    return 0;
}

