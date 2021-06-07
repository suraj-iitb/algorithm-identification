#include <stdio.h>
#define n 10000

int main(){
  int A[n],a,j,num,num2,count=0,i;

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
  
  scanf("%d",&num2);
  for(i=0;i<num2;i++){
    scanf("%d",&a);
    for(j=0;j<num;j++){
      if(a==A[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

