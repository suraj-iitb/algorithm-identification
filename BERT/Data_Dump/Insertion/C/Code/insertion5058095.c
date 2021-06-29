#include <stdio.h>
int main(){
  int i,j,key,N;
  int A[100];

  
  scanf("%d",&N);
  for(i=0;i<N;i++){                                       // i --> Iterator
    int tmp;
    scanf("%d",&tmp);
    A[i]= tmp;
  }
  

  for(i=1;i<=N;i++){         // start from A[1],end when the array becomes A[N-1]
    key = A[i];
    for(j=0;j<N;++j){
      if(j==N-1)
	printf("%d",A[j]);            //最後の数
      else
	printf("%d ",A[j]);      //最後の数以外は後に空白
      
    }
    printf("\n");
   
    j = i - 1;
    while(j>=0 && A[j]>key){
      A[j+1] = A[j];
      j--; 
    }
    A[j+1] = key;
  }
  return 0;
}

