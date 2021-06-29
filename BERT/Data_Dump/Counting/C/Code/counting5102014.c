#include<stdio.h>

int main(){
 int A[2000000],n,i,j,C,k=0;
 
  scanf("%d\n",&n);
  
  for(i=0;i<10001;i++){
   A[i]=0;
  }
  
  for(i=0;i<n;i++){
   scanf("%d",&C);
   A[C]++;
 }
 
  for(i=0;i<10001;i++){
   for(j=0;j<A[i];j++){
    if(k==0){
     printf("%d",i);
      k++;
    }
    else{
     printf(" %d",i);
    }
   }
 }
  
 printf("\n");
 return 0;
}


