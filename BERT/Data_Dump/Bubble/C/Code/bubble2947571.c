  #include <stdio.h>
  int main(){
    int count=0,flag=1,i,j,n,A[100],tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
    while(flag){
      flag=0;
      for(j=n-1;j>=1;j--){
        if(A[j]<A[j-1]){
          tmp=A[j-1];
          A[j-1]=A[j];
          A[j]=tmp;
          count++;
          flag=1;
        }
      }
    }
      for(i=0;i<n-1;i++){
        printf("%d ",A[i]);
      }
      printf("%d\n",A[n-1]);
      printf("%d\n",count);
      return 0;
    }

