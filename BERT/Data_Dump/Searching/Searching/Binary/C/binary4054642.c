#include <stdio.h>

#define N 100000
#define Q 50000

int main(void){
    int i,j,n,q,S[N],T[Q],cnt=0,m,l,r;
    
    scanf("%d",&n);
    if(n>100000) exit(1);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]); 
    }
    
    scanf("%d",&q);
    if(q>50000) exit(1);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }
    
    for(i=0;i<q;i++){
        l=0;
        r=n;
        while(l<r){
            m=(l+r)/2;
            if(S[m]==T[i]){
                cnt++;
                break;
            }
            else if(S[m]>T[i]){
                r=m;
            }
            else l=m+1;
        }
    }
    
    printf("%d\n",cnt);
    
    return 0;
}

