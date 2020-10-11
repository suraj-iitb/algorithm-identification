#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *,int);
void swap(int*,int*);

int main(){
  int i,n,a,*tmp;

  scanf("%d",&n);

  tmp = (int*)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&tmp[i]);
  }

  bubbleSort(tmp,n);
  
  free(tmp);
  return 0;
  
}

void bubbleSort(int *x,int n){
  int i,j,count=0;
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(x[j] < x[j -1]){
	swap(&x[j],&x[j-1]);
	count++;
	  }
    }
    printf("%d ",x[i]);
  }
  printf("%d\n",x[n-1]);
  printf("%d\n",count);
}

void  swap(int *x, int *y)
{
    int  work;   

    work = *x;   
    *x = *y;     
    *y = work;  
}
