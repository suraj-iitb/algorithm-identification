int main(){

  int n,i,j,k,key;

  //array length
  scanf("%d",&n);

  //array elements
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  //insertion sort
  for(i=1;i<n;i++){

    //display result
    for(k=0;k<n;k++){
      if(k==n-1){
        printf("%d\n",A[k]);
        break;
      }
      printf("%d ",A[k]);
    }

    key = A[i];
    j = i - 1;
    while(j>=0 && A[j]>key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }

  //display last result
  for(k=0;k<n;k++){
    if(k==n-1){
      printf("%d\n",A[k]);
      break;
    }
    printf("%d ",A[k]);
  }

  return 0;
}
