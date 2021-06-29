#include <stdio.h>

int main(){
    int n,q,ans=0;
    long int s[10000],t[5000];
    scanf("%d",&n);
    for (int i = 0; i<n; i++){
        scanf("%ld",&s[i]);
    }
    scanf("%d",&q);
    for (int i = 1; i<q+1;i++){
        scanf("%ld",&t[i]);
        for (int j =0;j<n;j++){
            if(t[i]==s[j]){
                ans=ans+1;
                break;
            }
        }
    }
    printf("%d\n",ans);
}
