#include <stdio.h>
//#define rep(i,n) for(int i=0;i<n;i++)

int A[100001],n;

int Binary(int key){
    int left=0;
    int right=n;
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(A[mid]==key) return 1;
        if(A[mid]<key) left=mid+1;
        else if(A[mid]>key) right=mid;
    }
    return 0;
}

int main(void){
    int i=0,key,q,sum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&A[i]);

    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if( Binary(key)) sum++;
    }
    printf("%d\n",sum);
}
