#include<stdio.h>

int main(){
    int n,q, S[10000], T[500], i, j, res=0, flg=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    
    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%d",&T[j]);
    }
    
    for(j=0;j<q;j++){
        for(i=0;i<n;i++){
            if(T[j]==S[i])flg++;
        }
        if(flg!=0)res++;
        flg=0;
    }
    printf("%d\n",res);
    return 0;
}
