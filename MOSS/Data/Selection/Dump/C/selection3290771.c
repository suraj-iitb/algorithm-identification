#include<stdio.h>
int main()
{
  int i,j,tmp,N,minj,flag,cnt=0;
 int A[100];
 scanf("%d",&N);

 for(i=0;i<N;i++){
   scanf(" %d",&A[i]);
}

 for(i=0;i<N;i++)
{
  minj = i;
  flag = 0;
  for(j=i;j<N;j++){
    if(A[j] < A[minj]){
      minj = j;
      flag = 1;
}
}
  if(flag == 1){
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    cnt++;
}
 }

 for(i=0;i<N;i++){
   if(i == N-1)
     {printf("%d\n",A[i]);
     break;
}

   printf("%d ",A[i]);
}
 printf("%d\n",cnt);
  return 0;
}

