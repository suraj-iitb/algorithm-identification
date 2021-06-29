#include <stdio.h>
#define N 10000

int arrayA[2000001],arrayC[N+1],arrayB[2000001];
int main()
{

  int k,i,j,max=0;
  //int arrayA[2000001],arrayC[N+1],arrayB[2000001];

  scanf("%d",&k);
  for(i = 0 ; i < k ; i++) 
    {
      scanf("%d",&arrayA[i]);
      if(max<arrayA[i])max = arrayA[i];
    }

  


  for(i = 0 ; i <= max ; i++) arrayC[i] = 0;


  for(j = 0 ; j < k ; j++) arrayC[arrayA[j]]++;



  for(i = 1 ; i <= max ; i++)arrayC[i] = arrayC[i] + arrayC[i-1];

  

  for(j = k-1 ; j >= 0 ; j--)
    { 
      arrayB[arrayC[arrayA[j]]]= arrayA[j];
      arrayC[arrayA[j]]--;
      
    }






  for(i = 1 ; i < k ; i++)
    {
      printf("%d ",arrayB[i]);
    } 
  printf("%d",arrayB[k]);
  printf("\n");

  return 0;
}
