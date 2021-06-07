#include <stdio.h>
#define N 100000
#define Q 50000

int main(){
    int n,q,count=0,i,j,l,r,mid,key;
    int S[N],T[Q];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }
    for(i=0;i<q;i++){
        l = 0;
        r = n;
        key = T[i];
        while(l<r){
            mid  = (int)((l+r)/2);
            if(S[mid] == key){
                count++;
                break;
            }
            else if(key < S[mid]){
                r = mid;
            }
            else
            l = mid + 1;
        }
    }
    printf("%d\n",count);
    return 0;
}
