#include<stdio.h>

static const int N = 100;

int main(){
  int n,i,j,flag=0;
  int A[N+1];
  int minj,swap,sort=0;

  scanf("%d",&n); /*Input an integer n, the number of elements in sequence*/

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);/* Input N elements of the sequence*/
  }
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj])
        minj = j;
     }  
    if(i!=minj){ swap=A[i];    
       A[i]=A[minj];
       A[minj]=swap;
       sort++;
      }
     }
    for(i=0;i<n;i++){
      if(i<n-1) printf("%d ",A[i]);/*Output the sorted sequence*/
      else printf("%d\n",A[i]);
    }
    printf("%d\n",sort);  /*Output the number of swap operations.*/

    return 0;
   } 
