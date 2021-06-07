#include <stdio.h>
int i;
int count=0;


void Linear(int *A,int key){
  
  int k=0;
  A[i]=key;
  while(A[k] != key){
    k++;

  }

  if( k == i) return;

  count++;
  return ;


}

main(){


  int A[100000],t,j,q,n;


  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
 for(j=0;j<q;j++){

   scanf("%d",&t);
   Linear(A,t);
 }


 printf("%d\n",count);
 return 0; 
}
