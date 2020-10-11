#include<stdio.h>

int main(){
  int A[100],i,j,k,temp,num,cnt=0;
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&A[i]);
  }
  for (i = 0;i < k ;i++) {
    temp=i;
    for (j = i+1;j < k ;j++) {
      if (A[j] < A[temp]) 
	temp = j;
	  }
      num=A[i];
	A[i] = A[temp];
	A[temp] = num;
	if(i!=temp)
	cnt++;
      }
    
    
    for(i=0;i<k;i++){
      if(i)printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
  printf("%d\n",cnt);
  return 0;
  }
  

