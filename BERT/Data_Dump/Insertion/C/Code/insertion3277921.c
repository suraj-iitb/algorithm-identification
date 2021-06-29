#include <stdio.h>
int main(){
  int i,j,k,v,N;
 int A[100]; 
scanf("%d",&N);
if((1<=N)&&(N<=100)){
for(i=0;i<N;i++){
scanf("%d",&A[i]);
 printf("%d",A[i]);
 if(i<N-1){
   printf(" ");
 }
}
 printf("\n");
for(i=1;i<N;i++){
v = A[i];
j = i - 1;
while((j>=0)&&(A[j]>v)){
A[j+1]=A[j];
j--;
}
A[j+1]=v;
for(k=0;k<N;k++){  
printf("%d",A[k]);
 if(k<N-1){
   printf(" ");
 }
}
printf("\n");
}
}
else printf("error");
return 0;
}

