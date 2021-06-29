#include<stdio.h>
int main ()
{  int i,n,t,j,k=0,minnumber,a[10000];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   for(i=0;i<n;i++)
   {  minnumber=i;
      for(j=i;j<n;j++)
      if(a[j]<a[minnumber])  minnumber=j;//找出未排序的最小值序号 
      if(minnumber!=i)
	  {  t=a[i];
         a[i]=a[minnumber];
         a[minnumber]=t;
         k++;
      }
   }
   for(i=0;i<n;i++)
   {  if(i>0)  printf(" ");
      printf("%d",a[i]);
   }
   printf("\n");
   printf("%d\n",k);
   return 0; 
}
