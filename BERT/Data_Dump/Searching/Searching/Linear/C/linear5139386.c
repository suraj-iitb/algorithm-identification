#include<stdio.h>

int main(){
    int n,q,s[10000],t[500],sum=0,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&t[i]);
    }
    for(i=0;i<q;i++){
        j=0;
        while(s[j]!=t[i]){
            j++;
            if(j==n)break;
        }
        if(j!=n)sum++;
    }
    printf("%d\n",sum);
    return 0;
}
