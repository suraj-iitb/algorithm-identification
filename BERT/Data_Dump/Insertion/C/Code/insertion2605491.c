#include<stdio.h>

int main(void){

int i,j=1,N,key,n;

int data[101];

scanf("%d",&N);

for(i=1;i<=N;i++){

scanf("%d",&data[i]);

}

for(j=1;j<=N;j++){

key = data[j];

i = j -1;

while(i>0 && data[i] > key){

data[i+1] = data[i];

i=i-1;

data[i+1] = key;

}

for(n=1;n<=N;n++){

printf("%d",data[n]);

if(n<N) printf(" ");

}

printf("\n");

}

return 0;

}
