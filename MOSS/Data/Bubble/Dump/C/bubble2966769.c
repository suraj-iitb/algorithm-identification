#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,n,x,k=0,flag;
  int *A;

  scanf("%d",&n);
  if(n<1 || n>100)return 0;

  A = (int *)malloc(sizeof(int) * n);

for(i = 0;i < n;i++){
  scanf("%d",&A[i]);
    if(A[i]<0|| A[i]>100)return 0;
}

flag = 1;
 i = 0; // 未ソート部分列の先頭インデックス
 while (flag){
   flag = 0;

   for( j = n-1 ;j > 0; j--){

     if (A[j] < A[j-1]){
       x = A[j];
       A[j] = A[j-1];
       A[j-1] = x;
        flag = 1;
       k++;
    }
     }
  i++;
 }

  printf("%d",A[0]);
for(i=1;i<n;i++){
  printf(" %d",A[i]);
}
printf("\n");
printf("%d\n",k);

return 0;
}

