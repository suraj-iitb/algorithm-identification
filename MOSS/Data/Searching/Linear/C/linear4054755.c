#include <stdio.h>
int main (){
    int n,s[10001],i,q,t[500],j,cnt=0;
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
        s[n]=t[i];
        while(s[j]!=t[i]){
            j++;
        }
        if(j!=n){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

