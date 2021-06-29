#include <stdio.h>
 
int Search(int r);
 
int array1[10000],array2[500];

int n,m,count = 0;
 
int main(){

  int i;
  
  scanf("%d",&n);
  
  for(i = 0;i < n;i ++)
    {
      scanf("%d",&array1[i]);
    }
 
  scanf("%d",&m);
  
  for(i = 0;i < m;i ++)
    {
      scanf("%d",&array2[i]);
      count += Search(array2[i]);
    }
 
  printf("%d\n",count);
 
  return 0;
 
}
 
int Search(int r){

  int j;
  
  for(j = 0;j < n;j ++)
    {
      if(r == array1[j])
	{
	  return 1;
	}
    }
return 0;
}
