#include<stdio.h>
#include<stdlib.h>

#define N 101

int main()
{
  int i,j,a[N],count=0,l,min,k;

  scanf("%d",&l);
  
  if(l < 1 || l > 100)exit(2);
  
  for(i = 0;i < l;i++)
    {
      scanf("%d",&a[i]);
    }
 
  for(i = 0;i < l;i++){
      min = i;
      for(j = i ;j< l;j++)
	{
	  if(a[j] < a[min]){
	    min = j;
	  }
	}
      if(a[i] != a[min]){
      k = a[i];
      a[i] = a[min]; 
      a[min] = k;
      count++;
      }
    } 
	
  for(i = 0;i < l;i++){
    printf("%d",a[i]);
  if(i != l-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
