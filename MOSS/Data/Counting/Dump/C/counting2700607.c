#include<stdio.h>
#define MAX 2000000
#define NMAX 10001



int main(){
int n,i,j,x,last;
int A[MAX];
int B[MAX];
int C[NMAX]={0};
int m=-1;

scanf("%d",&n);
for(i=0;i<n;i++){scanf("%d",&A[i]);if(A[i]>m){m=A[i];}}


for(i=0;i<n;i++)C[A[i]]++;
last=0;

for(i=0;i<=m;i++){
 if(C[i]>0){
   x=C[i];
   for(j=0;j<x;j++){B[last]=i;last++;}
 }
}





for(i=0;i<n-1;i++)printf("%d ",B[i]);
printf("%d\n",B[n-1]);

return 0;
}
