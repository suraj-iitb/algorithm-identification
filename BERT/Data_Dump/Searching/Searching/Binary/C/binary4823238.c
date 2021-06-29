#include<stdio.h>
int A[1000000],n;
int search(int A[],int key){
    int right,left,mid;
    right =n;
    left=0;
    while(right>left){
        mid=(right+left)/2;
        if(A[mid]==key) return 1;
        else if(A[mid]>key) right =mid;
        else left=mid+1;
    }
    return -1;
}
int main(void){
    int q,k,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&k);
        if(search(A,k)==1) sum++;
    }
    printf("%d\n",sum);
    return 0;
    
}

