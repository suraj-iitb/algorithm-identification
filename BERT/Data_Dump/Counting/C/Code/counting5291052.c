#include<stdio.h>
#define p 2000001

int A[p];
int B[p];
int C[p];


void countsort();

int main()
{ 
  int i, n;
  scanf("%d",&n);
//input the array
  for(i = 0; i <= n-1; i++) 
  {scanf("%d",&A[i]);}
  countsort(A, n);

  return 0;
}
void countsort(int A[], int n)
{  
  //the pseudo code given in the description of the problem 
  int i;
  for(i = 0; i <= p-1; i++)
  {C[i] = 0;}


  for(i = 0; i <= n-1; i++) 
  {C[A[i]]++;}
   

  for(i = 1; i <= p-1; i++) 
  {C[i] += C[i-1];}

  for(i = n-1; i >= 0; i--)
    {
      B[C[A[i]]] = A[i];
      C[A[i]]--;
    }  
    //print the sorted array
    for(i = 1; i <= n; i++)
    {
      printf("%d",B[i]);
      if(i == n)printf("\n");
      else printf(" ");
    }
}

