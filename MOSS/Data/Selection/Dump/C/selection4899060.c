#include <stdio.h>

int main()
{
 int a[100],i,min,cout=0,N;
 scanf("%d",&N);
 for(i=0;i<N;i++)
  scanf("%d",&a[i]);
 for(i=0;i<N;i++)
 {
  int temp,j;
  min=i;
  for(j=i;j<N;j++)
   if(a[j]<a[min])
    min=j;
  if(i!=min)
  {
   temp=a[i];
   a[i]=a[min];
   a[min]=temp;
   cout++;
  }
 }
 for(i=0;i<N;i++)
 {
  printf("%d",a[i]);
  printf("%c",i==N-1?'\n':' ');
 }
 printf("%d\n",cout);
 
}
