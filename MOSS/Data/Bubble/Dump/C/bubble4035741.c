#include <stdio.h>

int main(){
    
  int i,j,flag,A[100],x,y,N,cnt=0;
    
  scanf("%d",&N);
  for(i = 0;i < N;i++) scanf("%d",&A[i]);
  
    flag = 1; // 逆の隣接要素が存在する
    while (flag){
      flag = 0;
      for(j = N-1;j >= 1;j--){
        if(A[j] < A[j-1]){
	  x = A[j];
	  y = A[j-1];
	  A[j] = y;
	  A[j-1] = x;
	  cnt++;
	  flag = 1;
	}
      }
    }
    for(i = 0;i < N;i++){
      printf("%d",A[i]);
      if(i < N-1) printf(" ");
      else printf("\n");
    }
    printf("%d\n",cnt);

    return 0;
}

