#include<stdio.h>

int main(){
  int length,i,j,k,key;
  int A[100];
  scanf("%d",&length);
  for(i=0;i<=length-1;i++) scanf("%d",&A[i]); 
  for(i=0;i<length-1;i++)
  printf("%d ",A[i]);
  printf("%d\n",A[length-1]);
  for(i=1;i<=length-1;i++)
    {
      key=A[i];
      j=i-1;  
      while(j>=0 && A[j]>key)
        {
          A[j+1]=A[j];
          j--;
          A[j+1]=key;
	}
      for(k=0;k<length-1;k++)
         printf("%d ",A[k]);
         printf("%d\n",A[length-1]);
    }
  return 0;
}

