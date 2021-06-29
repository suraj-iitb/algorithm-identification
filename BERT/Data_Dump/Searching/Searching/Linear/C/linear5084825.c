#include<stdio.h>
int main(){
    int s[10000],t[500],i,j,n,q,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&s[i]);
    scanf("%d",&q);
    for(j=0;j<q;j++) scanf("%d",&t[j]);
    
    for(j=0;j<q;j++){
        for(i=0;i<n;i++){
            if(s[i]==t[j]){
            cnt++;
            break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

