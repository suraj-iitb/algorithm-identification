#include<stdio.h>
//線形探索
int search(int A[],int n,int key){
    int i=0;
    A[n]=key;
    while(A[i]!=key)i++;
    if(i==n) return -1;
    else return i;
}

int main(void){
    int i,n,A[100001],q,key,sum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if(search(A,n,key)!=-1) sum++;
    }
    printf("%d\n",sum);
    return 0;
}
