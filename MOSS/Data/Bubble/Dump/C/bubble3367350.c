#include<stdio.h>
int main()
{  int i,n,t,j,flag,a[200000];
   scanf("%d",&n); 
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   flag=1;
   j=0;
   while(flag)
   {  flag=0;
      for(i=n-1;i>0;i--)
      {  if(a[i]<a[i-1]) //不符合条件的两两交换 
         {  t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
            j++;
            flag=1;
         }
      }
   }
   for(i=0;i<n;i++)
   {  if(i>0)  printf(" ");
      printf("%d",a[i]);
   }
   printf("\n");
   printf("%d\n",j);
   return 0; 
}
