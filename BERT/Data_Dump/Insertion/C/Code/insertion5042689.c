#include<stdio.h>
int main(){
  int j,N,i,s,key;
  int B[1000];
   scanf("%d",&N);
  for(s=0;s<N;s++){
    scanf("%d",&B[s]);
  }
   for(s=0;s<N;s++){
	if(s<N-1)printf("%d ",B[s]);
	if(s==N-1)printf("%d",B[s]);
      }
   
   printf("\n");
  for(j=1;j<N;j++){
    key=B[j];
    i=j-1;
    while(i>=0&&B[i]>key){
      B[i+1]=B[i];
      i=i-1;
    }
      B[i+1]=key;
      for(s=0;s<N;s++){
	if(s<N-1)printf("%d ",B[s]);
	if(s==N-1)printf("%d",B[s]);
      }
      printf("\n");
  }
  return 0;
}
    


