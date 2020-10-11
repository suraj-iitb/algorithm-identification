#include<stdio.h>
#include<stdlib.h>

int bubble(int *,int);



int main()
{
  int *num;
  int kazu,i,count;

  scanf("%d",&kazu);
 
  num = (int *)malloc(kazu * sizeof(int));

  for(i=0;i<kazu;i++) scanf("%d",&num[i]);

  count = bubble(&num[0],kazu);

  for(i=0;i<kazu;i++)
    {
      printf("%d",num[i]);

      if(i != kazu - 1) printf(" ");
    }

  printf("\n");

  printf("%d\n",count);


  free(num);
  return 0;
}

int bubble(int *num,int kazu)
{
  int i,j,count=0,temp;

  for(i=0;i<kazu-1;i++)
    {
      for(j=kazu-1;j>=i+1;j--)
	{
	  if(num[j]<num[j-1])
	    {
	      temp = num[j];
	      num[j] = num[j-1];
	      num[j-1]= temp;
	      count++;
	    }
	}
    }
  return count;
}

