#include <stdio.h>

int A[100000], n;

int bSearch(int k){
    int l=0, r=n, m;
    
    while(l<r){
        m = (l+r)/2;
        if(k==A[m])return 1;
        if(k>A[m])l = m+1;
        else if(k<A[m]) r = m;
    }
    return 0;
}

int main(){
    int i,q,k,sum=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&k);
        if(bSearch(k))sum++;
    }
    printf("%d\n",sum);
    
    return 0;
}
