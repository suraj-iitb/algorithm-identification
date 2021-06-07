#include <stdio.h>

// positive only
int get_int() {
    int n = 0;
    int c = getchar_unlocked();
    if(c < 48 || 57 < c) return -1;
    while(47 < c && c < 58) {
        n = 10 * n + (c & 0xf);
        c = getchar_unlocked();
    }
    return n;
}
int linear_search(int key, int *arr, int N) {
    arr[N] = key;
    int i = 0;
    while(arr[i++] != key) {};
    return i > N ? 0 : 1;
}
int main(int argc, char **argv) {
    int n = get_int();
    int s[10001];
    for(int i = 0; i < n; ++i) {
        s[i] = get_int();
    }
    int q = get_int();
    int cnt = 0;
    int t;
    while(q--) {
        t = get_int();
        linear_search(t, s, n) && cnt++;
    }
    printf("%d\n", cnt);
}

