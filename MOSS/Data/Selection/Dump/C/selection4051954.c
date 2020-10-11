#include <stdio.h>
#define N 100

int main()
{
  int a[N],b,e=0,i,d,c,j;

  scanf("%d",&b);
  for(i=0;i<b;i++)
    scanf("%d",&a[i]);

 for(i=0;i<b-1;i++){
    c=i;
    for(j=i+1;j<b;j++){
      if(a[j]<a[c])
	c=j;
      }
      d=a[i];
      a[i]=a[c];
      a[c]=d;
    if(i != c)e++;
  }

	  
  for(i=0;i<b;i++){
    if(i>0)printf(" ");
                printf("%d",a[i]);
            }
            printf("\n");
            printf("%d\n",e);
            
            return 0;
        }

