#include <stdio.h>

#define N 100000
#define Q 50000

int n,S[N];

int binarySearch(int);

int main(){
    int k=0,q,i,T[Q];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }
    for(i=0;i<q;i++){
        if(binarySearch(T[i])!=-1){
            k++;
        }
    }
    printf("%d\n",k);
    return 0;
}

int binarySearch(int x){
    int l=0,r=n,m;
    while(l<r){
        m=(l+r)/2;
        if(S[m]==x) return m;
        else if(x<S[m])r=m;
        else l=m+1;
    }
    return -1;
}
