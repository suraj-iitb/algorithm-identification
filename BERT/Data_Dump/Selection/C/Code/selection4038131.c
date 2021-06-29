#include<stdio.h>
int selectionSort(int*,int);/*選択ソート*/
void swap(int* ,int*);/*入替*/

int main()
{
  int n,i,cnt;
  scanf("%d",&n);
  int b[n];
  for(i=0 ; i<n ; i++)
    scanf("%d",&b[i]);

  cnt=selectionSort(b,n);
   for(i=0;i<n;i++){
    if(i == n-1)
      printf("%d",b[i]);
    else
    printf("%d ",b[i]);}
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

void swap(int *x ,int *y)
{
  int z;
  z=*x;
  *x=*y;
  *y=z;
}

int selectionSort(int*b,int n)
{
  int i,j,mini,cnt=0;
  for(i=0 ; i < n-1; i++)
    {
      mini=i;
      for(j=i ; j < n ; j++)
	{
	  if(b[j] < b[mini])
	    { mini=j; }
	}
      swap(&b[i],&b[mini]);
      if(i!=mini)
      cnt++;
    }
  return cnt;
 
}

