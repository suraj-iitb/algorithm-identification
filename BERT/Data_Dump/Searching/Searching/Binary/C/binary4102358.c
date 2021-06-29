#include<stdio.h>

int A[1000000], n;

int binarysearch(int key){
    int left = 0;
    int right = n;
    int middle;
    
    while(left<right){
        middle = (left+right)/2;
        if(key==A[middle]) return 1;
        if(key>A[middle]) left=middle+1;
        else if(key<A[middle]) right=middle;
    }
    return 0;
}

int main(){
    int i,m,k,sum=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&k);
        if(binarysearch(k)) sum++;
    }
    
    printf("%d\n",sum);
    
    return 0;
}
