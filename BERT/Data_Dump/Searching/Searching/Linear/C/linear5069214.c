#include <stdio.h>

int main(){
    int n, q, S[100001], T[500], i, j, C=0;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d", &T[i]);
    }
    for(i=0; i<q; i++){
        j=0;
        S[n]=T[i];
        while(S[j]!=T[i]){
            j++;
        }
        if(j!=n){
            C++;
        }
    }
    printf("%d\n", C);
    return 0;
}
