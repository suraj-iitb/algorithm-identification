static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int n, i, j, v;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  for(i=1;i<n;i++){
    trace(A, n);
    v=A[i];
    j=i-1;       
    while(j>=0 && A[j] > v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
  }
  trace(A, n);
  return 0;
}
