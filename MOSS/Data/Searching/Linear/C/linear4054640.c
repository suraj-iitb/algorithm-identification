#include <stdio.h>

#define N 10000
#define Q 500

int main(void){
    int i,j,n,q,S[N],T[Q],cnt=0;
    
    scanf("%d",&n);
    if(n>10000) exit(1);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]); 
    }
    
    scanf("%d",&q);
    if(q>500) exit(1);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }
    
    for(i=0;i<q;i++){
        for(j=0;j<n;j++){
	  if(T[i]==S[j]){
	    cnt++;
	    break;
	  }
        }
    }
    
    printf("%d\n",cnt);
    
    return 0;
}

