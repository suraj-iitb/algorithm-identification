#include<stdio.h>
int count=0;
void bubblesort(int a[], int n)
{
  int i,flag=0;
  
  while(flag<n-1){
    int last=n-1;//これ分からん
    for(i=n-1; i>flag; i--){//右端から大きいのと交換して一回目で左端を最小にする
      if(a[i-1]>a[i]){
	count++;
	int tmp=a[i-1];
	a[i-1]=a[i];
	a[i]=tmp;
	last=i;
      }
    }
    /* for(i=0; i<n; i++)
      printf("%d ",a[i]);
      putchar('\n');*/
    flag=last;//結局1,2,3,,,,とやってるだけ
  }
}
int main()
{
  int i,n;
  scanf("%d",&n);
  int a[n];
  for(i=0; i<n; i++)
    scanf("%d",&a[i]);

  bubblesort(a,n);
  for(i=0; i<n; i++)
    if(i==n-1)
      printf("%d",a[i]);
    else
      printf("%d ",a[i]);
  putchar('\n');
  printf("%d\n",count);
  return 0;
}
