#include<stdio.h>
int main()
{  int i,n,t,j,k,a[200000];
   scanf("%d",&n); 
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   for(i=1;i<=n;i++)
   {  t=a[i];//抽出一个进行插入 
      j=i-1;
      for(k=0;k<n;k++)
      {  if(k>0)  printf(" ");
          printf("%d",a[k]);
      }
      while(j>=0&&a[j]>t)//与之前排过序的比较 
      {  a[j+1]=a[j];// 大的往后走 
         a[j]=t;//小的往前走 
         j--;
      }
      printf("\n");
   }
   return 0;
}
