#include <stdio.h>
 
// 数値のハッシュ関数
#define HASHSIZ 250007
int hash[HASHSIZ+3], *hashend = hash+HASHSIZ;
 
int lookup(int n)
{
    int *p;
     
    n++; p = hash + n % HASHSIZ;
    while (*p) {
        if (*p == n) return 1;
        if (++p == hashend) p = hash;
    }
    return 0;
}
 
void insert(int n)
{
    int *p;
     
    n++; p = hash + n % HASHSIZ;
    while (*p) {
        if (*p == n) return;
        if (++p == hashend) p = hash;
    }
    *p = n;
}
 
// バッファを経ずstdinから数値を得る
//#define getchar_unlocked()  getchar()
int in()
{
    int n = 0, c = getchar_unlocked();
    do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
    return n;
}
 
int main()
{
    int n, q, C;
 
    n = in();
    while (n--) insert(in());
 
    C = 0;
    q = in();
    while (q--) if (lookup(in())) C++;
     
    printf("%d\n", C);
    return 0;
}
