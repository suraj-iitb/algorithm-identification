#include <stdio.h>
#define N 100
int main()
{
  int A[N],n,i,j,min=0,minj,c,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  for(i=0;i<=n-1;i++)
    {
      minj=i;//ソート順１かい目０、２かい目１。。。
      for(j=i;j<=n-1;j++)
	{
	  if(A[j]<A[minj]){
	    minj=j;//最小値のある要素番号更新
	  }
	}
      //ソート終の次の要素と最小値交換
      if(minj!=i)
	{
	  c=A[i];
	  A[i]=A[minj];
	  A[minj]=c;
	  count++;
	}
    }
  for(i=0;i<n;i++)
    {
      printf("%d",A[i]);
      if(i!=n-1)
	printf(" ");
    }
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}

