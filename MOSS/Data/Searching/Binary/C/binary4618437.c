#include<stdio.h>
int binarysearch(void);
int S[1000000000],n,key;
int binarysearch(){
    int left,right,mid;
    left=0;right=n;
    while(left<right){
        mid=(left+right)/2;
        if(key==S[mid]){
            return 1;
        }
        else if(key>S[mid]){
            left=mid+1;
        }
        else if(key<S[mid]){
            right=mid;
        }
    }
    return 0;
}
int main(void){
    int q,i,j,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%d",&key);
        if(binarysearch()){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
