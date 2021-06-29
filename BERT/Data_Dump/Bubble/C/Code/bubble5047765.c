#include <stdio.h>

#define MAX 100

int main()
{
  int flag=1,i=0,k,n,j,invert,count=0;

  int A[MAX];

  scanf("%d",&n);

  for(k=0;k < n;k++){
    scanf("%d",&A[k]);
  }

  while(flag){

  flag = 0;

  for(j=n-1;j >= 1;j--){

    if(A[j] < A[j - 1]){

      invert = A[j];

      A[j] = A[j - 1];

      A[j - 1] = invert;

      flag = 1;

    count = count + 1;
  }
  }
}

for(i = 0;i < n;i++){

  if(i>0) printf(" ");

printf("%d",A[i]);

}
printf("\n");

printf("%d\n",count);

return 0;

  }

