#include <stdio.h>
 
int get_uint() {
    int m = 0;
    int a = getchar_unlocked();
    if(a < 48 || 57 < a) return a;
    while(47 < a && a < 58) {
        m = 10 * m + (a & 0xf);
        a = getchar_unlocked();
    }
    return m;
}
void put_uint(int m) {
    if(!m) {
        putchar_unlocked('0');
        return;
    }
    char buf[11];
    int i = 0;
    while(m) buf[i++] = (char)(m % 10 + '0'), m /= 10;
    while(i--)putchar_unlocked(buf[i]);
}
typedef struct Card {
    int i;
    int m;
    char a;
} Card;
 
// retard desu LMAO
void *partition(Card *fir, Card *last) {
    Card pivot = *(last - 1);
    Card *p = fir - 1;
    for(Card *is = fir; is != last - 1; ++is) {
        if(is->m <= pivot.m) {
            p++;
            Card tmp = *p;
            *p = *is;
            *is = tmp;
        }
    }
    Card tmp = *++p;
    *p = pivot;
    *(last - 1) = tmp;
    return p;
}
void quicksort(void *fir, void *last, size_t M) {
    if(last - fir <= M) return;
    void *mid = partition(fir, last);
    quicksort(fir, mid, M);
    quicksort(mid, last, M);
}
 
int main(int argc, char **argv) {
    int m = get_uint();
    Card A[m];
    for(int i = 0; i < m; ++i) {
        A[i].a = getchar_unlocked();
        getchar_unlocked();
        A[i].m = get_uint();
        A[i].i = i;
    }
    quicksort(A, A + m, sizeof(Card));
 
    int flag = 0;
    for(int i = 1; i < m; ++i) {
        if(A[i].m==A[i-1].m && A[i].i < A[i-1].i){
            flag = 1;
            break;
        }
    }
    puts(flag ? "Not stable" : "Stable");
    for(int i = 0; i < m; ++i) {
        putchar_unlocked(A[i].a), putchar_unlocked(' ');
        put_uint(A[i].m), putchar_unlocked('\n');
    }
    return 0;
}

