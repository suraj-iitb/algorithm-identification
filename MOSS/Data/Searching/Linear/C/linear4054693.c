#include<stdio.h>
int main(){
    
    int i=0,count=0,m,n,j;
    scanf("%d",&m);
    int S[m];
    for(i=0;i<m;i++) scanf("%d",&S[i]);
    scanf("%d",&n);
    int T[n];
    for(i=0;i<n;i++) scanf("%d",&T[i]);
    
    for(j=0;j<n;j++){
        i=0;
    while (S[i] != T[j]){
        i++;
        if(i == m) break;
    }
    if (S[i] == T[j]) count++;
    }
    printf("%d\n",count);
    return 0;
}

