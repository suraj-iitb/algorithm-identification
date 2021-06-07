#include<stdio.h>

int binarySearch(int T,int S[],int n){
    int left,right,mid;
    
    left=0;
    right=n;
    while(left<right){
        mid=(left+right)/2;
        if(T==S[mid]){
            return 1;
        }else if(T<S[mid]){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    
    return 0;
}

int main(void){
    int n,q,S[100000],T[50000];
    int i,j,count=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }
    
    for(i=0;i<q;i++){
        if(binarySearch(T[i],S,n)==1){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
