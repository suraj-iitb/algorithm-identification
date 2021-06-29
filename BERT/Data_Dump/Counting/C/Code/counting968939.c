#include<stdio.h>
#define MAX 10000000
 
int A[MAX],B[MAX],C[MAX];
int main(){
    int n,i;
 
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&A[i]);
}
for(i = 1;i <= MAX;i++){
    C[i]=0;
}
for(i=1;i<=n;i++){
    C[A[i]]++;
}
for(i=1;i<=MAX;i++){
    C[i] = C[i] + C[i - 1];
}
for(i = n; i >= 1;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
}

for(i=1;i<=n;i++){
  if(i==n){
  printf("%d\n",B[i]);
      }else{   
 printf("%d ",B[i]);
 }
}
return 0;
}
