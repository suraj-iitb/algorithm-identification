#include<stdio.h>
int main(){
  int i,a,b,j,cn=0;
  int q;
  int A[10000];
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&q);
    for(j=0;j<a;j++){
      if(A[j]==q){
	cn++;
      break;
      }
    }
  }
  printf("%d\n",cn);
  return 0;
}
  
	
      
      
  
  
  
  

