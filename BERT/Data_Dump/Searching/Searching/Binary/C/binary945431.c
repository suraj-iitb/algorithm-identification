#include <stdio.h>
int i;
int count=0;


void Binary(int *A,int key){
  int left=0,right;
  int mid;

  right=i;
  while(left < right){
    mid=(left+right)/2;
    
    if(key == A[mid]){
      count++;
      return ;
    }
    if(key > A[mid]) left = mid + 1;
       else if(key < A[mid]) right=mid;
       
       
  }
   
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
   Binary(A,t);
 }


 printf("%d\n",count);
 return 0; 
}
