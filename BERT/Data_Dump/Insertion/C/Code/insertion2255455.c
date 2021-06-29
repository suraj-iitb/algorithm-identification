#include<stdio.h>

int main(){
  int i,j,k,m,Kazu[100],sum,key;

  scanf("%d",&j);

  for(i=0;i<j;i++)
    {
      scanf("%d",&Kazu[i]);
    }
  for(i=1;i<j;i++)
    {
      key = Kazu[i];
       
      for(k=0;k<j;k++)
	{
	  printf("%d",Kazu[k]);
	  if(k<j-1)printf(" ");
	}
      m=i;
       
      while(m > 0 && Kazu[m-1] > key)
	{
	  Kazu[m]=Kazu[m-1];
	  m--;
	  Kazu[m]=key;
	}
       
         printf("\n");
    }
   for(k=0;k<j;k++)
	{
	  printf("%d",Kazu[k]);
	  	  if(k<j-1)printf(" ");
	}
   printf("\n");
  return 0;
  
}
