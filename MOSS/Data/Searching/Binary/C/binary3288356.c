#include<stdio.h>
int binarySearch(int,int S[],int);
int main(){
    int n,S[100000];
    int q,T[50000];
    int i,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
       scanf("%d",&S[i]); 
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
        count+=binarySearch(n,S,T[i]);
    }
    printf("%d\n",count);
    return 0;
}

int binarySearch(int n,int S[],int key){
    int left,right,mid;
    left=0;
    right=n;
    while(left<right){
        mid=(left+right)/2;
        if(key==S[mid]){
        return 1;
        }
        if(key>S[mid]){
        left=mid+1;
        }
        else if(key<S[mid]){
        right=mid;
        }
    }
    return 0;
}
