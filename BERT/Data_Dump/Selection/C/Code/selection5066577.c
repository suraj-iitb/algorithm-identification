# include<stdio.h>

int main(){
  int i,j,N,A[100],minj,key,cnt=0;

  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if (A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj) cnt++;
    key=A[i];
    A[i]=A[minj];
    A[minj]=key;
   
  }

   for(i=0;i<N;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  
  printf("\n%d\n",cnt);
  
  return 0;
}

