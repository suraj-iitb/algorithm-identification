#include<stdio.h>
#define N 100

int bubble(int, int);

int main(){
  
  int array[N], i, j, temp, num, cnt = 0, k;
  
  scanf("%d",&num);

  for(i = 0 ; i < num; i++)scanf("%d",&array[i]);

  for(i = 0; i < num; i++)
    {
      for(j = 0; j < num - i - 1; j++)
	{
	  if(bubble(array[j],array[j + 1]) == 1)
	    {
	      temp = array[j + 1];
	      array[j + 1] = array[j];
	      array[j] = temp;
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

int bubble(int a, int b)
{
  if(a > b)return 1;
  else return 0;
}

