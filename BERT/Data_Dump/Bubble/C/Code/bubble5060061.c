#include<stdio.h>

int main(){
   int j,cnt=0,N,n,flag=1;
   scanf("%d",&N);
   int A[N];
   for(j=0;j<N;j++){
       scanf("%d",&A[j]);
   }
while(flag==1){
    flag = 0;
for(j=N-1;j>0;j--){
if(A[j]<A[j-1]){
    n=A[j];
    A[j]=A[j-1];
    A[j-1]=n;
    flag = 1;
    cnt++;
}
}
}
for(j=0;j<N-1;j++){
printf("%d ",A[j]);
}
printf("%d\n",A[N-1]);
printf("%d\n",cnt);
return 0;
}

