#include<stdio.h> 
#include<string.h>
int main()
{  char s;
   int i,t,b[90000],a[90000],n,j,p,q,k;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   scanf("%d",&j);
   for(i=0;i<j;i++)
   scanf("%d",&b[i]);
   p=n;q=j;t=0;
   for(k=i=1;i<p;i++)	
   {  for(j=0;j<k;j++)		          
      {  if(a[j]==a[i])  
	     break;			//思路：如果没有重复,a[i]的值递给a[k],如果a[i]与前面相比有重复，则用break，使a[i]的值不给a[k]; 
	  }		
	  if(j==k)   
	  a[k++]=a[i];
   }		
   for(i=0;i<k;i++)
     for(j=0;j<q;j++)
     if(a[i]==b[j]) t++;
   printf("%d\n",t);
}
