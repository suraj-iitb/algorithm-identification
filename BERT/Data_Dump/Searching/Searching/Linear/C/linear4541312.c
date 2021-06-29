#include <stdio.h>
#include <stdlib.h>

void liner_search(int *S, int *T, int n, int q);

int main(void)
{
    int n,q;
    int *S,*T;
    int i;

    scanf("%d", &n);
    S = calloc(n, sizeof(int));
    
    for (i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    T = calloc(q, sizeof(int));

    for (i = 0; i < q; i++){
        scanf("%d", &T[i]);
    }

    liner_search(S, T, n, q);

    return (0);
}

void liner_search(int *S, int *T,int n, int q)
{
    int i,j;
    int count;

    count = 0;
    for (i = 0; i < q; i++){
        j = 0;
        while (j < n){
            if (S[j] == T[i]){
                count++;
                break;
            }
            j++;
        }
    }
    printf("%d\n", count);


}
