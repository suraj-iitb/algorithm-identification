#include<stdio.h>
#define N 10000

int linerSearch(int [],int,int);
int main(){
    int A[N],i,n,q,key,x,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        x= linerSearch(A,n,key);
        if(x!=n+1) count++;
    }
    printf("%d\n",count);
    
    return 0;
}
 
    
  int  linerSearch(int A[],int n, int key){
        int i=0;
        A[n]=key;
        while(A[i]!=key){
            i++;
        }
        if(i==n) return n+1;
        else return i;
    }
