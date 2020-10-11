int main(void){
  int N, tmp, flag = 1, count =0;
  scanf("%d", &N);
  int A[N];
  for(int i=0; i<N; i++){scanf("%d", &A[i]);}

  while(flag){
    flag=0;
    for(int j=N-1; j>0; j--){
      if(A[j] < A[j-1]){
        tmp = A[j-1];
        A[j-1] = A[j];
        A[j] = tmp;
        count++;
        flag =1;
      }
    }
  }
  
  for(int k=0; k<N; k++){
    printf("%d",A[k]);
    if(k<N-1) printf(" ");
  }

  printf("\n%d\n", count);
  
  return 0;
}
