#include <stdio.h>
#define MAX 2000001
#define N 10000

int main(){

int C[N];
int A[MAX];
int B[MAX];
int i,j,num;


scanf("%d",&num);
for(i=1;i<=num;i++){
  scanf("%d",&A[i]);
}


for(i=0;i<N;i++){
  C[i] = 0;
  }

for(j=1;j<=num;j++){
  C[A[j]]++;
}

for(i=1;i<=N;i++){
  C[i] = C[i] + C[i-1];
}

for(j=num;j>0;j--){
  B[C[A[j]]] = A[j];
  C[A[j]]--;
}
for(i=1;i<num;i++){
printf("%d ",B[i]);
}
printf("%d\n",B[num]);

}
