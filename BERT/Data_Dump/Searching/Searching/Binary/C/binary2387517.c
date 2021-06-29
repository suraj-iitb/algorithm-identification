#include<stdio.h>
int search(int A[],int n,int key){
    int l=0,r=n;
    int mid;
    while(l<r){
	mid=(l+r)/2;
	if(key<A[mid]) r=mid; 
	else if(key>A[mid]) l=mid+1;
	else return 1;
    }
    return 0;
}

int main(void){
    int n,A[100000],q,key,sum=0;
    int i;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++){
	scanf("%d",&key);
	if(search(A,n,key)) sum++;
    }
    printf("%d\n",sum);

    return 0;
}
