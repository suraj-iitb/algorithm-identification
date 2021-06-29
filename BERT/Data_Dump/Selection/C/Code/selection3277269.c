#include <stdio.h>
int selectionsort(int *,int);
void swap(int *,int *);
int main(){

  int A[101],i,j,n,count;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  count=selectionsort(A,n);
  
  for(j=0;j<n;j++){
    if(j==n-1)printf("%d\n",A[j]);
    else printf("%d ",A[j]);
  }
  printf("%d\n",count);

  return 0;
}
int selectionsort(int a[],int n){
  int i,j,min,flag,count=0;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min]){
	min=j;
      }
    }
    if(i!=min){
    swap(&a[i],&a[min]);
    count++;
    }
  }
  return count;
}

void swap(int *p,int *q)
{
  int tmp;

  tmp=*p;
  *p=*q;
  *q=tmp;
  
}

