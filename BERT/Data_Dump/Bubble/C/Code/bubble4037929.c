#include<stdio.h>
#define N 100

int main(){
  int Array[N];
  int temp;
  int n;
  int i,j;
  int count=0;

  /* Input */
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&Array[i]);
  }

  for(j=0;j<n;j++){
    for(i=n-1;i>=1;i--){
      if(Array[i]<Array[i-1]){
	temp=Array[i-1];
	Array[i-1]=Array[i];
	Array[i]=temp;
	count++;
      }
    }
  }

  /* Output */
  for(i=0;i<n-1;i++){
    printf("%d ",Array[i]);
  }
  printf("%d\n",Array[n-1]);
  printf("%d\n",count);
  
  return 0;
}

