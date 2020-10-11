#include <stdio.h>

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
typedef struct Card {
    int i;
    int n;
    char c;
} Card;

// retard desu LMAO
void *partition(Card *first, Card *last) {
    Card pivot = *(last - 1);
    Card *p = first - 1;
    for(Card *it = first; it != last - 1; ++it) {
        if(it->n <= pivot.n) {
            p++;
            Card tmp = *p;
            *p = *it;
            *it = tmp;
        }
    }
    Card tmp = *++p;
    *p = pivot;
    *(last - 1) = tmp;
    return p;
}
void quicksort(void *first, void *last, size_t N) {
    if(last - first <= N) return;
    void *mid = partition(first, last);
    quicksort(first, mid, N);
    quicksort(mid, last, N);
}

int main(int argc, char **argv) {
    int n = get_uint();
    Card a[n];
    for(int i = 0; i < n; ++i) {
        a[i].c = getchar_unlocked();
        getchar_unlocked();
        a[i].n = get_uint();
        a[i].i = i;
    }
    quicksort(a, a + n, sizeof(Card));

    int flag = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i].n==a[i-1].n && a[i].i < a[i-1].i){
            flag = 1;
            break;
        }
    }
    puts(flag ? "Not stable" : "Stable");
    for(int i = 0; i < n; ++i) {
        putchar_unlocked(a[i].c), putchar_unlocked(' ');
        put_uint(a[i].n), putchar_unlocked('\n');
    }
    return 0;
}

