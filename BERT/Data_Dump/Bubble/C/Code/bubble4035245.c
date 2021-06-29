#include<stdio.h>

void bubbleSort(int*,int);
void swap(int* ,int*);

int main()
{
  int n,i;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  bubbleSort(a,n);

  return 0;
}

void swap(int *x ,int *y)
{
  int z;
  z=*x;
  *x=*y;
  *y=z;
}




void bubbleSort(int*a,int n)/*バブルソート*/
{
  int i,j,x,cnt=0;
  
  for(i=0; i<n-1; i++){
    for(j=n-1; j>=i+1; j--){
      if(a[j]<a[j-1])/*入替*/
	{
	  swap(&a[j],&a[j-1]);
	  cnt++;
        }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%d",a[i]);
    else
    printf("%d ",a[i]);}
  printf("\n");
  printf("%d\n",cnt);
}

