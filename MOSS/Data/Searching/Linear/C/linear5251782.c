#include <stdio.h>

int main(void) {

    int n;
    scanf("%d", &n);
    int S[n];
    int i;
    for (i=0; i<n; i++){
        scanf("%d", &S[i]);
    }

    int  q;
    scanf("%d", &q);
    int T[q];
    int j;
    for (j=0; j<q; j++){
        scanf("%d", &T[j]);
    }

    int ctr=0;
    for (i=0; i<q; i++)
    {
        for(j=0; j<n; j++)
        {
            if (S[j] == T[i])
                {
                    ctr ++;
                    break;
                }
        }
    }
    printf("%d", ctr);
    printf("\n");
    return 0;
}

