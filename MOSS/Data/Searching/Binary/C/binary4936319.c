#include<stdio.h>

int binarySearch(int A[],int n,int key){


    int left=0;
    int right=n;
    int mid;

    while(left<right){
        mid=(left+right)/2;
        
        if(A[mid]==key){
            return mid;
        }
        else if(key<A[mid]){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return n;
}
int main(void){

    int n,q,c,count=0;
    scanf("%d",&n);

    int S[n];
    for(int i=0; i<n; i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    int T[q];
    for(int i=0; i<q; i++){
        scanf("%d",&T[i]);
        c=binarySearch(S, n, T[i]);
    	if(c<n){
    		count++;
    	}
    }
    printf("%d\n",count);

    return 0;
}
