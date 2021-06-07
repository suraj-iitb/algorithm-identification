#include <stdio.h>
#define N 1000000000
int S[N],n,key;
int binarySearch(){
    int left = 0,right = n,mid;
    while(left < right){
        mid = (left + right) / 2;
        if(S[mid] == key) return 1;
        if(key > S[mid]) left = mid + 1;
        else if(key < S[mid]) right = mid;
    }
    return 0;
}
int main(void){
    int i;
    int q,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&S[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if(binarySearch() == 1) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

