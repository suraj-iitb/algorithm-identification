#include<stdio.h>
#include<stdlib.h>
int count = 0;

void binarySearch(int *S,int left,int right,int target){
    if(left>right){
        //printf("%d is not found\n",target);
        return;
    }
    int mid = (left+right)/2;
    //printf("mid???%d\n",mid);
    if(S[mid]==target){
        //printf("%d is found! It is at %d\n",target,mid);
        count++;
        return;
    }else{
        if(target>S[mid]){
            //printf("target%d>S[mid]%d????????????????????????\n",target,S[mid]);
            binarySearch(S,mid+1,right,target);
        }else{
            //printf("target%d<S[mid]%d????????????????????????\n",target,S[mid]);
            binarySearch(S,left,mid-1,target);
        }
    }
}

int main(){
    int n,q,i;
    int *S,*T;
    scanf("%d",&n);
    S = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&S[i]);
    scanf("%d",&q);
    T = (int *)malloc(sizeof(int)*q);
    for(i=0;i<q;i++)scanf("%d",&T[i]);
    /*
    for(i=0;i<n;i++){
        if(i==0){
            printf("%d",S[i]);
        }else{
            printf(" %d",S[i]);
        }
    }
    */
    
    
    
    for(i=0;i<q;i++){
        binarySearch(S,0,n-1,T[i]);
    }
    
    printf("%d\n",count);
    
    return 0;
}
