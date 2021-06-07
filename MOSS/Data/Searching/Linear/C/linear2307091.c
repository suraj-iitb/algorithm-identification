#include<stdio.h>
#define N 10000
#define Q 500

int Search();

int S[N];
int n, key;

int main(){
    int T[Q];
    int q, i;
    int count = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &T[i]);
    }

    for(i = 0; i < q; i++){
        key = T[i];
        if(Search() == 1) count++;
    }

    printf("%d\n",count);

    return 0;
}

int Search(){
    int i = 0;

    S[n] = key;

    while(S[i] != key) i++;

    if(i == n) return 0;

    return 1;
}
