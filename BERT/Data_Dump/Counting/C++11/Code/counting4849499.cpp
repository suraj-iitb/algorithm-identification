#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define endl '\n'
#define ls (i << 1)
#define rs (i << 1 | 1)
#define loop(i, a, b) for (int i = a; i < b; ++i)

inline int read() {
    char ch = getchar();
    int w = 1, c = 0;
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-') w = -1;
    for (; isdigit(ch); ch = getchar()) c = (c << 3) + (c << 1) + (ch ^ 48);
    return w * c;
}

int n, a[N];

int main() {
    n = read();
    loop(i, 0, n) {
        int x = read();
        a[x]++;
    }
    bool f = true;
    loop(i, 0, 10000) {
        while (a[i]--) {
            if (f)
                printf("%d", i), f = false;
            else
                printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}
