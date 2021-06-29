#include <stdio.h>

int main(){
int i,j,n,flag=1,tmp,count=0;
scanf("%d",&n);
int A[n];
for(i=0;i<n;i++) scanf("%d",&A[i]);

i=0;

while(flag==1){
flag=0;
for(j=n-1;j>=i+1;j--){
  if(A[j]<A[j-1]){
  tmp=A[j];
  A[j]=A[j-1];
  A[j-1]=tmp;
  count++;
  }
flag=1;
}
i++;
}
for(j=0;j<n;j++){
      printf("%d",A[j]);
      if(j<n-1)  printf(" ");
    }
    printf("\n%d\n",count);
  return 0;
}

