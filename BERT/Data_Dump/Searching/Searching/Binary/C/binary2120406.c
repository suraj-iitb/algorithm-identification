#include<stdio.h>

int main(){
    int n,q;
    int S[100000],T[50000];
    scanf("%d",&n);
    int i;
    for(i=0;i<=n-1;i++)scanf("%d",&S[i]);
    scanf("%d",&q);
    for(i=0;i<=q-1;i++)scanf("%d",&T[i]);
    int ans=0;
    for(i=0;i<=q-1;i++){
        int sta=0,end=n;
        int t=T[i];
        while(sta<end){
            int mid=(sta+end)/2;
            if(t==S[mid]){
                ans++;
                sta=end;
            }else if(t<S[mid]){
                end=mid;
            }else{
                sta=mid+1;
            }
        }
    }
    printf("%d\n",ans);
    
    return 0;
}
