int main(void){
  int N, tmp, count = 0;
  scanf("%d", &N);
  int A[N];
  for(int i=0; i<N; i++) scanf("%d", &A[i]);

  for(int i=0; i<N; i++){
    int minj = i;
    for(int j=i; j<N; j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(minj != i) count += 1; 
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
  }
  
  for(int k=0; k<N; k++){
    printf("%d",A[k]);
    if(k<N-1) printf(" ");
  }

  printf("\n%d\n", count);
  
  return 0;
}
