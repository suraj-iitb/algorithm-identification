    #include<stdio.h>
    #include<stdlib.h>
    #define MIN 1
    #define MAX 100
    int main(){
      int N,A[MAX],i,j,tmp,count=0,minj;
      scanf("%d",&N);
      if(N<MIN||N>MAX) exit(1);
      for(i=0;i<N;i++){
        scanf("%d",&A[i]);
      }
      for(i=0;i<N;i++){
        minj = i;
        for(j=i; j<N; j++)
          if(A[j] < A[minj]){
            minj = j;
          }
        if(minj!=i){
          tmp = A[i];
          A[i] = A[minj];
          A[minj] =tmp;
          count++;
          }
          if(i==N-1){
            printf("%d\n",A[i]);
            break;
          }
          printf("%d ",A[i]);
      }
      printf("%d\n",count);
      return 0;
    }

