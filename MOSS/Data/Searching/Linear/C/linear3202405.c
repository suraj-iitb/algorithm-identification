#include <stdio.h>

int main() {
    int key,A=0,j,i;
    int count = 0;
    int N,q;
    int S[10010],T[510];

    scanf("%d",&N);
    for (i = 0;i < N; ++i){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for (i = 0;i < q; ++i){
        scanf("%d",&T[i]);
    }

    for(j=0;j<q;j++) {

        key = T[j];
        S[N] = key;
        A = 0;

        while (1) {
            if (S[A] == key) {
                break;
            }
            A++;
        }
        if (A < N) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
