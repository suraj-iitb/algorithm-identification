#include <stdio.h>

//線形探査
int search(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key) i++;
  return i!= n;
}

int main(){
  int i,n,q,A[10001],key,sum=0;

  //数列Sの決定
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  //数列Tの決定
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search(A,n,key)) sum++;
  }

  printf("%d\n",sum);
    
  return 0;
}

