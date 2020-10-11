#include<stdio.h>
int count=0;
void selection(int a[], int n)//選択ソート
{
  int i,j;
  for(i=0; i<n-1; i++){
    int min=i;
    for(j=i+1; j<n; j++)
      if(a[j]<a[min])
	min=j;
      
    int tmp=a[i];
    a[i]=a[min];
    a[min]=tmp;

    if(a[i]!=a[min]) count++;
  }   
}

int main()
{
  int i,n;
  scanf("%d",&n);
  int a[n];
  for(i=0; i<n; i++)
    scanf("%d",&a[i]);
  
  selection(a,n);
  for(i=0; i<n; i++){
    if(i==n-1)
      printf("%d",a[i]);
    else
      printf("%d ",a[i]);
  }
  putchar('\n');
  printf("%d\n",count);
  return 0;
}


