#include <stdio.h>

int n,A[1000000];

int search(int k){
    int left=0,right=n,mid;
    while(left<right){
        mid=(left+right)/2;
        if(A[mid]==k){
            return 1;
        }
        else if(k<A[mid]){
            right=mid;
        }
        else{
            left=mid+1;
        }
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
    for(int i=0;i<q;i++){
        scanf("%d",&k);
        if(search(k)){
            sum+=1;
        }
    }
    printf("%d\n",sum);
    return 0;
}
