#include <stdio.h>

int main()
{
  int N,i,j,a,key;

  scanf("%d",&N);

  int data[N];
  
  for(i=0; i<N; i++){
    scanf("%d",&data[i]);
  }

   for(i=1; i<N+1; i++){
     key = data[i];
     j = i-1;

     for(a=0; a<N-1; a++){
       printf("%d ",data[a]);
     }
     printf("%d",data[N-1]);
     printf("\n");

     while(j>=0 && data[j] > key){
       data[j+1] = data[j];
       j--;
       data[j+1] = key;
     }
   }
   return 0;
}
    

