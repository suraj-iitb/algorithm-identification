#include <stdio.h>
int main(void){
    int n, q;
    int S[10000];
    int T[500];
    int count = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        scanf("%d", &T[i]);

        for (int k = 0; k < n; k++){
            if (S[k] == T[i]){
                count += 1;
                break;
            }
        }
    }

    printf("%d\n", count);
    return 0;

    
}
