#include <stdio.h>

int get_uint() {
    int n = 0;
    int c = getchar_unlocked();
    if(c < 48 || 57 < c) return c;
    while(47 < c && c < 58) n = 10 * n + (c & 0xf), c = getchar_unlocked();
    return n;
}
void put_uint(int n) {
    if(!n) {
        putchar_unlocked('0');
        return;
    }
    char buf[11];
    int i = 0;
    while(n) buf[i++] = (char)(n % 10 + '0'), n /= 10;
    while(i--)putchar_unlocked(buf[i]);
}

void dfs(int G[100][100], int n, int *d, int *f, int u) {
    static int t = 0;
    d[u] = ++t;
    for(int i = 0; i < n; ++i) {
        if(!G[u][i] || d[i]) continue;
        dfs(G, n, d, f, i);
    }
    f[u] = ++t;
}
int main(int argc, char **argv) {
    int n = get_uint();
    int G[100][100] = {};
    for(int i = 0; i < n; ++i) {
        int u = get_uint() - 1;
        int k = get_uint();
        for(int j = 0; j < k; ++j) G[u][get_uint() - 1] = 1;
    }
    int d[100], f[100] = {};
    for(int i = 0; i < n; ++i)
        if(!f[i]) dfs(G, n, d, f, i);
    for(int i = 0; i < n; ++i) {
        put_uint(i + 1), putchar_unlocked(' ');
        put_uint(d[i]), putchar_unlocked(' ');
        put_uint(f[i]), putchar_unlocked('\n');
    }
    return 0;
}

