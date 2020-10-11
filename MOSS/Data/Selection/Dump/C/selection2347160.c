#include <stdio.h>

int main()
{
 int n,a[1000],i,j,mini,dem=0;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 for (i = 0;i<n;i++)
 {    mini = i;
      for (j = i;j<n;j++)
      {
        if (a[j] < a[mini])
           {
             mini = j;
           }
      }
	  if(i !=mini)
		 {
			 int temp=a[i];
             a[i]=a[mini];
             a[mini]=temp;      
			 dem++;
		}             
 }
 printf("%d",a[0]);
 for(i=1;i<n;i++)
 {
  printf(" %d",a[i]);
 }
 printf("\n%d\n",dem);
 return 0;
}
