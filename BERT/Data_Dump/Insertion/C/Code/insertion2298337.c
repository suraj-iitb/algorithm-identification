main(){
  int i,j,key,n,c;
  int A[101];
 
  scanf("%d",&n); /* The n is the number of elements in the sequence. */
   
  if(n<1||n>100){
    return 0;
  }               /* Constraints: 1 <= n <= 100 */
   
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }               /* Scanning n elements of the sequence */
   
  for(i=1;i<=n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  /* Printing scaned n elements of the sequence */
 
  for(j=2;j<=n;j++){
    key = A[j];
    i = j - 1;
    while(i>0&&A[i]>key){
      A[i+1]=A[i];
      i = i - 1;
    }
    A[i+1]=key;   /* Insertion Sort */
 
    for(c=1;c<=n-1;c++){
      printf("%d ",A[c]);
    }
    printf("%d\n",A[c]);
  }               /* Printing sorted the sequence */
 
  return 0;
}
