#include <stdio.h>

int main(){
int n,j,tmp,flag=1;
int count=0;

scanf("%d",&n);
int A[n];

for(j=0; j<n; j++){
  scanf("%d",&A[j]);
}

while(flag){
  flag=0;
for(j=n-1; j>=1; j--){
  if(A[j]<A[j-1]){
    tmp=A[j];
    A[j]=A[j-1];
    A[j-1]=tmp;
    flag=1;
    count++;
  }
}

}

for(j=0; j<n; j++){
if(j!=n-1) printf("%d ",A[j]);
else {
  printf("%d",A[j]);
}
}
printf("\n");
printf("%d\n",count);

return 0;
}

