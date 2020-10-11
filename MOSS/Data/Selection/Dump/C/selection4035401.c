#include<stdio.h>
#define N 100

int main(){
  
  int i , j, k, array[N], min, min_place, num, flag, cnt = 0;
  
  scanf("%d",&num);
  
  for(i = 0; i < num; i++)scanf("%d",&array[i]);
  
  for(i = 0; i < num; i++)
    {
      flag = 0;
      
      for(j = i; j < num; j++)
	{
	  if(j == i)min = array[j];
	  if(array[j] < min)
	    {
	      min = array[j];
	      min_place = j;
	      flag = 1;
	    } 
	}
      if(flag == 1)
	{
	  array[min_place] = array[i];
	  array[i] = min;
	  cnt++;
	}
      /*for(k = 0; k < num; k++)
	{
	printf("%d",array[k]);
	printf(" ");
	if(k == num - 1)printf("\n");
	}
      */ 
    } 
  for(i = 0; i < num; i++)
    {
      printf("%d",array[i]);
      if(i == num - 1){
	printf("\n");
	break;
      }
      printf(" ");
    }

  printf("%d\n",cnt);
  
  return 0;
}

