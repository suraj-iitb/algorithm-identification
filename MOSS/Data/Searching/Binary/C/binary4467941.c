#include<stdio.h>
int a[1000001],n;
int bs(int k){
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r)/2;
        if(k==a[mid]) return 1;
        if(k>a[mid]) l=mid+1;
        if(k<a[mid]) r=mid;
    }
    return 0;
}
int main(){
    int i,q,x,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;++i) scanf("%d",&a[i]);
    scanf("%d",&q);
    for(i=0;i<q;++i){
        scanf("%d",&x);
        if(bs(x)) sum++;
    }
    printf("%d\n",sum);
    return 0;
}
