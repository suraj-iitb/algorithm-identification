
#include <stdio.h>

int main()
{
 int a[100],N,i,j,temp,count=0;
 scanf("%d",&N);
 for(i=0;i<N;i++)
  scanf("%d",&a[i]);
 for(i=0;i<N;i++)
  for(j=N-1;j>i;j--)
   if(a[j]<a[j-1])
   {
    temp=a[j];
    a[j]=a[j-1];
    a[j-1]=temp;
    count++;
   }
 for(i=0;i<N-1;i++)
  printf("%d ",a[i]);  
 printf("%d\n%d\n",a[i],count);
 return 0;
}
