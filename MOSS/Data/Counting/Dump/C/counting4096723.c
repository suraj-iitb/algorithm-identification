//Counting sort

#include<stdio.h>
#define MAX 2000001
#define VMAX 10000

int Barr[MAX],Carr[VMAX + 1];

//work time
void counting(int arr[],int Barr[],int n,int k)
{
  int i,j;

  for(i = 0; i <= k; i++)
    {
      Carr[i] = 0;
    }

  for(j = 1; j <= n; j++)
    {
      Carr[arr[j]]++;
    }

  for(i = 1; i <= k; i++)
    {
      Carr[i] = Carr[i] + Carr[i - 1];
    }

  for(j = n; j >= 1; j--)
    {
      Barr[Carr[arr[j]]] = arr[j];
      Carr[arr[j]]--;
    }

  printf("%d",Barr[1]);
  for(i = 2; i <= n; i++)
    {
      printf(" %d",Barr[i]);
    }
  printf("\n");
  
}



int main()
{
  int arr[MAX];
  int i;
  int n = 0;
  int k = 0;


 
  //input data
  scanf("%d",&n);
  for(i = 1; i <= n; i++)
    {
      scanf("%d",&arr[i]);
      if(k < arr[i]) k = arr[i];
    }

  counting(arr,Barr,n,k);

  return 0;
}


