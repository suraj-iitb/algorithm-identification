#include<stdio.h>

int bSearch(int n, int S[], int T){
    int left=0, mid, right=n;

    while(left!=right){
        mid=(left+right)/2;
        if(S[mid]==T)return 1;
        else if(T<S[mid])right=mid;
        else left=mid+1;
    }
    return 0;
}

int main(){
    int i, n, q, T, sum;
    int S[100000];

    scanf("%d", &n);
    for(i=0; i<n; i++)scanf("%d", &S[i]);
    scanf("%d", &q);

    for(i=0; i<q; i++){
        scanf("%d", &T);
        if(bSearch(n, S, T))sum++;
    }

    printf("%d\n", sum);

    return 0;
}
