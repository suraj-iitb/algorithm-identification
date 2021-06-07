#include<stdio.h>
#define N 10000

int lsearch(int n, int S[], int T){
    int i=0;
    S[n]=T;
    while(S[i]!=T)i++;
    return i !=n;
}

int main(){
    int i, n, q, T, sum=0;
    int S[N];
    scanf("%d", &n);
    for(i=0; i<n; i++)scanf("%d", &S[i]);
    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d", &T);
        if(lsearch(n, S, T))sum++;
    }
    printf("%d\n", sum);

    return 0;
}
