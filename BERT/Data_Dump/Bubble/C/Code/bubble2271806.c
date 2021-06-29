#include <stdio.h>

void bubbleSort(int *,int);

int main(){
  int N,A[100],i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  bubbleSort(A,N);
  
  return 0;
}
  void bubbleSort(int *a,int n)
  {
    int flag=1,i,j,num,count=0;
    while(flag!=0){
      flag=0;
      for(j=n-1;j>=1;j--){
	if(a[j]<a[j-1]){
	  num=a[j];
	  a[j]=a[j-1];
	  a[j-1]=num;
	  count++;
	  flag=1;
	}	 
      }
    }
    for(i=0;i<n;i++){
      printf("%d",a[i]);
      if(i!=n-1)printf(" ");
      }
    printf("\n");
    printf("%d\n",count);
  }
