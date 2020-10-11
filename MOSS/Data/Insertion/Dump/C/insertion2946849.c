int main()
{
  int i,N,j,k;
  
  scanf("%d",&N); //要素の個数
  int A[N];
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  

  for(k=0;k<N;k++){
    if(k>0) printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");
  int v;
  for(i=1;i<=N-1;i++){
    v = A[i];
    j = i-1;

    while(j>= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
     
    }

    A[j+1] = v;
    for(k=0;k<N;k++){
      if(k>0) printf(" ");
      printf("%d",A[k]);
    }
    printf("\n");
  }


  return 0;

}

