#include<stdio.h>
#include<stdlib.h>

int selection(int *,int);

int main()
{
  int *num;
  int kazu,i,count;

  scanf("%d",&kazu);

  num = (int *)malloc(kazu * sizeof(int));

  for(i=0;i<kazu;i++) scanf("%d",&num[i]);

  count = selection(&num[0],kazu);

  for(i=0;i<kazu;i++)
    {
      printf("%d",num[i]);
      if(i != kazu-1) printf(" ");
    }
  printf("\n");

  printf("%d\n",count);

  free(num);
  return 0;
}

int selection(int *num,int kazu)
{
  int i,j,minj,temp,count=0;

  for(i=0;i<kazu-1;i++)
    {
      minj = i;
      for(j=i;j<=kazu-1;j++)
	{
	  if(num[j]<num[minj]) minj =j;
	}

      if(i != minj)
	{
      temp = num[i];
      num[i] = num[minj];
      num[minj] = temp;
      count++;
	}
    }
  return count;
}

