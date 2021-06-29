#include<stdio.h>

int main(){

  int i,j,k,num,A[1000],min,tmp,cnt=0;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
  

  for(j=0;j<num;j++){
 min=j;
    for(k=j;k<num;k++){
     

      if(A[min]>A[k]){
	min=k;
        
      }
    }

      if(A[j]!= A[min]){
	tmp=A[j];
	A[j]=A[min];
	A[min]=tmp;
	cnt++;
      }
    
  }
  for(i=0;i<num-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",cnt);
  return 0;
}
