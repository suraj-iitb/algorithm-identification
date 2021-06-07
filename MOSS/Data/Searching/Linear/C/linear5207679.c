#include <stdio.h>

#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    int n, q;
    int S[10001];

    scanf("%d", &n);
    REP(i, n) scanf("%d", &S[i]);

    int count = 0;
    scanf("%d", &q);
    REP(i, q) {
        int key;
        scanf("%d", &key);

        int i = 0;
        S[n] = key;
        while(S[i] != key) i++;
        if (i != n) count++;
    }

    printf("%d\n", count);

    return 0;
}
