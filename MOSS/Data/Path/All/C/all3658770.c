#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define VMAX 100
static const long long INFTY = (1LL<<32);

long long D[VMAX][VMAX];
int n;

void warshallFloyd() {
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            if (D[i][k]==INFTY) continue;
            for (int j=0; j<n; j++) {
                if (D[k][j]==INFTY) continue;
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
            }
        }
    }
}

int main() {
    int s, t, E;
    long long d;

    scanf("%d %d", &n, &E);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            D[i][j] = INFTY;
        }
        D[i][i] = 0;
    }

    for (int i=0; i<E; i++) {
        scanf("%d %d %lld", &s, &t, &d);
        D[s][t] = d;
    }

    warshallFloyd();

    for (int i=0; i<n; i++) {
        if (D[i][i]<0) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j==0) {
                if (D[i][j]>=INFTY) printf("INF");
                else printf("%lld", D[i][j]);
            } else {
                if (D[i][j]>=INFTY) printf(" INF");
                else printf(" %lld", D[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
