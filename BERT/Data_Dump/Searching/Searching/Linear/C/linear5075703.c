#include<stdio.h>

int Search(int * ,int,int);

int main(){
    int i,n,S[10000+1],q,t,sum = 0;

    scanf("%d",&n);
    for(i = 0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i = 0;i<q;i++){
        scanf("%d",&t);
        if(Search(S,n,t)){
            sum++;
        }
    }
    printf("%d\n",sum);

    return 0;
}

int Search(int S[], int n, int t){
    int i = 0;
    S[n] = t;
    while( S[i] !=t)i++;
    return i != n;
}
