#include<stdio.h>
int main(){
  int N,i,temp,j,z;
  int A[100];
  scanf("%d",&N);
  for(i=1;i<=N;i++){
    scanf("%d",&A[i]);
  }
  for (i=1;i<=N;i++){
    temp = A[i];
    j = i-1;
    while (j >= 0 && A[j] > temp){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = temp; 
    for(z=1;z<=N;z++){
      printf("%d",A[z]);
      if(z == N)printf("\n");
      else printf(" ");
    }
  }
  return 0;
}
