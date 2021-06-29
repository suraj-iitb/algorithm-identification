#include <stdio.h>
#define N 100

int main(){
  int A[N];
  int v,i,j,num,cnt;

  scanf("%d",&num);
  
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
  
  for(cnt=0;cnt<num;cnt++){
      printf("%d",A[cnt]);
      if(cnt != num-1) printf(" ");
      if(cnt == num-1) printf("\n");
  }
    
    
  for(i=1;i<num;i++){
        v = A[i];
    j = i-1;
    while (j>=0 && A[j] > v)
      {
	A[j+1] = A[j];
	j--;
      }
    A[j+1] = v;
    for(cnt=0;cnt<num;cnt++){
      printf("%d",A[cnt]);
      if(cnt != num - 1) printf(" ");
      if(cnt == num - 1) printf("\n");
    }
    

    
  }
 
  return 0;
}





























  

