#include<stdio.h>
 
int main(){
  int aryN,i,j,k;
  int key;
  int A[1000];
  scanf("%d",&aryN);
  for(i = 1; i <= aryN; i++)
  {
      scanf("%d", &A[i]);
  }
 
  for(j = 1; j <= aryN; j++)
    {   
          key = A[j];       
          i = j-1;
          while(i>0 && A[i]>key)
        {
          A[i+1] = A[i];  
          i = i-1;
        }
          A[i+1] = key;
          
          for(k = 1; k <= aryN; k++)
          {
              if(k == aryN)
              {
                  printf("%d\n",A[k]);
              }
              else
              {
                  printf("%d ",A[k]);
              }
          }
    }
   
  return 0;
}
