#include<stdio.h>

int binarySearch(int A[],int n,int key){
    int left=0,right=n,mid;
    while(left<right){
        mid=(left+right)/2;
        if(A[mid]==key){
            return 1;
        }else if(key>A[mid]){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return 0;
}

int main(void){
    int n,q,i,sum=0,key,S[100001];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if(binarySearch(S,n,key)){
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}

