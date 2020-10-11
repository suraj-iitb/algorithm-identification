#include<stdio.h>
int main(){
  int N,i,v,j,A[1000],k,h;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  for(h=0;h<N;h++){
    printf("%d",A[h]);
	if(h>=0 && h<N-1)
	  printf(" ");
  }
  printf("\n");

  for(i=1;i<N;i++){
    

    v=A[i];
    j=i-1;
    while(j >=0 && A[j] > v){
      A[j+1] = A[j];
      j--;

    }   A[j+1] = v;
    for(k=0;k<N;k++){
      printf("%d",A[k]);
	if(k>=0 && k<N-1)
	  printf(" ");
    }
    printf("\n");

  }
  //  printf("%d",A[i]);
  return 0;
}
