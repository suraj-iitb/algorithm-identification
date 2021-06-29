//linear search

#include<stdio.h>
#define N 10000
#define M 500

//int sear(int);

int n1 = 0;
int n2 = 0;

int main()
{
  int i,j;
  int arr1[N];
  int arr2[M];
  int count = 0;
  int res = 0;

  //input data(be searched)
  scanf("%d",&n1);
  for(i = 0;i < n1; i++)
    {
      scanf(" %d",&arr1[i]);
    }

  //input data(search data)
  scanf("%d",&n2);
  for(j = 0;j < n2; j++)
    {
      scanf(" %d",&arr2[j]);
    }

  //search time
  for(j = 0; j < n2;)
    {
      for(i = 0; i < n1;)
	{
        
	  if(arr1[i] == arr2[j])
	    {
	      count++;
	      j++;
	      break;
	    }

	  else if(arr1[i] != arr2[j])
	    {
	      i++;
	    }
	  if(i == n1) j++;
 
	}
    }
  printf("%d\n",count);

  return 0;
}

