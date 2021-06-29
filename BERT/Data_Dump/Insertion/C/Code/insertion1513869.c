#include <stdio.h>

void trace(int N,int A[]){
  int i;
  for(i=0;i<=N-1;i++){
    if(i>0){
    printf(" ");
    }
    printf("%d",A[i]);
    }
  printf("\n");
}

int main(void){

int n,i,j,k;
int v;
int A[100];
scanf("%d\n",&n);
for(i=0;i<=n-1;i++){
  scanf("%d",&A[i]);
}

trace(n,A);//???????????¨???

for(j=1;j<=n-1;j++){
  v=A[j];
  k=j-1;
  while(k>=0 && v<A[k]){
    A[k+1]=A[k];
    k--;
  }
  A[k+1]=v;
  trace(n,A);
  }

return 0;    
}
