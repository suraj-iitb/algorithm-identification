#include<stdio.h>

int binarySearch(int key,int A[],int n){
    int left=0;
    int right=n;
    int mid;
    while(left<right){
        mid=(left + right)/2;
        if(A[mid] == key){
            return mid;
        }
        else if(key < A[mid]){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return n;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int S[n];
    for(int i=0; i<n; i++){
        scanf("%d",&S[i]);
    }
    int q;
    scanf("%d",&q);
    int T[q];
    int count=0;
    for(int i=0; i<q; i++){
        scanf("%d",&T[i]);
        if(binarySearch(T[i],S,n)!=n)
        {
            count++;
        }
    }
    printf("%d\n",count);
}
