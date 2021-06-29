#include <stdio.h>

int main(){
    int i, j, n, a;
    int S[10000], T[500], c=0;

    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &a);

    for(i=0;i<a;i++){
        scanf("%d", &T[i]);
    }

    for(j=0;j<a;j++){
        i=0;
        S[n]=T[j];

        while(S[i]!=T[j]){
        i++;
        }

        if(i!=n) c++;

    }

    printf("%d\n", c);

    return 0;
}

