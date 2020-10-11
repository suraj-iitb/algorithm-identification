#include<stdio.h>
int main(void)
{
  int A[100],N,i,j,minj,temp,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){scanf("%d",&A[i]);}
  
  for(i=0;i<N;i++)
    {
      minj=i;
      for(j=i;j<N;j++){
	if(A[minj]>A[j]){minj=j;}
	}
      if(i!=minj){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      count++;
      }
    }
  for(i=0;i<N;i++){printf("%d",A[i]);
      if(i!=(N-1)){printf(" ");}
      }
  printf("\n%d\n",count);
  return 0;
}
