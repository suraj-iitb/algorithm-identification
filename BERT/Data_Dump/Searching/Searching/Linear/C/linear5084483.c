#include<stdio.h>

int search(int [],int ,int );

int main(){
    int n,q,i,key,cnt=0;
    int A[10000];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&key);
      if(search(A,n,key)){
        cnt++;
      }
    }
  
    printf("%d\n",cnt);
    return 0;
}

int search(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
  }
  return i!=n;
}
