int main(void){
  int n;
  int v,j=0,i=0,k=0;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    v=A[i];
    j=i-1;
    if(i>=1){
      for(k=0;k<n;k++){
	if(k==n-1){
	  printf("%d",A[k]);
	}else{
	  printf("%d ",A[k]);
	}
      }
      printf("\n");
    }
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j=j-1;
      A[j+1]=v;
    }
  }
  for(k=0;k<n;k++){
    if(k==n-1){
      printf("%d",A[k]);
    }else{
      printf("%d ",A[k]);
    }
  }
  printf("\n");
  return 0;
}
