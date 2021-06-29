#include<stdio.h>

#define N 10000

int main(){
  int n1,n2,num1[N],num2[N],i,j,count=0;

  scanf("%d",&n1);

  for(i=0;i<n1;i++){
    scanf("%d",&num1[i]);
  }

  scanf("%d",&n2);

  for(i=0;i<n2;i++){
    scanf("%d",&num2[i]);
  }

  for(i=0;i<n2;i++){
    for(j=0;j<n1;j++){
      if(num2[i]==num1[j]){
	count++;
break;
      }
    }
  }

  printf("%d\n",count);
  
  return 0;
}
