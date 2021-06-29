#include <stdio.h>

int main()
{
 int n,m,i,j,a[10000],key,dem=0;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 scanf("%d",&m);
 for(i=0;i<m;i++)
 {
  scanf("%d",&key);
   for(j=0;j<n;j++)
    {
     if(a[j]==key){
    dem++;
    break;
    }
   }
 }
 printf("%d\n",dem);
 return 0;
}
