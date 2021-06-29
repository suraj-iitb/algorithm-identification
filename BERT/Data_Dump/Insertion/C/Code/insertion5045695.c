#include <stdio.h>

int main(){
 int i,j,v,N;
  int A[100];

scanf("%d",&N);
for(i=0;i<=N-1;i++){
scanf("%d",&A[i]);
}

for(i=0;i<=N-1;i++){
if(i==N-1)printf("%d",A[i]);
else printf("%d ",A[i]);
}
printf("\n");
for(i=1;i<=N-1;i++){
  v = A[i];
  j = i - 1;
  while ((j >= 0) && (A[j] > v)){
    A[j+1] = A[j];
    j--;
  A[j+1] = v;
}
for(j=0;j<=N-1;j++){
if(j==N-1)printf("%d",A[j]);
else printf("%d ",A[j]);
}
printf("\n");
}
  return 0;
}

