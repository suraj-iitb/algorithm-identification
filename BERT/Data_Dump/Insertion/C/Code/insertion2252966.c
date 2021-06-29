#include<stdio.h>

main(){
int N,i,j;
int A[100];

scanf("%d",&N);
for(i=0;i<N;i++)scanf("%d",&A[i]);

trace(A,N);
sort(A,N);

return 0;

}

void trace(int A[],int N){
int i;

for(i=0;i<N;i++){
if(i>0)printf(" ");
printf("%d",A[i]);
}
printf("\n");
}

void sort(int A[],int N){
int i,j,k;

for(i=1;i<N;i++){
k=A[i];
j=i-1;
while(j>=0&&A[j]>k){
A[j+1]=A[j];
j--;
}
A[j+1]=k;
trace(A,N);
}
}
