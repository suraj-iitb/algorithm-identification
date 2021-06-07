#include <stdio.h>
#define N 10000
#define Q 500

int main() {

    int i, j, n, q, cnt=0;
    int x[N], y[Q];

    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d", &x[i]);
    }
    scanf("%d",&q);
    for(i=0; i<q; i++) {
        scanf("%d",&y[i]);

	for(j=0; j<n; j++) {
            if(y[i] == x[j]) {
                cnt++;
                break;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}

