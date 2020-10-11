#include <stdio.h>
#define num 100

int main(){
int i,j,N,A[num],flag,count=0,key;

scanf("%d",&N);

for(i=0;i<N;i++){
scanf("%d",&A[i]);
}

flag=1;
i=0;

while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
        if(A[j]<A[j-1]){
        key=A[j];
        A[j]=A[j-1];
        A[j-1]=key;
        count++;
        flag=1;
        }
        i++;
    }
}

for(j=0;j<N-1;j++){
printf("%d ",A[j]);
}

printf("%d\n%d\n",A[N-1],count);

return 0;
}
