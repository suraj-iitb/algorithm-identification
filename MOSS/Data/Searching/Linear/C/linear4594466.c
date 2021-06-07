#include<stdio.h>
int issearch(int [],int,int);
int issearch(int x[],int y,int m){
    int t=0;
    while(x[t]!=y){
        t++;
    }
    return t!=m;
}
int main(void){
    int i,j,n,S[10000],q,T[500],sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%d",&T[j]);
        S[i]=T[j];
        sum+=issearch(S,T[j],i);
    }
    printf("%d\n",sum);
    return 0;
}
