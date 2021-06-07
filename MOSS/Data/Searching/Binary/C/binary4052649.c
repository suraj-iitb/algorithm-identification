#include <stdio.h>

int binarysearch(int[],int,int);

int main(){
    int i,n,m,k,res=0,num[100000];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&k);
        if(binarysearch(num,n,k)){
            res++;
        }
    }
    printf("%d\n",res);
    
    return 0;
}
int binarysearch(int A[],int n,int key){
    int left = 0,right = n,mid;
    
    while(left < right){
    mid = (left+right)/2;
    if(key == A[mid]){
        return 1;
    }
    if(key > A[mid]){
        left = mid+1;
    }
    else if(key < A[mid]){
        right = mid;
    }
    }
    return 0;
}
