#include <stdio.h>
 int main(){
 int minj,i,j,n,tmp;
 int count=0;

 scanf("%d",&n);
 int A[n];

 for(i=0; i<n; i++)
 scanf("%d",&A[i]);

 for(i=0; i<=n-1; i++){
  minj = i;
    for(j=i; j<=n-1; j++){
      if(A[j]<A[minj]){
        minj = j;
      }
    }

if(A[i]>A[minj]){
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    count++;
}

  }

for(i=0; i<n; i++){
if(i!=n-1)printf("%d ",A[i]);
else {
  printf("%d\n",A[i]);
}
}
printf("%d\n",count);

return 0;
 }

