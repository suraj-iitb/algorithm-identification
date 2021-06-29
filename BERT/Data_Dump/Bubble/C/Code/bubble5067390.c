#include<stdio.h>
int main(){

int i,j,N,cnt=0;
scanf("%d",&N);
int A[N];

for(i=0;i<N;i++){
    scanf("%d",&A[i]);
}

for(i=1;i<N;i++)
for(j=0;j<N-1;j++){
    if(A[j]>A[j+1]){
        int temp =A[j];
        A[j]=A[j+1];
        A[j+1]=temp;
        cnt++;
    }
}

for(i=0;i<N;i++)
    if(i==N-1)
printf("%d\n",A[i]);
else
    printf("%d ",A[i]);

printf("%d\n",cnt);
}
