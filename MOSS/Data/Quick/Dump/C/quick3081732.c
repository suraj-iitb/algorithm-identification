#include <stdio.h>
 
int get_uint() {
    int s = 0;
    int a = getchar_unlocked();
    if(a < 48 || 57 < a) return a;
    while(47 < a && a < 58) {
        s = 10 * s + (a & 0xf);
        a = getchar_unlocked();
    }
    return s;
}
void put_uint(int s) {
    if(!s) {
        putchar_unlocked('0');
        return;
    }
    char buf[11];
    int i = 0;
    while(s) buf[i++] = (char)(s % 10 + '0'), s /= 10;
    while(i--)putchar_unlocked(buf[i]);
}
typedef struct Card {
    int i;
    int s;
    char a;
} Card;
 
// retard desu LMAO
void *partition(Card *fir, Card *last) {
    Card pivot = *(last - 1);
    Card *p = fir - 1;
    for(Card *is = fir; is != last - 1; ++is) {
        if(is->s <= pivot.s) {
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
    int s = get_uint();
    Card A[s];
    for(int i = 0; i < s; ++i) {
        A[i].a = getchar_unlocked();
        getchar_unlocked();
        A[i].s = get_uint();
        A[i].i = i;
    }
    quicksort(A, A + s, sizeof(Card));
 
    int flag = 0;
    for(int i = 1; i < s; ++i) {
        if(A[i].s==A[i-1].s && A[i].i < A[i-1].i){
            flag = 1;
            break;
        }
    }
    puts(flag ? "Not stable" : "Stable");
    for(int i = 0; i < s; ++i) {
        putchar_unlocked(A[i].a), putchar_unlocked(' ');
        put_uint(A[i].s), putchar_unlocked('\n');
    }
    return 0;
}

