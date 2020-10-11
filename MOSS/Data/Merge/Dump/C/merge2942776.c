#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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

int get_uint() {
    int n = 0;
    int c = getchar_unlocked();
    if(c < 48 || 57 < c) return c;
    while(47 < c && c < 58) {
        n = 10 * n + (c & 0xf);
        c = getchar_unlocked();
    }
    return n;
}
int cnt;
void merge(int *first, int *mid, int *last) {
    const int N1 = (int)(mid - first);
    const int N2 = (int)(last - mid);
    int *left = malloc(sizeof(int) * (N1 + 1));
    int *right = malloc(sizeof(int) * (N2 + 1));
    memcpy(left, first, sizeof(int) * (N1 + 1));
    memcpy(right, mid, sizeof(int) * (N2 + 1));
    left[N1] = right[N2] = 1000000000;
    for(int *it = first, i = 0, j = 0; it != last; ++it) {
        *it = left[i] <= right[j] ? left[i++] : right[j++];
    }
    free(left);
    free(right);
}
void merge_sort(int *first, int *last) {
    const int N = (int)(last - first);
    if(N < 2) return;
    int *mid = first + N / 2;
    merge_sort(first, mid);
    merge_sort(mid, last);
    merge(first, mid, last);
    cnt += N;
}
int main(int argc, char **argv) {
    int n = get_uint();
    int s[500001];
    for(int i = 0; i < n; ++i) s[i] = get_uint();
    merge_sort(s, s + n);
    for(int i = 0; i < n - 1; ++i) put_uint(s[i]), putchar_unlocked(' ');
    put_uint(s[n - 1]), putchar_unlocked('\n');
    put_uint(cnt), putchar_unlocked('\n');
    return 0;
}

