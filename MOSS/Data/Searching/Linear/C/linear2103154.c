#include <stdio.h>

int main(){
    int n,q;
    scanf("%d",&n);
    long long int s[n+2];
    int w;
    for(w=0;w<=n-1;w++)scanf("%lld",&s[w]);
    scanf("%d",&q);
    
    int i,j;
    int ans=0;
    for(i=0;i<=q-1;i++){
        long long int sta;
        scanf("%lld",&sta);
        s[n]=sta;
        j=0;
        while(sta!=s[j]) j++;
        if(j!=n) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
