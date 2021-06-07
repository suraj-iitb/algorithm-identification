#include <stdio.h>
int main(void){
    int n,s[10000]={},q,t,i,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",s+i);
    }
    for(scanf("%d",&q);q--;){
        scanf("%d",&t);
        for(i=0;i<n;i++){
            if(s[i]==t){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
