#include<stdio.h>
#include<stdlib.h>
 
void swap(int*,int*); 

int main(){
  int N;
  int i,j,cnt=0;
  
  scanf("%d",&N);
  
  if(N<1&&N>100)exit(1);
  
  int inp[N];

  for(i=0;i<N;i++){
    scanf("%d",&inp[i]);
    if(inp[i]<1&&inp[i]>100)exit(2);
  }

  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(inp[j]<inp[j-1]){
	swap(&inp[j],&inp[j-1]);
	cnt++;}
    }
  }

  for(i=0;i<N;i++){
    printf("%d",inp[i]);
    if(i<N-1)printf(" ");
  }

  printf("\n");

  printf("%d\n",cnt);
  
  return 0;
}

void swap(int *a,int *b){

  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
  

