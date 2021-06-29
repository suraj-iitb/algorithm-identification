#include<stdio.h>
int linear(int A[],int n,int key){
    int i=0;
    A[n]= key;
    while(A[i]!=key)i++;
    return i !=n ;
}
int main(){
    int a,b,num=0,i,j,key,l,n,q,S[10000+1];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if( linear(S,n,key) )num++;
    }
    printf("%d\n",num);
      return 0;
    }
