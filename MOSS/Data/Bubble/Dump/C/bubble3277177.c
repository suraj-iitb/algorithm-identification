#include <stdio.h>
int bubblesort(int *,int);
void swap(int *,int *);
int main(){

  int A[101],i,j,n,count;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  count=bubblesort(A,n);
  
  for(j=0;j<n;j++){
    if(j==n-1)printf("%d\n",A[j]);
    else printf("%d ",A[j]);
  }
  printf("%d\n",count);

  return 0;
}
int bubblesort(int a[],int n){
  int i,j,flag,count=0;
  flag=1;
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	swap(&a[j],&a[j-1]);
	flag=1;
	count++;
	/*	for(i=0;i<n;i++)
	  printf("%d",a[i]);
	  printf("\n");*/
      }
      
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

