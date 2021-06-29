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

void print_array(u32 *A, u32 N);
u64 bubbleSort(u32 *A, u32 N);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    u32 n;
    u32 *A;

    cin >> n;

    A = new u32[n];

    rep (i, n)
    {
        cin >> A[i];
    }

    u64 ret = bubbleSort(A, n);

    print_array(A, n);
    cout << ret << "\n";

    delete[] A;

    return 0;
}

void print_array(u32 *A, u32 N)
{
    string str;
    rep (i, N)
    {
        str += to_string(A[i]) + ' ';
    }
    str.erase(str.end() - 1);
    str += '\n';
    cout << str;
}

u64 bubbleSort(u32 *A, u32 N)
{
    bool flag = true;
    u64 count = 0;
    while (flag)
    {
        flag = false;
        for (int i = N - 1; i > 0; --i)
        {
            if (A[i] < A[i - 1])
            {
                u32 temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                ++count;
                flag = true;
            }
        }
    }

    return count;
}

